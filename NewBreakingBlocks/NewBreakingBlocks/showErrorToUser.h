#pragma once
#include <string>
#include "extendException.h"

typedef struct showOnErrorDialogInfomation
{
	std::string messageShowForUser;
	std::string developerTwitterAddress;
	std::string developerMailAddress;
	std::string exceptionTypeName;
	std::string exceptionDetail;
	std::string exceptionOccurPlaceFile;
	int exceptionOccurPlaceLine;
	std::string nowRunSoftwareName;
	std::string nowRunsoftwareVersion;
	std::string useOS;
	std::string dxLibraryVersion;
}showOnErrorDialogInfomation;

//Normal:extendException���p�����A����Ɍʂ̃N���X���Ƃɗ�O��⑫���Ă���ꍇ
//Extend:extendException���̂�⑫����ӏ��ŕߑ����ꂽ�ꍇ
//Std:C++�W����O�ł���ꍇ
//System:�\������O(0���Z��)�ł���ꍇ(�\������O��Windows�ɂ������݂��Ȃ�)
class showErrorToUser
{
private:
	void showErrorDialog(const showOnErrorDialogInfomation& errorInfomation);
public:
	showErrorToUser();
	void showNormalExceptionErrorDialog(const extendException& exceptionInstance, std::string messageShowForUser);
	void showExtendExceptionErrorDialog(const extendException& exceptionInstance, std::string messageShowForUser);
	void showStdExceptionErrorDialog(const std::exception& exceptionInstance,std::string messageShowForUser);
	void showSystemExceptionErrorDialog(std::string messageShowForUser);
	virtual ~showErrorToUser();
};

