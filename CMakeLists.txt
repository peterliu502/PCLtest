cmake_minimum_required(VERSION 3.19)
project(PCLtest)

set(CMAKE_CXX_STANDARD 14)
set(PCL_DIR "D:/ProgramFiles/vcpkg/packages/pcl_x86-windows/share/pcl/")
set(EIGEN_INCLUDE_DIR "D:/ProgramFiles/vcpkg/packages/eigen3_x86-windows/include")

find_package(PCL 1.3 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS} )

add_executable(PCLtest main.cpp)
target_link_libraries (PCLtest ${PCL_LIBRARIES})
add_executable(io io.cpp)
target_link_libraries (io ${PCL_LIBRARIES})
