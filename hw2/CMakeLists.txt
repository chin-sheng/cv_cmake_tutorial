# CMake 最小指定版本要求為3.10.2
cmake_minimum_required(VERSION 3.10.2)
# 設定 Project 名稱
project(cpphw2)

# 設定尋找 header file 的路徑
include_directories(include/)

# Default
# Add Library Path:
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Build:
 add_executable(main main.cpp  src/deck.cpp src/card.cpp)

# 設定 C++ 版本為 11
set(DCMAKE_CXX_STANDARD 11)
set(DCMAKE_CXX_EXTENSIONS=OFF)
