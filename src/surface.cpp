#include "app.hpp"
#include "PublisherExample.cpp"


int main(int argc, char ** argv)
{
	// App app;
	// app.run(argc, argv);

	rclcpp::init(argc, argv);
  	rclcpp::spin(std::make_shared<MinimalPublisher>());
	rclcpp::shutdown();

	printf("hello world robot-control-surface package\n");  

	return 0;
}