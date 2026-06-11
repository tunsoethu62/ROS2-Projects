import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_srvs.srv import Empty
import time
import math


class SquareService(Node):

    def __init__(self):
        super().__init__('square_service_server')

        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.service = self.create_service(Empty, 'move_square', self.square_callback)

        self.get_logger().info("Square Service Ready")

    def square_callback(self, request, response):

        self.get_logger().info("Service called: Moving in square")

        twist = Twist()

        linear_speed = 0.2
        angular_speed = 0.5

        side_length = 0.5

        move_time = side_length / linear_speed
        rotate_time = (math.pi/2) / angular_speed

        for i in range(4):

            # Move forward
            twist.linear.x = linear_speed
            twist.angular.z = 0.0
            start_time = time.time()

            while time.time() - start_time < move_time:
                self.publisher.publish(twist)

            # Stop before turning
            twist.linear.x = 0.0
            self.publisher.publish(twist)
            time.sleep(0.5)

            # Rotate 90 degrees
            twist.angular.z = angular_speed
            start_time = time.time()

            while time.time() - start_time < rotate_time:
                self.publisher.publish(twist)

            # Stop after rotation
            twist.angular.z = 0.0
            self.publisher.publish(twist)
            time.sleep(0.5)

        self.get_logger().info("Finished square motion")

        return response


def main(args=None):
    rclpy.init(args=args)
    node = SquareService()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()