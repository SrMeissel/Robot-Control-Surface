cmake_minimum_required(VERSION 3.8)
project(robot-control-surface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# I guess this is ok. I would much prefer a single find_package(gtk4 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(surface 
src/app.hpp
src/app.cpp
#
# src/PublisherExample.cpp
)

# GTK4 also requires using target_link_libraries 
# because it has other libraries like GObject associated with it
target_link_libraries(surface ${GTK4_LIBRARIES})
ament_target_dependencies(surface rclcpp std_msgs geometry_msgs GTK4) 

target_include_directories(surface PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${rclcpp_INCLUDE_DIRS}
  ${GTK4_INCLUDE_DIRS}
  )
target_compile_features(surface PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS surface
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
