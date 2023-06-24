# set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)

add_executable(provider ${SRC_LIST}) # 生成可执行文件
# provider需要连接动态库，连接框架的库myrpc和protobuf的库
target_link_libraries(provider myrpc protobuf)