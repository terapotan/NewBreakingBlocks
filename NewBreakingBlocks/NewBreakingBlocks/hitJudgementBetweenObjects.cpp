#include "hitJudgementBetweenObjects.h"


bool hitJudgementBetweenObjects::hitJudgeRectAndRect(const rectElements& firstRect, const rectElements& secondRect)
{
	bool firstCondition = secondRect.rectLeftUpCoordX < (firstRect.rectLeftUpCoordX + firstRect.rectWidth);
	bool secondCondition = firstRect.rectLeftUpCoordX < (secondRect.rectLeftUpCoordX + secondRect.rectWidth);
	bool thirdCondition = secondRect.rectLeftUpCoordY < (firstRect.rectLeftUpCoordY + firstRect.rectHeight);
	bool fourthCondition = firstRect.rectLeftUpCoordY < (secondRect.rectLeftUpCoordY + secondRect.rectHeight);

	if (firstCondition && secondCondition && thirdCondition && fourthCondition) {
		return true;
	}
	else {
		return false;
	}

}

hitJudgementBetweenObjects::hitJudgementBetweenObjects()
{
}


hitJudgementBetweenObjects::~hitJudgementBetweenObjects()
{
}
