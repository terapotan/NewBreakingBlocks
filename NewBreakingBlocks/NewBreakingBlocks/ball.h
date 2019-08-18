#pragma once
#include "rectObject.h"
class ball : public rectObject
{
private:
	//物体の位置や速度指定に使う座標は実際の座標ではなく
	//realAndVirtualCoordinateSettings.h内に存在する
	//virtualDrawScreenWidth,Heightの仮想座標である。
	//メンバ変数に格納されている座標の値も仮想座標である。
	//仮想座標は描画時に実座標に変換される。

	//FIXME:仮想座標だとわかるように変数の名前を変更したほうがいい

	int ballLeftupCoordX;//画面右方向を正とする
	int ballLeftupCoordY;//画面下方向を正とする
	int ballVelocityX_PerFrame;//画面右方向を正とする
	int ballVelocityY_PerFrame;//画面下方向を正とする
	int ballDiamater_Pixel;
	int ballImageHandle;
public:
	ball();
	ball(int ballLeftupCoordX, int ballLeftupCoordY);
	void setBallCoordinate(int x, int y);
	int getBallCoordinateX();
	int getBallCoordinateY();
	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	int getBallDiamaterPixel();
	void moveBallAtTheSetVelocity();
	void ballPaint();
	virtual ~ball();
};

