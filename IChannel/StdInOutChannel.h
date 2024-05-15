#pragma once
#include <zinx.h>
#include <ZinxTCP.h>
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

class TcpChannel :
    public ZinxTcpData
{
    // ͨ�� ZinxTcpData �̳�
    AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
public:
    TcpChannel(int _fd) :ZinxTcpData(_fd){}
};

class TcpFact :public IZinxTcpConnFact
{
    // ͨ�� IZinxTcpConnFact �̳�
    ZinxTcpData* CreateTcpDataChannel(int _fd) override;
};

class ZinxTimerChannel :public Ichannel
{
    int _timerfd = 1;
    // ͨ�� Ichannel �̳�
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
    int iCount = -1;
    virtual void Proc() = 0;
    virtual int GetTimerSec() = 0;
};

class TimerOutMng : public AZinxHandler
{
    std::list<TimerOutProc*>m_task_list;
    static TimerOutMng single;
public:


    // ͨ�� AZinxHandler �̳�
    IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;

    AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;

    void AddTask(TimerOutProc*_task);
    void DelTask(TimerOutProc* _task);
    static TimerOutMng& GetInstance()
    {
        return single;
    }

};