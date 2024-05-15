#pragma once
#include <zinx.h>

class CmdCheck :
    public Iprotocol
{
    // 通过 Iprotocol 继承
    static CmdCheck* poSingle;
    CmdCheck();
    virtual ~CmdCheck();

public:

    // 通过sdin的输入生成CmdMsg
    UserData* raw2request(std::string _szInput) override;

    std::string* response2raw(UserData& _oUserData) override;

    Irole* GetMsgProcessor(UserDataMsg& _oUserDataMsg) override;

    Ichannel* GetMsgSender(BytesMsg& _oBytes) override;
    static CmdCheck* GetInstance()
    {
        return poSingle;
    }
    
    std::string szOutChannel;
};

