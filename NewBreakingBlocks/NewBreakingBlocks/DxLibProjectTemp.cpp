#include "ball.h"
#include "bar.h"
#include "block.h"
#include "imageLoadFailureExpection.h"
#include "hitJudgementBetweenObjects.h"
#include "realAndVirtualCoordinateSettings.h"
#include "playDisplayImageManagement.h"
#include "eventOccurCheckAndExecute.h"

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
	try {

		ChangeWindowMode(TRUE);

		if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
		{
			return -1;			// エラーが起きたら直ちに終了
		}


		SetDrawScreen(DX_SCREEN_BACK);

		playDisplayImageManagement playInstance;
		ball ballInstance(0, 0,playInstance);
		bar barInstance(30000, 0,playInstance);
		hitJudgementBetweenObjects hitJudgeInstance;
		eventOccurCheckAndExecute eventInstance;

		ballInstance.setBallVelocity(1, 0);
		barInstance.setBarVelocity(50);

		int previousFrameIsHitLeftKey = CheckHitKey(KEY_INPUT_LEFT);
		int previousFrameIsHitRightKey = CheckHitKey(KEY_INPUT_RIGHT);

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			unsigned int previousFrameTime = GetNowCount();
			int nowFrameIsHitLeftKey = CheckHitKey(KEY_INPUT_LEFT);
			int nowFrameIsHitRightKey = CheckHitKey(KEY_INPUT_RIGHT);
			//FIXME:eventCheckクラスとeventActionクラスを作成し
			//if文をまとめるリファクタリングを実施すること。

			if (previousFrameIsHitLeftKey == KEY_NOPUSH && nowFrameIsHitLeftKey == KEY_PUSH) {
				barInstance.setBarVelocity(-500);
			}

			if (previousFrameIsHitRightKey == KEY_NOPUSH && nowFrameIsHitRightKey == KEY_PUSH) {
				barInstance.setBarVelocity(500);
			}




			if (nowFrameIsHitLeftKey == KEY_NOPUSH && nowFrameIsHitRightKey == KEY_NOPUSH) {
				barInstance.setBarVelocity(0);
			}

			barInstance.moveBarAtTheSetVelocity();


			ballInstance.ballPaint();
			barInstance.barPaint();

			ballInstance.saveNowObjectStateToRectObject();
			barInstance.saveNowObjectStateToRectObject();

			DrawFormatString(0, 0, GetColor(255, 255, 255), "collisionCheck:%d", 
				hitJudgeInstance.hitJudgeRectAndRect(ballInstance.getRectObjectElements(),barInstance.getRectObjectElements() ));

			previousFrameIsHitLeftKey = CheckHitKey(KEY_INPUT_LEFT);
			previousFrameIsHitRightKey = CheckHitKey(KEY_INPUT_RIGHT);

			//ゲームのFPSを1000/ONE_FRAME_TIME_MSECに調整
			while ((GetNowCount() - previousFrameTime) < ONE_FRAME_TIME_MSEC) {
				Sleep(1);
			}

		}

	}//FIXME:imageLoadFailureExpectionのメンバにどの画像読み込みが失敗したか保持する変数を作る。
	catch (const imageLoadFailureExpection& expectionInstance)
	{
		MessageBox(NULL,
			TEXT("画像の読み込みに失敗しました。\n以下の点を確認してください。\n* resourceフォルダに画像が全て存在するか\n* resourceフォルダの位置を変更していないか"),
			TEXT("エラー"),
			MB_OK | MB_ICONERROR);
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

