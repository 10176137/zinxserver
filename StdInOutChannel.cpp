#include "StdInOutChannel.h"

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
	return "stdIn";
}

AZinxHandler* StdInChannel::GetInputNextStage(BytesMsg& _oInput)
{
	return nullptr;
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
