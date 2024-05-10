#pragma once
#include<zinx.h>
class TestStdOut :public Ichannel
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
class Echo :public AZinxHandler
{
	// ������׼�����
public:

	// ͨ�� AZinxHandler �̳�
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;

	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;

};
class TestStdin :public Ichannel
{
public:
	// ͨ�� Ichannel �̳�
	bool Init() override;
	bool ReadFd(std::string& _input) override;
	bool WriteFd(std::string& _output) override;
	void Fini() override;
	int GetFd() override;
	std::string GetChannelInfo() override;
	AZinxHandler* GetInputNextStage(BytesMsg& _oInput) override;
};

// �˳�������
class ExiFramework :public AZinxHandler
{
	// ͨ�� AZinxHandler �̳�
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;
	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;
};

// ������
class Command :public AZinxHandler
{
	// ͨ�� AZinxHandler �̳�
	IZinxMsg* InternelHandle(IZinxMsg& _oInput) override;
	AZinxHandler* GetNextHandler(IZinxMsg& _oNextMsg) override;
};