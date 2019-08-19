#pragma once
//矩形のオブジェクトが持っているべき要素・機能をここで定義する。
//要するにrectObjectはインタフェースということである。
//FIXME:実装強制させたい関数をこのクラスに書き、
//これをbar,ballクラスに継承させること
typedef struct rectElements {
	int rectLeftUpCoordX;
	int rectLeftUpCoordY;
	int rectWidth;
	int rectHeight;
}rectElements;

class rectObject
{
protected:
	rectElements rectObjectElements;
public:
	//矩形オブジェクトの値にアクセスする前に
	//この関数を呼び出すこと
	virtual void saveNowObjectStateToRectObject() = 0;
	const rectElements& getRectObjectElements();
	rectObject();
	~rectObject();
};

