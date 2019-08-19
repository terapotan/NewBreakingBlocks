#pragma once
#include "rectObject.h"
#include "playDisplayImageManagement.h"

class bar : public rectObject
{
private:
	//物体の位置や速度指定に使う座標は実際の座標ではなく
	//realAndVirtualCoordinateSettings.h内に存在する
	//virtualDrawScreenWidth,Heightの仮想座標である。
	//メンバ変数に格納されている座標の値も仮想座標である。
	//仮想座標は描画時に実座標に変換される。

	int barLeftupCoordX;
	int barLeftupCoordY;
	int barVelocityX_PerFrame;
	int barImageHandle;
	int barWidth_Pixel;
	int barHeight_Pixel;

public:
	bar(const playDisplayImageManagement& playInstance);
	bar(int barLeftupCoordX, int barLeftupCoordY, const playDisplayImageManagement& playInstance);

	void setBarCoordinate(int x, int y);
	int getBarCoordinateX();
	int getBarCoordinateY();
	int getBarWidthPixel();
	int getBarHeightPixel();

	void setBarVelocity(int ballVelocityX_PerFrame);
	void moveBarAtTheSetVelocity();

	void barPaint();

	void saveNowObjectStateToRectObject() override;

	virtual ~bar();
};

