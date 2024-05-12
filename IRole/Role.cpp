#include "Role.h"
#include "../UserData/CmdMsg.h"
#include "../Iprotocol/CmdCheck.h"
bool EchoRole::Init()
{
	return true;
}

UserData* EchoRole::ProcMsg(UserData& _poUserData)
{

	GET_REF2DATA(CmdMsg, input, _poUserData);
	CmdMsg* pout = new CmdMsg(input);
	ZinxKernel::Zinx_SendOut(*pout, *(CmdCheck::GetInstance()));
	return nullptr;
}

void EchoRole::Fini()
{
}

bool OutputCtrl::Init()
{
	return true;
}

UserData* OutputCtrl::ProcMsg(UserData& _poUserData)
{
	GET_REF2DATA(CmdMsg, input, _poUserData);
	if (input.isOpen == true)
	{
		if (pout != nullptr)
		{
			ZinxKernel::Zinx_Add_Channel(*pout);
		}
	}
	else
	{
		auto pchannel = ZinxKernel::Zinx_GetChannel_ByInfo("StdOut");
		// 从Zinx通道队列中删除
		ZinxKernel::Zinx_Del_Channel(*pchannel);
		pout = pchannel;
	}
	return nullptr;
}

void OutputCtrl::Fini()
{
}

bool AddDataPre::Init()
{
	auto RoleList = ZinxKernel::Zinx_GetAllRole();
	for (Irole *echo : RoleList)
	{
		auto nextrole = dynamic_cast<EchoRole*>(echo);
		if (nextrole != NULL)
		{
			this->SetNextProcessor(*nextrole);
		}
	}
	
	return true;
}

UserData* AddDataPre::ProcMsg(UserData& _poUserData)
{
	CmdMsg* pret = NULL;
	GET_REF2DATA(CmdMsg, input, _poUserData);
	if (input._cmdType == 1)
	{
		this->needAddData = input.needDataPre;
	}

	if (needAddData)
	{
		time_t tmp;
		time(&tmp);
		std::string szNew = std::string(ctime(&tmp)) + input.szUserData;
		pret = new CmdMsg();
		pret->szUserData = szNew;
		return pret;
	}

	pret = new CmdMsg();
	pret->szUserData = input.szUserData;
	return pret;
}

void AddDataPre::Fini()
{
}
