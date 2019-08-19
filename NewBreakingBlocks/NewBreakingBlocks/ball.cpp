#include "ball.h"
#include "imageLoadFailureExpection.h"
#include "realAndVirtualCoordinateSettings.h"

ball::ball(const playDisplayImageManagement& playInstance)
{
	//ƒ{[ƒ‹‚Ì‰æ‘œ‚Æ‚µ‚Ä“Ç‚Ýž‚Þ‰æ‘œ‚ÍˆÈ‰º‚Ì—vŒ‚ð–ž‚½‚µ‚Ä‚¢‚é•K—v‚ª‚ ‚è‚Ü‚·
	//1:‰æ‘œ‚Ìc•‚Æ‰¡•‚ª“¯‚¶’l‚Å‚ ‚è“Ç‚Ýž‚Þ‰æ‘œ‚É•`‰æ‚³‚ê‚Ä‚¢‚é}Œ`‚ª‰~‚Å‚ ‚é‚±‚Æ
	//2:PNGŒ`Ž®‚Ì‰æ‘œ‚Å‚ ‚é‚±‚Æ
	//3:‰~‚Ì’¼Œa‚ª‰æ‘œ‚Ì‰¡•(‚à‚µ‚­‚Íc•)‚Éˆê’v‚µ‚Ä‚¢‚é‚±‚Æ
	//2‚ª–ž‚½‚³‚ê‚È‚¢‚Æ‰æ‘œ‚Ì“§‰ßˆ—‚ªs‚í‚ê‚È‚¢‰Â”\«‚ª‚ ‚è‚Ü‚·
	//1‚Æ3‚ª–ž‚½‚³‚ê‚È‚¢‚Æ“–‚½‚è”»’èˆ—‚ª³‚µ‚­s‚í‚ê‚È‚¢‰Â”\«‚ª‚ ‚è‚Ü‚·


	this->ballImageHandle = playInstance.getBallImageHandle();

	int ballImageSizeX, ballImageSizeY;
	GetGraphSize(ballImageHandle, &ballImageSizeX, &ballImageSizeY);

	ballDiamater_Pixel = convertToVirtualCoordinate(ballImageSizeX);
}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY, const playDisplayImageManagement& playInstance) : ball(playInstance){
	this->setBallCoordinate(ballLeftupCoordX, ballLeftupCoordY);
	this->ballImageHandle = playInstance.getBallImageHandle();
}

void ball::saveNowObjectStateToRectObject()
{
	this->rectObjectElements.rectLeftUpCoordX = this->ballLeftupCoordX;
	this->rectObjectElements.rectLeftUpCoordY = this->ballLeftupCoordY;
	this->rectObjectElements.rectWidth = this->ballDiamater_Pixel;
	this->rectObjectElements.rectHeight = this->ballDiamater_Pixel;
}

ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setBallCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

int ball::getBallCoordinateX()
{
	return this->ballLeftupCoordX;
}

int ball::getBallCoordinateY()
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


void ball::ballPaint() {
	DrawGraph(convertToRealCoordinate(ballLeftupCoordX), 
		convertToRealCoordinate(ballLeftupCoordY), ballImageHandle, TRUE);
}