#include "bar.h"


bar::bar()
{
	//FIXME:‰æ‘œ“Ç‚Ýž‚ÝŽ¸”sŽž‚Ìˆ—‚ªŽÀ‘•‚³‚ê‚Ä‚¢‚È‚¢
	//‰æ‘œ“Ç‚Ýž‚ÝŽ¸”sŽž‚ÍimageLoadFailuereExpection—áŠO‚ð‘—o‚·‚é‚æ‚¤‚É‚µ‚È‚¯‚ê‚Î‚È‚ç‚È‚¢
	barImageHandle = LoadGraph("../.././resource/bar.png");
}


bar::~bar()
{
	DeleteGraph(barImageHandle);
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

void bar::objectPaint() {
	DrawGraph(barLeftupCoordX, barLeftupCoordY, barImageHandle,TRUE);
}