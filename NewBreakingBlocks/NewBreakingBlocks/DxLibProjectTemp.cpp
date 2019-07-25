#include "ball.h"
#include "bar.h"
#include "block.h"

//DXライブラリのcheckHitKey関数を使用するときに用いる定数
constexpr int KEY_PUSH = 1;
constexpr int KEY_NOPUSH = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<ball> ballInstance(new ball());


	int ballCoordinateX = 100;
	int preFrameButtonState = CheckHitKey(KEY_INPUT_A);
	int nowFrameButtonState;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		ballInstance->setObjectCoordinate(ballCoordinateX,0);
		ballInstance->objectPaint();

		nowFrameButtonState = CheckHitKey(KEY_INPUT_A);

		//前のフレームで押されていなかったときだけ移動する
		if ((preFrameButtonState == KEY_NOPUSH) && (nowFrameButtonState == KEY_PUSH)) {
			ballCoordinateX += 1;
		}

		preFrameButtonState = nowFrameButtonState;
		
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
