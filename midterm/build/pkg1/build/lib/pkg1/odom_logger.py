import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from tf_transformations import euler_from_quaternion

class MyNode(Node):
    def __init__(self):
        super().__init__("odom_logger")
        self.latest_msg = None
        self.subscriber_ = self.create_subscription(Odometry, "/odom", self.listener_callback, 10)
        self.timer = self.create_timer (1.0, self.print_odom)
    
    def listener_callback(self,msg):
        self.latest_msg = msg
        
    def print_odom(self):
        if self.latest_msg == None:
            return

        msg = self.latest_msg
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        z = msg.pose.pose.position.z

        qx = msg.pose.pose.orientation.x
        qy = msg.pose.pose.orientation.y
        qz = msg.pose.pose.orientation.z
        qw = msg.pose.pose.orientation.w

        roll, pitch, yaw = euler_from_quaternion([qx, qy, qz, qw])

        self.get_logger().info(f"\nPosition:\nx: {x}, y: {y}\n\nOrientation:\nYaw: {yaw}")


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()