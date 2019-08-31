#include "paintCollisionCheckNum.h"


paintCollisionCheckNum::paintCollisionCheckNum()
{
}

void paintCollisionCheckNum::executeEventExecuteClass(managementSceneObjects& sceneObjects)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "collisionCheck:%d",1);
}


paintCollisionCheckNum::~paintCollisionCheckNum()
{
}
