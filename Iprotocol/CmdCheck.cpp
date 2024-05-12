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
        pret->isCmd = true;
        pret->isOpen = true;

    }
    else if ("close" == _szInput)
    {
        pret->isCmd = true;
        pret->isOpen = false;
    }

    return pret;
}

std::string* CmdCheck::response2raw(UserData& _oUserData)
{
    GET_REF2DATA(CmdMsg,output, _oUserData);
    return new std::string(output.szUserData);
}

Irole* CmdCheck::GetMsgProcessor(UserDataMsg& _oUserDataMsg)
{
    // 根据命令不同，交给不同的处理role
    auto RoleList = ZinxKernel::Zinx_GetAllRole();
    auto pCmdMsg = dynamic_cast<CmdMsg*>(_oUserDataMsg.poUserData);
    // 遍历容器 
    for (Irole* prople : RoleList)
    {
        if (pCmdMsg->isCmd)
        {
            OutputCtrl* OutCtrl = dynamic_cast<OutputCtrl*>(prople);
            if (OutCtrl != NULL)
            {
                return OutCtrl;
            }
        }
        else
        {
            EchoRole* Echo = dynamic_cast<EchoRole*>(prople);
            if (Echo != NULL)
            {
                return Echo;
            }
        }
		
    }
    return NULL;
}

Ichannel* CmdCheck::GetMsgSender(BytesMsg& _oBytes)
{
    return ZinxKernel::Zinx_GetChannel_ByInfo("StdOut");
}
