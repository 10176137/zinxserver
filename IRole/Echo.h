#pragma once
#include <zinx.h>
class Echorole :
    public Irole
{
    // ͨ�� Irole �̳�
    bool Init() override;

    // ��д
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
};

