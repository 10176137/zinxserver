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
    int _cmdType = 0;
    bool needDataPre = false;
};

