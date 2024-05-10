#include "CmdCheck.h"
#include "CmdMsg.h" 

CmdCheck* CmdCheck::poSingle = new CmdCheck();
int CmdCheck::kell = 1145;
UserData* CmdCheck::raw2request(std::string _szInput)
{
    auto pret = new CmdMsg();
    pret->szUserData = _szInput;
    return pret;
}

std::string* CmdCheck::response2raw(UserData& _oUserData)
{
    GET_REF2DATA(CmdMsg,output, _oUserData);
    return new std::string();
}

Irole* CmdCheck::GetMsgProcessor(UserDataMsg& _oUserDataMsg)
{
    // 根据命令不同，交给不同的处理role
    return nullptr;
}

Ichannel* CmdCheck::GetMsgSender(BytesMsg& _oBytes)
{
    
    return ZinxKernel::Zinx_GetChannel_ByInfo("sdout");
}
