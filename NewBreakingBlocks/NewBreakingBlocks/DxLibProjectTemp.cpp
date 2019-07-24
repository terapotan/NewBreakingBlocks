#include "ball.h"
#include "bar.h"
#include "block.h"


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

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		ballInstance->setObjectCoordinate(ballCoordinateX,0);
		ballInstance->objectPaint();
		ballCoordinateX += 1;
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
