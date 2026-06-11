import rclpy
from rclpy.node import Node
from std_srvs.srv import Empty


class SquareServiceClient(Node):

    def __init__(self):
        super().__init__('square_service_client')

        self.client = self.create_client(Empty, 'move_square')

        # Wait until service is available
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

        self.get_logger().info('Service available, sending request')

        self.request = Empty.Request()
        self.future = self.client.call_async(self.request)

        self.future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info('Service call completed successfully')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

        # Shutdown after response
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    node = SquareServiceClient()
    rclpy.spin(node)


if __name__ == '__main__':
    main()