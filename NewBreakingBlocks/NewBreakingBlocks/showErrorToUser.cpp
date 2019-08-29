#include "showErrorToUser.h"
#include "softwareInfomation.h"


showErrorToUser::showErrorToUser()
{
}

void showErrorToUser::showNormalExceptionErrorDialog(const extendException& exceptionInstance, std::string messageShowForUser)
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//ユーザ向けエラーメッセージ
	errorInformation.messageShowForUser			= messageShowForUser;
	errorInformation.developerTwitterAddress	= softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress		= softInfo.getDeveloperMailAddress();

	//開発者向けエラーメッセージ
	errorInformation.exceptionTypeName			= exceptionInstance.getExceptionTypeName();
	errorInformation.exceptionDetail			= exceptionInstance.getDetailThisException();
	errorInformation.exceptionOccurPlaceFile	= exceptionInstance.getThrowExceptionFileName();
	errorInformation.exceptionOccurPlaceLine	= exceptionInstance.getThrowExceptionLineNumber();
	errorInformation.nowRunSoftwareName			= softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion		= softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS						= softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion			= softInfo.getDxLibraryVersion();

											
	this->showErrorDialog(errorInformation);
}

void showErrorToUser::showExtendExceptionErrorDialog(const extendException& exceptionInstance, std::string messageShowForUser)
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//ユーザ向けエラーメッセージ
	errorInformation.messageShowForUser = messageShowForUser;
	errorInformation.developerTwitterAddress = softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress = softInfo.getDeveloperMailAddress();

	//開発者向けエラーメッセージ
	errorInformation.exceptionTypeName = exceptionInstance.getExceptionTypeName();
	errorInformation.exceptionDetail = exceptionInstance.getDetailThisException();
	errorInformation.exceptionOccurPlaceFile = exceptionInstance.getThrowExceptionFileName();
	errorInformation.exceptionOccurPlaceLine = exceptionInstance.getThrowExceptionLineNumber();
	errorInformation.nowRunSoftwareName = softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion = softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS = softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion = softInfo.getDxLibraryVersion();


	this->showErrorDialog(errorInformation);
}

void showErrorToUser::showStdExceptionErrorDialog(const std::exception& exceptionInstance,std::string messageShowForUser)
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//ユーザ向けエラーメッセージ
	errorInformation.messageShowForUser = messageShowForUser;
	errorInformation.developerTwitterAddress = softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress = softInfo.getDeveloperMailAddress();

	//開発者向けエラーメッセージ
	errorInformation.exceptionTypeName = exceptionInstance.what();
	errorInformation.exceptionDetail = "Unknown";
	errorInformation.exceptionOccurPlaceFile = "Unknown";
	errorInformation.exceptionOccurPlaceLine = -1;
	errorInformation.nowRunSoftwareName = softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion = softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS = softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion = softInfo.getDxLibraryVersion();


	this->showErrorDialog(errorInformation);
}


void showErrorToUser::showSystemExceptionErrorDialog(std::string messageShowForUser)
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//ユーザ向けエラーメッセージ
	errorInformation.messageShowForUser = messageShowForUser;
	errorInformation.developerTwitterAddress = softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress = softInfo.getDeveloperMailAddress();

	//開発者向けエラーメッセージ
	errorInformation.exceptionTypeName = "構造化例外";
	errorInformation.exceptionDetail = "Unknown";
	errorInformation.exceptionOccurPlaceFile = "Unknown";
	errorInformation.exceptionOccurPlaceLine = -1;
	errorInformation.nowRunSoftwareName = softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion = softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS = softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion = softInfo.getDxLibraryVersion();


	this->showErrorDialog(errorInformation);
}

void showErrorToUser::showErrorDialog(const showOnErrorDialogInfomation & errorInfomation)
{
	std::string errorMessageOnErrorDialog = "";

	//ユーザー向けエラーメッセージ
	errorMessageOnErrorDialog += errorInfomation.messageShowForUser;
	errorMessageOnErrorDialog += "\n\n";
	errorMessageOnErrorDialog += "以上の項目を試し、コンピューター・本ソフトウェアの再起動を試してもエラーが再発する場合\n"
								"以下の連絡先から開発者にこのエラーダイアログの内容とともにご連絡ください。\n"
								"このエラーダイアログをアクティブ(ダイアログをクリックする)にした状態で\n"
								"Ctrl+C(CtrlキーとCキーを同時押し)すると、ダイアログの内容をコピーすることが出来ます。";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += "このソフトはエラーダイアログを閉じると自動的に終了します。";
	errorMessageOnErrorDialog += "\n\n";
	errorMessageOnErrorDialog += ("Twitter:" + errorInfomation.developerTwitterAddress);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("メールアドレス:" + errorInfomation.developerMailAddress);
	errorMessageOnErrorDialog += "\n\n";

	//開発者向けエラーメッセージ
	errorMessageOnErrorDialog += "===開発者向けエラーログ===";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("例外の型:" + errorInfomation.exceptionTypeName);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("詳細なエラー内容:" + errorInfomation.exceptionDetail);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("エラーが発生した場所:" + errorInfomation.exceptionOccurPlaceFile + " " + std::to_string(errorInfomation.exceptionOccurPlaceLine) + "行目");
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("アプリケーション名:" + errorInfomation.nowRunSoftwareName);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("アプリケーションバージョン:" + errorInfomation.nowRunsoftwareVersion);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("使用OS:" + errorInfomation.useOS);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("DXライブラリバージョン:" + errorInfomation.dxLibraryVersion);
	errorMessageOnErrorDialog += "\n";


	MessageBox(NULL,
		TEXT(errorMessageOnErrorDialog.c_str()),
		TEXT("致命的なエラー"),
		MB_OK | MB_ICONERROR);
}



showErrorToUser::~showErrorToUser()
{
}
