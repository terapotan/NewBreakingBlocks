#include "isHitBallAndBar.h"


isHitBallAndBar::isHitBallAndBar()
{
}


isHitBallAndBar::~isHitBallAndBar()
{
}

std::string isHitBallAndBar::toStringForDebug()
{
	return std::string("isHitBallAndBar");
}

std::string isHitBallAndBar::executeEventOccurCheck(managementSceneObjects& sceneObjects)
{
	std::shared_ptr<hitJudgementBetweenObjects> hitJudgeInstance = sceneObjects.hitJudgementBetweenObjectsInstance;
	std::shared_ptr<ball> ballInstance = sceneObjects.ballInstance;
	std::shared_ptr<bar> barInstance = sceneObjects.barInstance;

	//FIXME:どうにかして、この文をbarクラスかhitJudgementBetweenObjectsクラスにまとめたい。
	ballInstance->saveNowObjectStateToRectObject();
	barInstance->saveNowObjectStateToRectObject();

	if (hitJudgeInstance->hitJudgeRectAndRect(ballInstance->getRectObjectElements(), barInstance->getRectObjectElements())) {
		return std::string("paintCollisionCheckNum");
	}
	return std::string(EXECUTE_NOTHING);
}
