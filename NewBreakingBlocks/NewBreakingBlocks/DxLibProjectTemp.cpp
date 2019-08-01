#include "ball.h"
#include "bar.h"
#include "block.h"
#include "imageLoadFailureExpection.h"

//DXライブラリのcheckHitKey関数を使用するときに用いる定数
constexpr int KEY_PUSH = 1;
constexpr int KEY_NOPUSH = 0;

//この定数の値を変えるとFPSを設定することが出来ます
//設定したいFPSをFPSとすると、以下の式で定数に代入する値を
//求めることが出来ます。
//ONE_FRAME_TIME_MSEC = 1000/FPS	ex)1000/60=16.66666・・・=16(小数点以下切り捨て)
//現在は60FPSに設定しています
constexpr unsigned int ONE_FRAME_TIME_MSEC = 16;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<ball> ballInstance;

	try
	{
		ballInstance.reset(new ball(0, 0));
	}
	catch (const imageLoadFailureExpection& expectionInstance)
	{
		MessageBox(NULL,
			TEXT("画像の読み込みに失敗しました。\n以下の点を確認してください。\n* resourceフォルダに画像が全て存在するか\n* resourceフォルダの位置を変更していないか"),
			TEXT("エラー"),
			MB_OK | MB_ICONERROR);
		goto FORCE_TERMINATE_THIS_SOFTWARE;
	}

	
	ballInstance->setBallVelocity(1, 0);
	printfDx("ballRadius:%d", ballInstance->getBallRadiusPixel());

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		unsigned int previousFrameTime = GetNowCount();

		ballInstance->moveBallAtTheSetVelocity();
		ballInstance->objectPaint();

		//ゲームのFPSを1000/ONE_FRAME_TIME_MSECに調整
		while ((GetNowCount() - previousFrameTime) < ONE_FRAME_TIME_MSEC) {
			Sleep(1);
		}

	}













	


	







	




	











	//例外処理などの理由でソフトを強制終了させたい場合は
	//goto FORCE_TERMINATE_THIS_SOFTWARE;を実行すること
	//通常終了時はこの文を使用せずbreak文などを使って自然にFORCE_TERMINATE_THIS_SOFTWAREに到達させること
	FORCE_TERMINATE_THIS_SOFTWARE:
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}



