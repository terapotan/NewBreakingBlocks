#include "ball.h"
#include "imageLoadFailureExpection.h"

ball::ball()
{
	//ƒ{[ƒ‹‚Ì‰æ‘œ‚Æ‚µ‚Ä“Ç‚Ýž‚Þ‰æ‘œ‚ÍˆÈ‰º‚Ì—vŒ‚ð–ž‚½‚µ‚Ä‚¢‚é•K—v‚ª‚ ‚è‚Ü‚·
	//1:‰æ‘œ‚Ìc•‚Æ‰¡•‚ª“¯‚¶’l‚Å‚ ‚è“Ç‚Ýž‚Þ‰æ‘œ‚É•`‰æ‚³‚ê‚Ä‚¢‚é}Œ`‚ª‰~‚Å‚ ‚é‚±‚Æ
	//2:PNGŒ`Ž®‚Ì‰æ‘œ‚Å‚ ‚é‚±‚Æ
	//3:‰~‚Ì’¼Œa‚ª‰æ‘œ‚Ì‰¡•(‚à‚µ‚­‚Íc•)‚Éˆê’v‚µ‚Ä‚¢‚é‚±‚Æ
	//2‚ª–ž‚½‚³‚ê‚È‚¢‚Æ‰æ‘œ‚Ì“§‰ßˆ—‚ªs‚í‚ê‚È‚¢‰Â”\«‚ª‚ ‚è‚Ü‚·
	//1‚Æ3‚ª–ž‚½‚³‚ê‚È‚¢‚Æ“–‚½‚è”»’èˆ—‚ª³‚µ‚­s‚í‚ê‚È‚¢‰Â”\«‚ª‚ ‚è‚Ü‚·

	ballImageHandle = LoadGraph("../.././resource/ball.png");

	if (ballImageHandle == -1) {
		imageLoadFailureExpection imageLoadInstance;
		throw imageLoadInstance;
	}


	
	int ballImageSizeX, ballImageSizeY;
	GetGraphSize(ballImageHandle, &ballImageSizeX, &ballImageSizeY);

	ballDiamater_Pixel = ballImageSizeX;

}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY) : ball()
{
	this->setObjectCoordinate(ballLeftupCoordX, ballLeftupCoordY);
}


ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

int ball::getObjectCoordinateX()
{
	return this->ballLeftupCoordX;
}

int ball::getObjectCoordinateY()
{
	return this->ballLeftupCoordY;
}

void ball::setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame)
{
	this->ballVelocityX_PerFrame = ballVelocityX_PerFrame;
	this->ballVelocityY_PerFrame = ballVelocityY_PerFrame;
}

int ball::getBallDiamaterPixel()
{
	return this->ballDiamater_Pixel;
}

void ball::moveBallAtTheSetVelocity()
{
	this->ballLeftupCoordX += this->ballVelocityX_PerFrame;
	this->ballLeftupCoordY += this->ballVelocityY_PerFrame;
}


void ball::objectPaint() {
	DrawGraph(ballLeftupCoordX, ballLeftupCoordY, ballImageHandle, TRUE);
}