# 设置cmake的最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(myrpc)

# 生成debug版本，可以进行gdb调试
set(CMAKE_BUILD_TYPE "Debug")

# 设置项目可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目编译头文件搜索路径 -I
# 将指定目录添加到编译器的头文件搜索路径之下
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
# 设置项目库文件搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)

# src包含了mprpc框架所有的相关代码
# 添加一个子目录并构建该子目录
# 子目录也要写个makefile，将子目录下源文件编译为库文件
add_subdirectory(src)
# example包含了mprpc框架使用的示例代码
add_subdirectory(example)