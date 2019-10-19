#pragma once
#include "rectObject.h"
class hitJudgementBetweenObjects
{
private:
public:
	bool hitJudgeRectAndRect(const rectElements& firstRect, const rectElements& secondRect);
	hitJudgementBetweenObjects();
	virtual ~hitJudgementBetweenObjects();

	hitJudgementBetweenObjects(const hitJudgementBetweenObjects&) = delete;
	hitJudgementBetweenObjects& operator=(const hitJudgementBetweenObjects&) = delete;
	hitJudgementBetweenObjects(hitJudgementBetweenObjects&&) = delete;
	hitJudgementBetweenObjects& operator=(hitJudgementBetweenObjects&&) = delete;
};

