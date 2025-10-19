from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='mypack', executable='number_publisher', output='screen'),
        Node(package='mypack', executable='minmax_subscriber', output='screen'),
    ])
