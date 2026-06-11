import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rotate_pkg.action import Rotate

class RotateActionClient(Node):
    def __init__(self):
        super().__init__('rotate_action_client')
        self._action_client = ActionClient(self, Rotate, 'rotate')

    def send_goal(self, target_angle):
        self.get_logger().info('Waiting for action server to start...')
        self._action_client.wait_for_server()

        goal_msg = Rotate.Goal()
        
        goal_msg.angle = float(target_angle)

        self.get_logger().info(f'Sending goal: Rotate {target_angle} radians')
        
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal aborted')
            return

        self.get_logger().info('Goal accepted, waiting for result...')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Feedback -> Remaining angle: {feedback.reamining_angle:.4f} radians')

    def get_result_callback(self, future):
        result = future.result().result
        
        if result.success:
            self.get_logger().info('Goal reached successfully')
        else:
            self.get_logger().info('Goal aborted')
            
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    action_client = RotateActionClient()
    
    
    action_client.send_goal(3.14)
    
    rclpy.spin(action_client)

if __name__ == '__main__':
    main()