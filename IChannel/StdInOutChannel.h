#pragma once
#include <zinx.h>
class StdInChannel :
    public Ichannel
{
    // ͨ�� Ichannel �̳�
    bool Init() override;
    bool ReadFd(std::string& _input) override;
    bool WriteFd(std::string& _output) override;
    void Fini() override;
    int GetFd() override;
    std::string GetChannelInfo() override;
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};

class StdOutChannel :
    public Ichannel
{
    // ͨ�� Ichannel �̳�
    bool Init() override;
    bool ReadFd(std::string& _input) override;
    bool WriteFd(std::string& _output) override;
    void Fini() override;
    int GetFd() override;
    std::string GetChannelInfo() override;
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};
