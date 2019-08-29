#include "softwareInfomation.h"
#include "versionHelpers.h"

//lower=true:��������16�i�����o��
//lower=false:�啶����16�V�����o��
std::string softwareInfomation::to_hexString(unsigned int val, bool lower = false)
{
	if (!val) {
		return std::string("0");
	}

	std::string str;
	const char hc = lower ? 'a' : 'A';


	while (val != 0) {
		int d = val & 15;     // 16�i���ꌅ���擾�B15(10)=1111(2)�ł���B

		if (d < 10) {
			//0�`9�́u���l�v��'0'�`'9'�́u�����v�ɕϊ�����B
			//'0'�͕����ł�int�^�ɂȂ�B���������āA���l�Ƃ̉��Z���\�B
			//���l�𒼐ڑ�����Ă��܂��ƁA�܂������ʂ̈Ӗ��ɂȂ��Ă��܂��B
			str.insert(str.begin(), d + '0');
		} else {
			//10�`19�́u���l�v����U0�`9�̐��l�ɕϊ����Ă���
			//'a'�`'z'�������́A'A'�`'Z'�́u�����v�ɕϊ�����
			str.insert(str.begin(), d - 10 + hc);
		}

		//�擾���������E��4�r�b�g�V�t�g����
		val >>= 4;

	}
	return str;
}

softwareInfomation::softwareInfomation()
{
	//Windows�̃o�[�W�������擾���A�w��̕�����`���ɕϊ�

	//DX���C�u�����̃o�[�W�������擾���A������ɕϊ�
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
