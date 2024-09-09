import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
# import serial
import random


# Mock serial class to simulate reading from a sonar sensor
class MockSerial:
    def __init__(self, port, baud_rate):
        self.port = port
        self.baud_rate = baud_rate
        self.is_open = True

    def readline(self):
        # Simulate reading a byte sequence that represents a distance
        # Simulate distances between 10.0 and 100.0
        distance = random.uniform(10.0, 100.0)
        # Format as a string with two decimal places
        distance_str = f"{distance:.2f}\n"
        return distance_str.encode('utf-8')  # Encode as bytes

    def close(self):
        self.is_open = False
        print('Serial connection closed.')


def distance_serial():

    serial_port = '/dev/ttyACM0'
    baud_rate = 9600  # In arduino, Serial.begin(baud_rate)

    # data = serial.Serial(serial_port, baud_rate) # Arduino serial (If discomment, also import serial).
    data = MockSerial(serial_port, baud_rate)  # MockSerial for testing.
    try:
        while True:
            # ser.readline returns a byte
            distance_byte = data.readline()

            distance_str = distance_byte.decode("utf-8", "ignore").strip()

            try:
                distance = (float(distance_str))/10
                return distance

            except ValueError:
                pass

    except KeyboardInterrupt:
        print('Program interrupt by user.')
    finally:
        data.close()
        print('Serial connection closed.')


class MarkerPublisher(Node):
    def __init__(self):
        super().__init__('marker_publisher')
        self.publisher_ = self.create_publisher(Marker, 'marker_topic', 10)
        self.marker_id = 0
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        marker = Marker()

        marker.header.frame_id = "/base_link"
        marker.header.stamp = self.get_clock().now().to_msg()

        # Set shape, Arrow: 0; Cube: 1; Sphere: 2; Cylinder: 3
        marker.type = 1
        marker.id = self.marker_id  # Set the current marker ID

        # Increment the marker ID for the next marker
        self.marker_id += 1

        # Set the scale of the marker
        marker.scale.x = 1.0
        marker.scale.y = 1.0
        marker.scale.z = 1.0

        # Set the color
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 1.0
        marker.color.a = 1.0

        marker.lifetime.sec = 3

        # Set the pose of the marker
        marker.pose.position.x = distance_serial()
        marker.pose.position.y = 0.0
        marker.pose.position.z = 0.0
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        self.publisher_.publish(marker)


def main(args=None):
    print('Hi from viz_package.')

    rclpy.init(args=args)
    marker_publisher = MarkerPublisher()
    rclpy.spin(marker_publisher)

    # Destroy the node explicitly
    marker_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
