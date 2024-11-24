import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class TurtleController(Node):
    def __init__(self):
        super().__init__('turtle_controller')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.timer = self.create_timer(1.0, self.move_turtle)

    def move_turtle(self):
        msg = Twist()
        msg.linear.x = 2.0  # Kura-kura bergerak maju
        msg.angular.z = 1.0  # Kura-kura berputar
        self.publisher.publish(msg)
        self.get_logger().info(f'Sending command: linear={msg.linear.x}, angular={msg.angular.z}')

def main(args=None):
    rclpy.init(args=args)
    node = TurtleController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
