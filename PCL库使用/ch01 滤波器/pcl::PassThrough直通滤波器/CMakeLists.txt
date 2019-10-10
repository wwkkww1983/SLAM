cmake_minimum_required(VERSION 3.15)
project(pcl__PassThrough)

set(CMAKE_CXX_STANDARD 14)
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_PassThrough main.cpp)


target_link_libraries(pcl_PassThrough ${PCL_LIBRARIES})