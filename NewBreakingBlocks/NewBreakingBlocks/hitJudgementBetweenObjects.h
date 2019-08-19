#pragma once
#include "rectObject.h"

class hitJudgementBetweenObjects
{
public:
	bool hitJudgeRectAndRect(const rectElements& firstRect, const rectElements& secondRect);
	hitJudgementBetweenObjects();
	~hitJudgementBetweenObjects();
};

