#pragma once
#include <zinx.h>
class EchoRole :
    public Irole
{
    // 通过 Irole 继承
    bool Init() override;

    // 重写
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
};

class OutputCtrl :public Irole
{
    // 通过 Irole 继承
    bool Init() override;
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
    Ichannel* pout = NULL;
};

class AddDataPre : public Irole
{
    // 通过 Irole 继承
    bool Init() override;
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
    bool needAddData = false;
};
