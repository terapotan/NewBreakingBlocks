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

//Normal:extendExceptionを継承し、さらに個別のクラスごとに例外を補足している場合
//Extend:extendException自体を補足する箇所で捕捉された場合
//Std:C++標準例外である場合
//System:構造化例外(0除算等)である場合(構造化例外はWindowsにしか存在しない)
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

