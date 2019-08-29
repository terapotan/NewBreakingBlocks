#include "showErrorToUser.h"
#include "softwareInfomation.h"


showErrorToUser::showErrorToUser()
{
}

void showErrorToUser::showNormalExceptionErrorDialog()
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//ユーザ向けエラーメッセージ
	errorInformation.messageShowForUser			= "画像の読み込みに失敗しました。\n"
								   				"以下の項目を確認してください。\n"
								   				"* resourceフォルダの位置を変更していないか\n"
								   				"* resourceフォルダの中に画像ファイルが全て存在するか";
	errorInformation.developerTwitterAddress	= softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress		= softInfo.getDeveloperMailAddress();

	//開発者向けエラーメッセージ
	errorInformation.exceptionTypeName			= "imageLoadFailureException";
	errorInformation.exceptionDetail			= "ball.pngの読み込みに失敗しました。";
	errorInformation.exceptionOccurPlaceFile	= "playDisplayImageManagement.cpp";
	errorInformation.exceptionOccurPlaceLine	= 10;
	errorInformation.nowRunSoftwareName			= softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion		= softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS						= softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion			= softInfo.getDxLibraryVersion();
	errorInformation.messageShowForDeveloper	= "* exeファイルの2階層上の1階層下にresourceフォルダが存在すること\n"
												  "* パスの区切り字が間違っていないこと\n"
												  "* 読み込み失敗したファイルが存在すること、破損していないこと"
												  "を確認してください。";
											
	this->showErrorDialog(errorInformation);
}

void showErrorToUser::showExtendExceptionErrorDialog()
{
}

void showErrorToUser::showStdExceptionErrorDialog()
{
}


void showErrorToUser::showSystemExceptionErrorDialog()
{
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
	errorMessageOnErrorDialog += "===開発者向けの対処方法===";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += errorInfomation.messageShowForDeveloper;


	MessageBox(NULL,
		TEXT(errorMessageOnErrorDialog.c_str()),
		TEXT("致命的なエラー"),
		MB_OK | MB_ICONERROR);
}

showErrorToUser::~showErrorToUser()
{
}
