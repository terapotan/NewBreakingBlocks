#include "showErrorToUser.h"


showErrorToUser::showErrorToUser()
{
}

void showErrorToUser::showNormalExceptionErrorDialog()
{
	constexpr const char* errorMessage = "画像の読み込みに失敗しました。\n"
		"以下の項目を確認してください。\n"
		"* resourceフォルダの位置を変更していないか\n"
		"* resourceフォルダの中に画像ファイルが全て存在するか\n"
		"\n"
		"以上の項目を試し、コンピューター・本ソフトウェアの再起動を試してもエラーが再発する場合\n"
		"以下の連絡先から開発者にこのエラーダイアログの内容とともにご連絡ください。\n"
		"このエラーダイアログをアクティブ(ダイアログをクリックする)にした状態で\n"
		"Ctrl+C(CtrlキーとCキーを同時押し)すると、ダイアログの内容をコピーすることが出来ます。\n"
		"\n"
		"Twitter:https://twitter.com/terapotan\n"
		"メールアドレス:gameblog60@gmail.com\n\n"
		"===開発者向けエラーログ===\n"
		"例外の型:imageLoadFailueException\n"
		"詳細なエラー内容:ball.pngの読み込みに失敗しました。\n"
		"エラーが発生した場所:playDisplayImageManagement.cpp xx行目\n"
		"アプリケーション名:BreakingBlocks\n"
		"アプリケーションバージョン:prealpha6.1\n"
		"使用OS:Windows10\n"
		"DXライブラリバージョン(3.02f)\n"
		"===開発者向けの対処方法===\n"
		"* exeファイルの2階層上の1階層下にresourceフォルダが存在すること\n"
		"* パスの区切り字が間違っていないこと\n"
		"* 読み込み失敗したファイルが存在すること、破損していないこと"
		"を確認してください。\n";

	MessageBox(NULL,
		TEXT(errorMessage),
		TEXT("エラー"),
		MB_OK | MB_ICONERROR);
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

showErrorToUser::~showErrorToUser()
{
}
