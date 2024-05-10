#pragma once
#include <zinx.h>

class CmdCheck :
    public Iprotocol
{
    // Í¨¹ý Iprotocol ¼Ì³Ð
private:
    static CmdCheck* poSingle;
    CmdCheck();
    virtual ~CmdCheck();
public:
    static int kell;
    UserData* raw2request(std::string _szInput) override;
    std::string* response2raw(UserData& _oUserData) override;
    Irole* GetMsgProcessor(UserDataMsg& _oUserDataMsg) override;
    Ichannel* GetMsgSender(BytesMsg& _oBytes) override;
    static CmdCheck* GetInstance() 
    {
        return poSingle;
    }
};

