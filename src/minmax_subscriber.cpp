#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <limits>

class MinMaxSubscriber : public rclcpp::Node
{
public:
    MinMaxSubscriber() : Node("minmax_subscriber"),
                         min_value_(std::numeric_limits<int>::max()),
                         max_value_(std::numeric_limits<int>::min())
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "random_number", 10,
            std::bind(&MinMaxSubscriber::callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "MinMax Subscriber node started");
    }

private:
    void callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        int value = msg->data;
        if (value < min_value_)
            min_value_ = value;
        if (value > max_value_)
            max_value_ = value;

        RCLCPP_INFO(this->get_logger(), "Received: %d | Min: %d | Max: %d",
                    value, min_value_, max_value_);
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    int min_value_;
    int max_value_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinMaxSubscriber>());
    rclcpp::shutdown();
    return 0;
}
