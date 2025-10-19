# hor_a7g_mate

ROS 2 C++ package.

A package két node-ból áll. A /number_publisher egy tömben véletlen számokat generál amiket std_msgs::msg::Int32MultiArray topicban hirdet. A /minmax_subscriber pedig előállítja a tömben lévő értékek közül a legnagyobb, illetve legkisebb értéket. Megvalósítás ROS 2 Humble alatt.

# Packages and build

It is assumed that the workspace is ~/ros2_wkp/.

# Clone the packages
```
cd ~/ros2_wkp/src
```
```
git clone https://github.com/Matteuszhrv/hor_a7g_mate
```
# Build ROS 2 packages
```
cd ~/ros2_wkp
```
```
colcon build --packages-select hor_a7g_mate --symlink-install
```
Before ROS commands you need to source.
```
source ~/ros2_wkp/install/setup.bash
```
```
ros2 launch hor_a7g_mate minmax_launch.py
```
# Számítás ellenőrzése
```
ros2 topic echo /minmax
```
