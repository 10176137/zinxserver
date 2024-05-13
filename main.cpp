#include"zinx.h"
#include "./IChannel/StdInOutChannel.h"
#include "./IRole/Role.h"

int main()
{
	ZinxKernel::ZinxKernelInit();
	ZinxKernel::Zinx_Add_Channel(*(new StdInChannel()));
	ZinxKernel::Zinx_Add_Channel(*(new StdOutChannel()));
	ZinxKernel::Zinx_Add_Channel(*(new ZinxTCPListen(12306,new TcpFact())));
	ZinxKernel::Zinx_Add_Role(*(new EchoRole()));
	ZinxKernel::Zinx_Add_Role(*(new OutputCtrl()));
	ZinxKernel::Zinx_Add_Role(*(new AddDataPre()));
	ZinxKernel::Zinx_Run();
	ZinxKernel::ZinxKernelFini();
	return 0;
}
