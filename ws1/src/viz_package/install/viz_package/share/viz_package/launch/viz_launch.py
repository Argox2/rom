from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='viz_package',
            namespace='paquito1',
            executable='viz_node',
            name='viz'

        )
    ])
