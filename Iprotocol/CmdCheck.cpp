#include "CmdCheck.h"
#include "../UserData/CmdMsg.h" 
#include "../IRole/Role.h"
CmdCheck* CmdCheck::poSingle = new CmdCheck();
CmdCheck::CmdCheck()
{
}
CmdCheck::~CmdCheck()
{
}

UserData* CmdCheck::raw2request(std::string _szInput)
{
 
    if (_szInput == "exit")
    {
        ZinxKernel::Zinx_Exit();
        return NULL;
    }

    auto pret = new CmdMsg();
    pret->szUserData = _szInput;
    if ("open"==_szInput)
    {
        pret->_cmdType = 2;
        pret->isOpen = true;
    }
    else if ("close" == _szInput)
    {
        pret->_cmdType = 2;
        pret->isOpen = false;
    }
    else if ("data" == _szInput)
    {
        pret->_cmdType = 1;
        pret->needDataPre = true;
    }
    else if ("cleardata" == _szInput)
    {
        pret->_cmdType = 1;
        pret->needDataPre = false;
    }

    return pret;
}

std::string* CmdCheck::response2raw(UserData& _oUserData)
{
    GET_REF2DATA(CmdMsg, output, _oUserData);
    return new std::string(output.szUserData);
}

Irole* CmdCheck::GetMsgProcessor(UserDataMsg& _oUserDataMsg)  // _oUserDataMsg中有个基类UserData（CmdMsg的父类）
{
    if (_oUserDataMsg.szInfo == "StdIn")
    {
        this->szOutChannel = "StdOut";
    }
    // 根据命令不同，交给不同的处理role
    auto RoleList = ZinxKernel::Zinx_GetAllRole();
    auto pCmdMsg = dynamic_cast<CmdMsg*>(_oUserDataMsg.poUserData);
    // 遍历容器 
    for (Irole* prople : RoleList)
    {
        switch (pCmdMsg->_cmdType)
        {
        case 0:

        case 1:
        {
            auto nextrole = dynamic_cast<AddDataPre*>(prople);
            if (nextrole != NULL)
            {
                return nextrole;
            }
            continue;
        }
        case 2:
        {
            auto nextrole = dynamic_cast<OutputCtrl*>(prople);
            if (nextrole != NULL)
            {
                return nextrole;
            }
            continue;
        }
        }
    }
    return NULL;
}

Ichannel* CmdCheck::GetMsgSender(BytesMsg& _oBytes)
{
    return ZinxKernel::Zinx_GetChannel_ByInfo(this->szOutChannel);
}
