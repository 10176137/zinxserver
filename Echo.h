#pragma once
#include <zinx.h>
class Echorole :
    public Irole
{
    // Í¨¹ý Irole ¼Ì³Ð
    bool Init() override;
    UserData* ProcMsg(UserData& _poUserData) override;
    void Fini() override;
};

