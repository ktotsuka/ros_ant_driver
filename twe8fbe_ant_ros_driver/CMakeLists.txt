cmake_minimum_required(VERSION 2.8.3)
project(twe8fbe_ant_ros_driver)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  roslib
  sensor_msgs
  nav_msgs
  geometry_msgs
  std_msgs
  odva_ethernetip
)

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

catkin_package(CATKIN_DEPENDS
               odva_ethernetip
               #INCLUDE_DIRS include
               #LIBRARIES include
               )

set(SOURCE_FILES
  "src/ant_ros_driver.cpp")

add_executable(and_ros_driver ${SOURCE_FILES})
target_link_libraries(and_ros_driver ${catkin_LIBRARIES})
add_dependencies(and_ros_driver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

