#pragma once
#include "rectObject.h"
#include "playDisplayImageManagement.h"

class ball : public rectObject
{
private:
	//物体の位置や速度指定に使う座標は実際の座標ではなく
	//realAndVirtualCoordinateSettings.h内に存在する
	//virtualDrawScreenWidth,Heightの仮想座標である。
	//メンバ変数に格納されている座標の値も仮想座標である。
	//仮想座標は描画時に実座標に変換される。
	//画像の大きさ等の数値も仮想座標である


	int ballLeftupCoordX;//画面右方向を正とする
	int ballLeftupCoordY;//画面下方向を正とする
	int ballVelocityX_PerFrame;//画面右方向を正とする
	int ballVelocityY_PerFrame;//画面下方向を正とする
	int ballDiamater_Pixel;
	int ballImageHandle;
public:
	ball(const playDisplayImageManagement& playInstance);
	ball(int ballLeftupCoordX, int ballLeftupCoordY, const playDisplayImageManagement& playInstance);
	void setBallCoordinate(int x, int y);
	int getBallCoordinateX();
	int getBallCoordinateY();
	int getBallDiamaterPixel();

	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	void moveBallAtTheSetVelocity();

	void ballPaint();

	void saveNowObjectStateToRectObject() override;
	virtual ~ball();
};

