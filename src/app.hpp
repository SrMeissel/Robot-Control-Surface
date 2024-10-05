#include <cstdio>

#include <gtk/gtk.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Surface : public rclcpp::Node {
public:
  Surface();
  ~Surface();

  // Used to ensure C function pointers are working properly :)
  void printSomething() { RCLCPP_INFO(get_logger(), "Hello, world!"); }

private:
  int createWindow(); // this is a blocking function.

  GtkApplication *app;
};
