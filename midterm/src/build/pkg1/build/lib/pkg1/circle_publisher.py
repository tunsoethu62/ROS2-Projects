import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class MyNode(Node):
    def __init__(self):
        super().__init__("circle_publisher")
        self.get_logger().info("Starting the Node...")
        self.publisher_ = self.create_publisher(Twist, "/cmd_vel", 10)
        self.timer = self.create_timer (1, self.timer_callback)

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 0.22
        msg.angular.z = 0.44
        self.publisher_.publish(msg)
        self.get_logger().info (f"Linear Velocity: {msg.linear.x}\nAngular velocity: {msg.angular.z}")

def main(args=None):
    rclpy.init(args=args)

    node = MyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()