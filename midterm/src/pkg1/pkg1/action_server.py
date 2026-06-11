import math
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rotate_pkg.action import Rotate 

def euler_from_quaternion(q):
    """Convert a quaternion into euler angles (roll, pitch, yaw)"""
    siny_cosp = 2 * (q.w * q.z + q.x * q.y)
    cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
    yaw = math.atan2(siny_cosp, cosy_cosp)
    return yaw

class RotateActionServer(Node):
    def __init__(self):
        super().__init__('rotate_action_server')
        
        self.callback_group = ReentrantCallbackGroup()
        
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.odom_sub = self.create_subscription(
            Odometry, 
            '/odom', 
            self.odom_callback, 
            10, 
            callback_group=self.callback_group)
            
        self._action_server = ActionServer(
            self,
            Rotate,
            'rotate',
            self.execute_callback,
            callback_group=self.callback_group)
            
        self.current_yaw = 0.0
        self.kp = 1.0
        self.tolerance = math.radians(10.0)

    def odom_callback(self, msg):
        self.current_yaw = euler_from_quaternion(msg.pose.pose.orientation)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        
        
        target_angle_relative = goal_handle.request.angle
        target_yaw_absolute = self.current_yaw + target_angle_relative
        
        
        target_yaw_absolute = math.atan2(math.sin(target_yaw_absolute), math.cos(target_yaw_absolute))

        feedback_msg = Rotate.Feedback()
        twist_msg = Twist()
        
        rate = self.create_rate(10.0)

        while rclpy.ok():    
            error = math.atan2(math.sin(target_yaw_absolute - self.current_yaw), 
                               math.cos(target_yaw_absolute - self.current_yaw))
            
            if abs(error) <= self.tolerance:
                break

            
            angular_velocity = self.kp * error
            twist_msg.angular.z = max(min(angular_velocity, 1.5), -1.5) 
            self.cmd_vel_pub.publish(twist_msg)

            
            feedback_msg.reamining_angle = error
            goal_handle.publish_feedback(feedback_msg)

            rate.sleep()

        
        twist_msg.angular.z = 0.0
        self.cmd_vel_pub.publish(twist_msg)

        
        goal_handle.succeed()
        result = Rotate.Result()
        result.success = True
        self.get_logger().info("Goal reached successfully")
        
        return result

def main(args=None):
    rclpy.init(args=args)
    rotate_server = RotateActionServer()
    executor = MultiThreadedExecutor()
    rclpy.spin(rotate_server, executor=executor)
    rclpy.shutdown()

if __name__ == '__main__':
    main()