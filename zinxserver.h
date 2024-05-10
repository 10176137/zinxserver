#pragma once
#include<zinx.h>
class TestStdOut :public Ichannel
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
class Echo :public AZinxHandler
{
	// 创建标准输出类
public:

	// 通过 AZinxHandler 继承
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;

	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;

};
class TestStdin :public Ichannel
{
public:
	// 通过 Ichannel 继承
	bool Init() override;
	bool ReadFd(std::string& _input) override;
	bool WriteFd(std::string& _output) override;
	void Fini() override;
	int GetFd() override;
	std::string GetChannelInfo() override;
	AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};

// 退出功能类
class ExiFramework :public AZinxHandler
{
	// 通过 AZinxHandler 继承
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;
	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;
};

// 命令类
class Command :public AZinxHandler
{
	// 通过 AZinxHandler 继承
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;
	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;
};