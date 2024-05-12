#pragma once
#include <zinx.h>
class EchoRole :
    public Irole
{
    // ͨ�� Irole �̳�
    bool Init() override;

    // ��д
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
};

class OutputCtrl :public Irole
{
    // ͨ�� Irole �̳�
    bool Init() override;
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
    Ichannel* pout = NULL;
};

class AddDataPre : public Irole
{
    // ͨ�� Irole �̳�
    bool Init() override;
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
    bool needAddData = false;
};
