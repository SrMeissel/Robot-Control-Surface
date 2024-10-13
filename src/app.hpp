#include <cstdio>

#include <gtk/gtk.h>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Surface : public rclcpp::Node {
public:
  Surface();
  ~Surface();

  // Used to ensure C function pointers are working properly :)
  void printSomething(const geometry_msgs::msg::Twist &msg) const {
    RCLCPP_INFO(this->get_logger(), "recieved message over topic!");
  }

private:
  int createWindow(); // this is a blocking function.

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub;
  rclcpp::CallbackGroup::SharedPtr callBackGroup;
  rclcpp::TimerBase::SharedPtr timer;

  GtkApplication *app;
  GMainContext *context;
};
