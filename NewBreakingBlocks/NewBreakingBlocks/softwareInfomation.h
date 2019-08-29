#pragma once
#include <string>

class softwareInfomation
{
private:
	//_GetSystemInfo関数から帰ってくる値が16進数形式の文字列でこの変数に格納される。
	std::string windowsOSVersion = "";
	std::string nowRunSoftwareName = "BreakingBlocks";
	//FIXME:ファイルから自動取得するように変更する
	std::string nowRunSoftwareVersion = "prealpha6.1";
	//0xABCDはバージョンA.BCDの意である。
	std::string dxLibraryVersion = "";
	//FIXME:自動取得するように変更すること
	std::string developerTwitterAddress = "https://twitter.com/terapotan";
	//FIXME:自動取得するように変更すること
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

