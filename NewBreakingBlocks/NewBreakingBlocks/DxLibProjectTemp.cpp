#include "imageLoadFailureException.h"
#include "hitJudgementBetweenObjects.h"
#include "realAndVirtualCoordinateSettings.h"
#include "playDisplayImageManagement.h"
#include "eventOccurCheckAndExecute.h"
#include "showErrorToUser.h"
#include "callUnknownEventExecuteClassException.h"
#include "setFailureEventOccurCheckClass.h"
#include "managementSceneObjects.h"
#include "userInputManagement.h"
#include <string>

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

		managementSceneObjects sceneObjects;

		std::shared_ptr<ball> ballInstance = sceneObjects.ballInstance;
		std::shared_ptr<bar> barInstance = sceneObjects.barInstance;

		eventOccurCheckAndExecute eventInstance;
		std::shared_ptr<userInputManagement> inputInstance = sceneObjects.userInputManagementInstance;

		ballInstance->setBallVelocity(1, 0);
		barInstance->setBarVelocity(50);


		inputInstance->setPreviousKeyStateAll();

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			unsigned int previousFrameTime = GetNowCount();
			inputInstance->setNowKeyStateAll();

			eventInstance.executeOccurCheckClasses(sceneObjects);
			eventInstance.executeEventExecuteClasses(sceneObjects);

			ballInstance->ballPaint();
			barInstance->barPaint();
			
			inputInstance->setPreviousKeyStateAll();
			//ゲームのFPSを1000/ONE_FRAME_TIME_MSECに調整
			while ((GetNowCount() - previousFrameTime) < ONE_FRAME_TIME_MSEC) {
				Sleep(1);
			}

		}

	}
	catch (const imageLoadFailureException& exceptionInstance)
	{
		constexpr const char* errorMessage = "画像の読み込みに失敗しました。\n"
			"以下の項目を確認してください。\n"
			"* resourceフォルダの位置を変更していないか\n"
			"* resourceフォルダの中に画像ファイルが全て存在するか";

		(new showErrorToUser())->showNormalExceptionErrorDialog(exceptionInstance, errorMessage);
	}
	catch(const callUnknownEventExecuteClassException& exceptionInstance){
		(new showErrorToUser())->showNormalExceptionErrorDialog(exceptionInstance, "内部エラーが発生しました。");
	}
	catch (const setFailureEventOccurCheckClass& exceptionInstance) {
		(new showErrorToUser())->showNormalExceptionErrorDialog(exceptionInstance, "内部エラーが発生しました。");
	}
	catch (const extendException& exceptionInstance) {
		(new showErrorToUser())->showExtendExceptionErrorDialog(exceptionInstance, "想定外のエラーが発生しました。");
	}
	catch (const std::exception& exceptionInstance) {
		(new showErrorToUser())->showStdExceptionErrorDialog(exceptionInstance, "想定外のエラーが発生しました。");
	}catch (...) {
		(new showErrorToUser())->showSystemExceptionErrorDialog("想定外のエラーが発生しました。");
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

