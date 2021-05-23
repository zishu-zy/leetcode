# cmake 最低版本需求
cmake_minimum_required(VERSION 3.9)

# 工程名称
project(leetCode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(INCLUDE_PATH ./)

# 添加头文件的搜索路径
include_directories("${INCLUDE_PATH}")

# 编译源码生成目标
add_executable(leetCode 0093.cpp)

# 添加动态库
target_link_libraries(leetCode gtest gmock)
