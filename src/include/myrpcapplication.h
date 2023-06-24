#pragma once

#include "myrpcconfig.h"
#include "myrpcchannel.h"
#include "myrpccontroller.h"

// myrpc框架的基础类，负责框架的一些初始化操作
class MyrpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MyrpcApplication& GetInstance();
    static MyrpcConfig& GetConfig();
private:
    static MyrpcConfig m_config;

    MyrpcApplication(){}
    MyrpcApplication(const MyrpcApplication&) = delete;
    MyrpcApplication(MyrpcApplication&&) = delete;
};