#include "app.hpp"

Surface::Surface() : Node("controlSurface") {}

Surface::~Surface() {
  // g_object_unref(app);
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Surface>());
  rclcpp::shutdown();
  return 0;
};
