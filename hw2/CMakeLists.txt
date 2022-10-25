# CMake 最小指定版本要求為3.10.2
cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# 設定 Project 名稱
project(cpphw2)

# 設定尋找 header file 的路徑
include_directories(include/)


# Build:
 add_executable(main main.cpp  src/deck.cpp src/card.cpp)

