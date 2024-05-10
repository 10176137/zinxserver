#include "Echo.h"
#include "CmdMsg.h"
bool Echorole::Init()
{
	return false;
}

UserData* Echorole::ProcMsg(UserData& _poUserData)
{
	GET_REF2DATA(CmdMsg, input, _poUserData);
	auto szData = input.szUserData;
	// ZinxKernel::Zinx_SendOut(_poUserData, );
	return nullptr;
}

void Echorole::Fini()
{
}
