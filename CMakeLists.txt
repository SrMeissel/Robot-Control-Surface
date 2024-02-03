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

# set(Qt6_DIR /home/meissel/Qt/6.6.1/gcc_64/lib/cmake)
set(CMAKE_PREFIX_PATH "/home/meissel/Qt/6.6.1/gcc_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(surface src/surface.cpp)

#set_target_properties(surface PROPERTIES INSTALL_RPATH /home/meissel/Qt/6.6.1/gcc_64/lib)

target_link_libraries(surface PRIVATE Qt6::Widgets)

target_include_directories(surface PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
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
