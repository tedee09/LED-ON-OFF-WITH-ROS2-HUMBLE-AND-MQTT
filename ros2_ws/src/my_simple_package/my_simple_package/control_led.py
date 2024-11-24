import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt

class LEDController(Node):
    def __init__(self):
        super().__init__('led_controller')
        self.subscription = self.create_subscription(
            String,
            'led_control',
            self.listener_callback,
            10)
        
        # MQTT Client setup
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.connect("IP_ALAMAT_MQTT_BROKER", 1883, 60)  # Ganti dengan IP Broker Anda

    def listener_callback(self, msg):
        self.get_logger().info(f'Received command: {msg.data}')
        if msg.data in ["ON", "OFF"]:
            self.mqtt_client.publish("esp8266/led", msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = LEDController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
