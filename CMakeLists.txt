cmake_minimum_required(VERSION 3.8)
project(mypack)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(number_publisher src/number_publisher.cpp)
ament_target_dependencies(number_publisher rclcpp std_msgs)

add_executable(minmax_subscriber src/minmax_subscriber.cpp)
ament_target_dependencies(minmax_subscriber rclcpp std_msgs)

install(TARGETS
  number_publisher
  minmax_subscriber
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
