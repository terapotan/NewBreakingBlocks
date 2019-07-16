#include "bar.h"


bar::bar()
{
}


bar::~bar()
{
}

void bar::barPaint() {
	LoadGraphScreen(50, 100, "../.././resource/bar.png", TRUE);
}