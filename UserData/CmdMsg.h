#pragma once
#include <zinx.h>
#include <string.h>
class CmdMsg :
    public UserData
{
public:
    // ��Ա������ʾҪ���Ե��ַ�
    std::string szUserData;
    bool isOpen = true;
    bool isCmd = false;
};

