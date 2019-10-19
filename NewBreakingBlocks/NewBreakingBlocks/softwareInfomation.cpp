#include "softwareInfomation.h"
#include "versionHelpers.h"

//lower=true:小文字で16進数を出力
//lower=false:大文字で16新数を出力
std::string softwareInfomation::to_hexString(unsigned int val, bool lower = false)
{
	if (!val) {
		return std::string("0");
	}

	std::string str;
	const char hc = lower ? 'a' : 'A';


	while (val != 0) {
		int d = val & 15;     // 16進数一桁を取得。15(10)=1111(2)である。

		if (d < 10) {
			//0～9の「数値」を'0'～'9'の「文字」に変換する。
			//'0'は文中ではint型になる。したがって、数値との演算が可能。
			//数値を直接代入してしまうと、まったく別の意味になってしまう。
			str.insert(str.begin(), d + '0');
		} else {
			//10～19の「数値」を一旦0～9の数値に変換してから
			//'a'～'z'もしくは、'A'～'Z'の「文字」に変換する
			str.insert(str.begin(), d - 10 + hc);
		}

		//取得した分を右へ4ビットシフトする
		val >>= 4;

	}
	return str;
}

softwareInfomation::softwareInfomation()
{
	//Windowsのバージョンを取得し、指定の文字列形式に変換

	//DXライブラリのバージョンを取得し、文字列に変換
	int libraryVersion,windowsVersion;
	_GetSystemInfo(&libraryVersion, NULL, &windowsVersion);
	this->dxLibraryVersion = "0x" + this->to_hexString(libraryVersion);
	this->windowsOSVersion = "0x" + this->to_hexString(windowsVersion);
}

const std::string& softwareInfomation::getWindowsOSVersion () const
{
	return this->windowsOSVersion;
}

const std::string&  softwareInfomation::getNowRunSoftwareName() const
{
	return this->nowRunSoftwareName;
}

const std::string&  softwareInfomation::getNowRunSoftwareVersion() const
{
	return this->nowRunSoftwareVersion;
}

const std::string&  softwareInfomation::getDxLibraryVersion() const
{
	return this->dxLibraryVersion;
}

const std::string&  softwareInfomation::getDeveloperTwitterAddress() const
{
	return this->developerTwitterAddress;
}

const std::string& softwareInfomation::getDeveloperMailAddress() const
{
	return this->developerMailAddress;
}




softwareInfomation::~softwareInfomation()
{
}
