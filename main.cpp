#include"zinx.h"
#include "./IChannel/StdInOutChannel.h"
#include "./IRole/Role.h"

class timerhello :public TimerOutProc
{
	// Í¨¹ý TimerOutProc ¼Ì³Ð
	void Proc() override
	{
		auto pchannel = ZinxKernel::Zinx_GetChannel_ByInfo("StdOut");
		std::string out = "nmsl";
		ZinxKernel::Zinx_SendOut(out, *pchannel);
	}
	int GetTimerSec() override
	{
		return 3;
	}
};
int main()
{
	ZinxKernel::ZinxKernelInit();
	TimerOutMng::GetInstance().AddTask(new timerhello());
	ZinxKernel::Zinx_Add_Channel(*(new StdInChannel()));
	ZinxKernel::Zinx_Add_Channel(*(new StdOutChannel()));
	ZinxKernel::Zinx_Add_Channel(*(new ZinxTimerChannel()));
	ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(12306,new TcpFact())));
	ZinxKernel::Zinx_Add_Role(*(new EchoRole()));
	ZinxKernel::Zinx_Add_Role(*(new OutputCtrl()));
	ZinxKernel::Zinx_Add_Role(*(new AddDataPre()));
	ZinxKernel::Zinx_Run();
	ZinxKernel::ZinxKernelFini();
	return 0;
}
