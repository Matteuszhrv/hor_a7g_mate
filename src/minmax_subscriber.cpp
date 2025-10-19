#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include <algorithm>
#include <vector>

class MinMaxSubscriber : public rclcpp::Node
{
public:
    MinMaxSubscriber() : Node("minmax_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32MultiArray>(
            "random_numbers", 10,
            std::bind(&MinMaxSubscriber::callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "MinMax Subscriber node started");
    }

private:
    void callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg)
    {
        if (msg->data.empty())
        {
            RCLCPP_WARN(this->get_logger(), "Empty array received!");
            return;
        }

        int min_val = *std::min_element(msg->data.begin(), msg->data.end());
        int max_val = *std::max_element(msg->data.begin(), msg->data.end());

        RCLCPP_INFO(this->get_logger(),
                    "Received array: [%d, %d, %d, %d, %d] | Min: %d | Max: %d",
                    msg->data[0], msg->data[1], msg->data[2], msg->data[3], msg->data[4],
                    min_val, max_val);
    }

    rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinMaxSubscriber>());
    rclcpp::shutdown();
    return 0;
}
