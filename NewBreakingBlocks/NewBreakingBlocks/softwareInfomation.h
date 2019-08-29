#pragma once
#include <string>

class softwareInfomation
{
private:
	//_GetSystemInfo�֐�����A���Ă���l��16�i���`���̕�����ł��̕ϐ��Ɋi�[�����B
	std::string windowsOSVersion = "";
	std::string nowRunSoftwareName = "BreakingBlocks";
	//FIXME:�t�@�C�����玩���擾����悤�ɕύX����
	std::string nowRunSoftwareVersion = "prealpha6.1";
	//0xABCD�̓o�[�W����A.BCD�̈ӂł���B
	std::string dxLibraryVersion = "";
	//FIXME:�����擾����悤�ɕύX���邱��
	std::string developerTwitterAddress = "https://twitter.com/terapotan";
	//FIXME:�����擾����悤�ɕύX���邱��
	std::string developerMailAddress = "gameblog60@gmail.com";

	std::string to_hexString(unsigned int val, bool lower);
public:
	softwareInfomation();
	const std::string& getWindowsOSVersion() const;
	const std::string& getNowRunSoftwareName() const;
	const std::string& getNowRunSoftwareVersion() const;
	const std::string& getDxLibraryVersion() const;
	const std::string& getDeveloperTwitterAddress() const;
	const std::string& getDeveloperMailAddress() const;


	virtual ~softwareInfomation();

};

