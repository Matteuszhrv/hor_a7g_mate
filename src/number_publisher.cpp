#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

class NumberPublisher : public rclcpp::Node
{
public:
    NumberPublisher() : Node("number_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32MultiArray>("random_numbers", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(2),
            std::bind(&NumberPublisher::publish_numbers, this));
        std::srand(std::time(nullptr));
        RCLCPP_INFO(this->get_logger(), "Number Publisher node started");
    }

private:
    void publish_numbers()
    {
        std_msgs::msg::Int32MultiArray msg;
        msg.data.resize(5);
        for (int i = 0; i < 5; ++i)
        {
            msg.data[i] = std::rand() % 100;  // 0–99 közötti számok
        }

        RCLCPP_INFO(this->get_logger(), "Publishing numbers: [%d, %d, %d, %d, %d]",
                    msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4]);

        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NumberPublisher>());
    rclcpp::shutdown();
    return 0;
}
