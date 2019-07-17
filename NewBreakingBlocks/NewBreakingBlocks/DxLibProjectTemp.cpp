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
	 
	std::unique_ptr<bar> barInstance(new bar());
	std::unique_ptr<ball> ballInstance(new ball());
	std::unique_ptr<block> blockInstance(new block());

	barInstance->setObjectCoordinate(0, 0);
	ballInstance->setObjectCoordinate(0, 100);
	blockInstance->setObjectCoordinate(0, 200);

	barInstance->objectPaint();
	ballInstance->objectPaint();
	blockInstance->objectPaint();


	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
