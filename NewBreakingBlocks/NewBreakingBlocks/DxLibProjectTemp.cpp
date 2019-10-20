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
#include "DxLibProjectTemp.h"
#include "shouldBarMoveCheck.h"
#include "isHitBallAndBar.h"
#include "setVelocityBarLeft.h"
#include "setVelocityBarRight.h"
#include "setVelocityBarNoMove.h"
#include "paintCollisionCheckNum.h"
#include <string>


//FIXME:現状DxLibProjectTempには様々な責務が存在する
//sceneクラスか何かを作って責務を分担させる必要があるだろう

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
		auto& eventOccurCheckClassList = eventInstance.getEventOccurCheckClassList();
		auto& eventExecuteClassMap = eventInstance.getEventExecuteClassMap();

		eventOccurCheckClassList.push_back(std::unique_ptr<shouldBarMoveCheck>(new shouldBarMoveCheck()));
		eventOccurCheckClassList.push_back(std::unique_ptr<isHitBallAndBar>(new isHitBallAndBar()));

		eventExecuteClassMap.insert(std::make_pair(std::string("setVelocityBarLeft"), std::unique_ptr<setVelocityBarLeft>(new setVelocityBarLeft())));
		eventExecuteClassMap.insert(std::make_pair(std::string("setVelocityBarRight"), std::unique_ptr<setVelocityBarRight>(new setVelocityBarRight())));
		eventExecuteClassMap.insert(std::make_pair(std::string("setVelocityBarNoMove"), std::unique_ptr<setVelocityBarNoMove>(new setVelocityBarNoMove())));
		eventExecuteClassMap.insert(std::make_pair(std::string("paintCollisionCheckNum"), std::unique_ptr<paintCollisionCheckNum>(new paintCollisionCheckNum())));

		std::shared_ptr<userInputManagement> inputInstance = sceneObjects.userInputManagementInstance;

		ballInstance->setBallVelocity(1, 0);
		barInstance->setBarVelocity(50);


		inputInstance->setPreviousKeyStateAll();

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			unsigned int previousFrameTime = GetNowCount();
			inputInstance->setNowKeyStateAll();

			//FIXME:eventOccurCheckAndExecuteクラスを
			//eventOccurCheckとeventExecuteクラスに分割したほうがいいのでは?
			//そして、executeOccurCheckClassesからイベントチェックリストが返されて
			//それを受け取ったexecuteEventExecuteClassesがイベントを実行する
			eventInstance.executeOccurCheckClasses(sceneObjects);
			eventInstance.executeEventExecuteClasses(sceneObjects);

			ballInstance->ballPaint();
			barInstance->barPaint();
			
			inputInstance->setPreviousKeyStateAll();
			//ゲームのFPSを1000/ONE_FRAME_TIME_MSECに調整


			while ((GetNowCount() - previousFrameTime) < ONE_FRAME_TIME_MSEC) {
				Sleep(1);
			}

			unsigned int nowFrameTime = GetNowCount();
			unsigned int Color;

			Color = GetColor(255, 255, 255);
			DrawFormatString(0, 0, Color, "ONE_FRAME_TIME_MSEC:%d", nowFrameTime - previousFrameTime);

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

