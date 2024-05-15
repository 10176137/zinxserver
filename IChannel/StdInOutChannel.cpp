#include "StdInOutChannel.h"
#include "../Iprotocol/CmdCheck.h"
#include <sys/timerfd.h>
bool StdInChannel::Init()
{
	return true;
}

bool StdInChannel::ReadFd(std::string& _input)
{
	std::cin >> _input;
	return true;
}

bool StdInChannel::WriteFd(std::string& _output)
{
	return false;
}

void StdInChannel::Fini()
{
}

int StdInChannel::GetFd()
{
	return 0;
}

std::string StdInChannel::GetChannelInfo()
{
	return "StdIn";
}

AZinxHandler* StdInChannel::GetInputNextStage(BytesMsg& _oInput)
{
	return CmdCheck::GetInstance();
}

bool StdOutChannel::Init()
{
	return true;
}

bool StdOutChannel::ReadFd(std::string& _input)
{
	return false;
}

bool StdOutChannel::WriteFd(std::string& _output)
{
	std::cout << _output << std::endl;
	return true;
}

void StdOutChannel::Fini()
{
}

int StdOutChannel::GetFd()
{
	return 1;
}

std::string StdOutChannel::GetChannelInfo()
{
	return "StdOut";
}

AZinxHandler* StdOutChannel::GetInputNextStage(BytesMsg& _oInput)
{
	return nullptr;
}

AZinxHandler* TcpChannel::GetInputNextStage(BytesMsg& _oInput)
{
	return CmdCheck::GetInstance();
}

ZinxTcpData* TcpFact::CreateTcpDataChannel(int _fd)
{
	return new TcpChannel(_fd);
}

bool ZinxTimerChannel::Init()
{
	bool bRet = false;
	int ifd = timerfd_create(CLOCK_MONOTONIC, 0);
	if (ifd >= 0)
	{
		struct itimerspec period = { {5,0},{10,0} };
		if (0 == timerfd_settime(ifd, 0, &period, NULL))
		{
			bRet = true;
			_timerfd = ifd;
		}
	}
	return bRet;
}

bool ZinxTimerChannel::ReadFd(std::string& _input)
{
	bool bRet = false;
	char buff[8] = { 0 };
	if (sizeof(buff)==read(_timerfd, buff, sizeof(buff)))
	{
		bRet = true;
		_input.assign(buff, sizeof(buff));
	}

	return bRet;
}

bool ZinxTimerChannel::WriteFd(std::string& _output)
{

	return false;
}

void ZinxTimerChannel::Fini()
{
	close(_timerfd);
	_timerfd = -1;
}

int ZinxTimerChannel::GetFd()
{
	return _timerfd;
}

std::string ZinxTimerChannel::GetChannelInfo()
{
	return "TimerFd";
}

AZinxHandler* ZinxTimerChannel::GetInputNextStage(BytesMsg& _oInput)
{
	return &TimerOutMng::GetInstance();
}
TimerOutMng TimerOutMng::single;
IZinxMsg* TimerOutMng::InternelHandle(IZinxMsg& _oInput)
{

	for (auto task : m_task_list)
	{
		task->iCount--;
		if (task->iCount <= 0)
		{
			task->Proc();
			task->iCount = task->GetTimerSec();
		}
	}

	return nullptr;
}

AZinxHandler* TimerOutMng::GetNextHandler(IZinxMsg& _oNextMsg)
{
	return nullptr;
}

void TimerOutMng::AddTask(TimerOutProc* _task)
{
	m_task_list.push_back(_task);
	_task->iCount = _task->GetTimerSec();
}

void TimerOutMng::DelTask(TimerOutProc* _task)
{
	
}
