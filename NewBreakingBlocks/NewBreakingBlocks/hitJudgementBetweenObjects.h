#pragma once
typedef struct rectElements {
	int rectLeftUpCoordX;
	int rectLeftUpCoordY;
	int rectWidth;
	int rectHeight;
}rectElements;


class hitJudgementBetweenObjects
{
public:
	bool hitJudgeRectAndRect(const rectElements& firstRect, const rectElements& secondRect);
	hitJudgementBetweenObjects();
	~hitJudgementBetweenObjects();
};

