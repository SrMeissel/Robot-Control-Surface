#include <cstdio>

#include <gtk/gtk.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Surface : public rclcpp::Node {
public:
  Surface();
  ~Surface();

private:
  GtkApplication *app;
};
