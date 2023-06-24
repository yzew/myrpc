#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug; // proto中定义了package fixbug;  // 声明了代码所在的包（对于C++相当于namespace）

/////////////////////////////  protobuf演示  /////////////////////////////
int main2()
{
    
//     message GetFriendListsResponse
// {
//     ResultCode result = 1;
//     repeated User friend_list = 2;  // 用repeated定义了一个列表类型
// }

    GetFriendListsResponse rsp;

    // ResultCode是GetFriendListsResponse的一个变量
    ResultCode *rc = rsp.mutable_result(); 
    rc->set_errcode(0);

    // 在friend_list列表里添加两行
    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(22);
    user2->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;

    return 0;
}

int main()
{
    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 =》 char*
    std::string send_str;
    if (req.SerializeToString(&send_str))
    {
        // c_str()将send_str转成c语言的char*类型
        std::cout << send_str.c_str() << std::endl;
    }

    // 从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if (reqB.ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}