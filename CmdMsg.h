#pragma once
#include <zinx.h>
#include <string.h>
class CmdMsg :
    public UserData
{
public:
    // 成员变量表示要回显的字符
    std::string szUserData;
};

