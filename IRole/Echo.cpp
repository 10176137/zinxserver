#include "Echo.h"
#include "../UserData/CmdMsg.h"
#include "../Iprotocol/CmdCheck.h"
bool Echorole::Init()
{
	return true;
}

UserData* Echorole::ProcMsg(UserData& _poUserData)
{
	GET_REF2DATA(CmdMsg, input, _poUserData);
	CmdMsg* pout = new CmdMsg(input);
	ZinxKernel::Zinx_SendOut(*pout, *(CmdCheck::GetInstance()));
	return nullptr;
}

void Echorole::Fini()
{
}
