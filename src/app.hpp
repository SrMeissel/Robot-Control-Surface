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
  void printSomething(char *text) { RCLCPP_INFO(get_logger(), text); }

private:
  int createWindow(); // this is a blocking function.

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub;

  GtkApplication *app;
};
