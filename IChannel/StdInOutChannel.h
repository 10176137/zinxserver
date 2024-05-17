#pragma once
#include <zinx.h>
#include <ZinxTCP.h>
#include <vector>
class StdInChannel :
    public Ichannel
{
    // 通过 Ichannel 继承
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
    // 通过 Ichannel 继承
    bool Init() override;
    bool ReadFd(std::string& _input) override;
    bool WriteFd(std::string& _output) override;
    void Fini() override;
    int GetFd() override;
    std::string GetChannelInfo() override;
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};

class TcpChannel :
    public ZinxTcpData
{
    // 通过 ZinxTcpData 继承
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
public:
    TcpChannel(int _fd) :ZinxTcpData(_fd){}
};

class TcpFact :public IZinxTcpConnFact
{
    // 通过 IZinxTcpConnFact 继承
    ZinxTcpData* CreateTcpDataChannel(int _fd) override;
};

class ZinxTimerChannel :public Ichannel
{
    int _timerfd = 1;
    // 通过 Ichannel 继承
    bool Init() override;
    bool ReadFd(std::string& _input) override;
    bool WriteFd(std::string& _output) override;
    void Fini() override;
    int GetFd() override;
    std::string GetChannelInfo() override;
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};

class TimerOutProc 
{
public:
    int iperiod = 0;
    int sec = 0;
    virtual void Proc() = 0;
    virtual int GetTimerSec() = 0;
    int GetTimerPeriod();
};

class TimerOutMng : public AZinxHandler
{
    std::vector<std::list<TimerOutProc*>*>m_task_arry;
    static TimerOutMng single;
    int sec = 0;
public:
    TimerOutMng();

    // 通过 AZinxHandler 继承
    IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;

    AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;

    void AddTask(TimerOutProc*_task);
    void DelTask(TimerOutProc* _task);
    static TimerOutMng& GetInstance()
    {
        return single;
    }

};