# hor_a7g_mate
ROS 2 C++ package.

A package két node-ból áll. A /number_publisher generál egy tömböt véletlenszámokkal, amiket 
std_msgs::msg::Int32MultiArray topicban hirdet. A /minmax_subscriber pedig kiírja a tömben lévő legnagyobb, illetve legkisebb elemet. Megvalósítás ROS 2 humble alatt.

# Packages and build
It is assumed that the workspace is ~/ros2_sw/.

# Clone the packages
```
cd ~/ros2_sw/src
```
```
git clone https://github.com/Matteuszhrv/hor_a7g_mate
```
# Build ROS 2 packages
```
cd ~/ros2_sw
```
```
colcon build --packages-select mypack --symlink-install
```
# Futtatás, de előtte ne felejtsd el source-ni a ROS parancsokat
```
source ~/ros2_sw/install/setup.bash
```
```
ros2 launch mypack minmax_launch.py
```
# Le ellenőrizhetjük külön is
```
ros2 run mypack number_publisher.cpp
```
```
ros2 run mypack minmax_subscriber.cpp
```
