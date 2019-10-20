#include "managementSceneObjects.h"
#include "extendException.h"

managementSceneObjects::managementSceneObjects()
{
	//FIXME:�ȉ��̍s�����̃N���X����ǂ��o������
	//�f�[�^�����ۂɑ}������N���X�ƁA�Ǘ�����N���X�͕ʂɂ�����
	//��������΃V�[�����ƂɎg���܂킵���o����
	this->playDisplayImageManagementInstance.reset(new playDisplayImageManagement());

	this->ballInstance.reset(new ball(0, 0, this->playDisplayImageManagementInstance));
	this->barInstance.reset(new bar(30000, 0, this->playDisplayImageManagementInstance));
	
	this->userInputManagementInstance.reset(new userInputManagement());
}



managementSceneObjects::~managementSceneObjects()
{
}
