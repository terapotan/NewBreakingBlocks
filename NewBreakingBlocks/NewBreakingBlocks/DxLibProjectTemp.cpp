#include "ball.h"
#include "bar.h"
#include "block.h"
#include "imageLoadFailureExpection.h"
#include "hitJudgementBetweenObjects.h"
#include "realAndVirtualCoordinateSettings.h"

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

		ball ballInstance(0, 0);
		bar barInstance(30000, 0);
		hitJudgementBetweenObjects hitJudgeInstance;

		ballInstance.setBallVelocity(1, 0);
		barInstance.setBarVelocity(50);

		rectElements firstRect = {
			ballInstance.getBallCoordinateX(),
			ballInstance.getBallCoordinateY(),
			convertToVirtualCoordinateX(ballInstance.getBallDiamaterPixel()),
			convertToVirtualCoordinateY(ballInstance.getBallDiamaterPixel())
		};
		rectElements secondRect = {
			barInstance.getBarCoordinateX(),
			barInstance.getBarCoordinateY(),
			convertToVirtualCoordinateX(barInstance.getBarWidthPixel()),
			convertToVirtualCoordinateY(barInstance.getBarHeightPixel())
		};

		
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

			//以下代入
			//FIXME:構造体をこちら側で用意してそれにクラスのメンバ変数を代入している
			//このままでは冗長なうえ処理の無駄であるため
			//構造体をクラスのメンバ変数で用意する形にするか
			//クラスそのものを渡す形(rectObjectクラスを作成しball,barクラスのスーパークラスとする)にしたほうがいい
			firstRect.rectLeftUpCoordX = ballInstance.getBallCoordinateX();
			firstRect.rectLeftUpCoordY = ballInstance.getBallCoordinateY();
			//FIXME:座標は仮想座標なのにも関わらず円の直径だけ実座標になっている
			//めんどくさいので全て仮想座標で持つ形にすること
			firstRect.rectWidth = convertToVirtualCoordinateX(ballInstance.getBallDiamaterPixel());
			firstRect.rectHeight = convertToVirtualCoordinateY(ballInstance.getBallDiamaterPixel());

			secondRect.rectLeftUpCoordX = barInstance.getBarCoordinateX();
			secondRect.rectLeftUpCoordY = barInstance.getBarCoordinateY();
			//FIXME:座標は仮想座標なのにも関わらずバーの幅と高さだけ実座標になっている
			//めんどくさいので全て仮想座標で持つ形にすること
			secondRect.rectWidth = convertToVirtualCoordinateX(barInstance.getBarWidthPixel());
			secondRect.rectHeight = convertToVirtualCoordinateY(barInstance.getBarHeightPixel());

			//FIXME:カラーの色はどこかで宣言しておいたほうがいいだろう。
			DrawFormatString(0, 0, GetColor(255, 255, 255), "collisionCheck:%d", hitJudgeInstance.hitJudgeRectAndRect(firstRect, secondRect));

			previousFrameIsHitLeftKey = CheckHitKey(KEY_INPUT_LEFT);
			previousFrameIsHitRightKey = CheckHitKey(KEY_INPUT_RIGHT);

			//ゲームのFPSを1000/ONE_FRAME_TIME_MSECに調整
			while ((GetNowCount() - previousFrameTime) < ONE_FRAME_TIME_MSEC) {
				Sleep(1);
			}

		}

	}
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

