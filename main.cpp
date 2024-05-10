#include"zinxserver.h"
Echo* poEcho = new Echo();
ExiFramework* iexit = new ExiFramework();
TestStdOut* poOut = new TestStdOut();
TestStdin* poStdin = new TestStdin();
int main()
{
	ZinxKernel::ZinxKernelInit();
	TestStdin* poStdin = new TestStdin();
	ZinxKernel::Zinx_Add_Channel(*poStdin);
	ZinxKernel::Zinx_Add_Channel(*poOut);
	ZinxKernel::Zinx_Run();
	ZinxKernel::ZinxKernelFini();
	return 0;
}
