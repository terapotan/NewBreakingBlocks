#include "showErrorToUser.h"
#include "softwareInfomation.h"


showErrorToUser::showErrorToUser()
{
}

void showErrorToUser::showNormalExceptionErrorDialog()
{
	showOnErrorDialogInfomation errorInformation;
	softwareInfomation softInfo;


	//���[�U�����G���[���b�Z�[�W
	errorInformation.messageShowForUser			= "�摜�̓ǂݍ��݂Ɏ��s���܂����B\n"
								   				"�ȉ��̍��ڂ��m�F���Ă��������B\n"
								   				"* resource�t�H���_�̈ʒu��ύX���Ă��Ȃ���\n"
								   				"* resource�t�H���_�̒��ɉ摜�t�@�C�����S�đ��݂��邩";
	errorInformation.developerTwitterAddress	= softInfo.getDeveloperTwitterAddress();
	errorInformation.developerMailAddress		= softInfo.getDeveloperMailAddress();

	//�J���Ҍ����G���[���b�Z�[�W
	errorInformation.exceptionTypeName			= "imageLoadFailureException";
	errorInformation.exceptionDetail			= "ball.png�̓ǂݍ��݂Ɏ��s���܂����B";
	errorInformation.exceptionOccurPlaceFile	= "playDisplayImageManagement.cpp";
	errorInformation.exceptionOccurPlaceLine	= 10;
	errorInformation.nowRunSoftwareName			= softInfo.getNowRunSoftwareName();
	errorInformation.nowRunsoftwareVersion		= softInfo.getNowRunSoftwareVersion();
	errorInformation.useOS						= softInfo.getWindowsOSVersion();
	errorInformation.dxLibraryVersion			= softInfo.getDxLibraryVersion();
	errorInformation.messageShowForDeveloper	= "* exe�t�@�C����2�K�w���1�K�w����resource�t�H���_�����݂��邱��\n"
												  "* �p�X�̋�؂莚���Ԉ���Ă��Ȃ�����\n"
												  "* �ǂݍ��ݎ��s�����t�@�C�������݂��邱�ƁA�j�����Ă��Ȃ�����"
												  "���m�F���Ă��������B";
											
	this->showErrorDialog(errorInformation);
}

void showErrorToUser::showExtendExceptionErrorDialog()
{
}

void showErrorToUser::showStdExceptionErrorDialog()
{
}


void showErrorToUser::showSystemExceptionErrorDialog()
{
}

void showErrorToUser::showErrorDialog(const showOnErrorDialogInfomation & errorInfomation)
{
	std::string errorMessageOnErrorDialog = "";

	//���[�U�[�����G���[���b�Z�[�W
	errorMessageOnErrorDialog += errorInfomation.messageShowForUser;
	errorMessageOnErrorDialog += "\n\n";
	errorMessageOnErrorDialog += "�ȏ�̍��ڂ������A�R���s���[�^�[�E�{�\�t�g�E�F�A�̍ċN���������Ă��G���[���Ĕ�����ꍇ\n"
								"�ȉ��̘A���悩��J���҂ɂ��̃G���[�_�C�A���O�̓��e�ƂƂ��ɂ��A�����������B\n"
								"���̃G���[�_�C�A���O���A�N�e�B�u(�_�C�A���O���N���b�N����)�ɂ�����Ԃ�\n"
								"Ctrl+C(Ctrl�L�[��C�L�[�𓯎�����)����ƁA�_�C�A���O�̓��e���R�s�[���邱�Ƃ��o���܂��B";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += "���̃\�t�g�̓G���[�_�C�A���O�����Ǝ����I�ɏI�����܂��B";
	errorMessageOnErrorDialog += "\n\n";
	errorMessageOnErrorDialog += ("Twitter:" + errorInfomation.developerTwitterAddress);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("���[���A�h���X:" + errorInfomation.developerMailAddress);
	errorMessageOnErrorDialog += "\n\n";

	//�J���Ҍ����G���[���b�Z�[�W
	errorMessageOnErrorDialog += "===�J���Ҍ����G���[���O===";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("��O�̌^:" + errorInfomation.exceptionTypeName);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("�ڍׂȃG���[���e:" + errorInfomation.exceptionDetail);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("�G���[�����������ꏊ:" + errorInfomation.exceptionOccurPlaceFile + " " + std::to_string(errorInfomation.exceptionOccurPlaceLine) + "�s��");
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("�A�v���P�[�V������:" + errorInfomation.nowRunSoftwareName);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("�A�v���P�[�V�����o�[�W����:" + errorInfomation.nowRunsoftwareVersion);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("�g�pOS:" + errorInfomation.useOS);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += ("DX���C�u�����o�[�W����:" + errorInfomation.dxLibraryVersion);
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += "===�J���Ҍ����̑Ώ����@===";
	errorMessageOnErrorDialog += "\n";
	errorMessageOnErrorDialog += errorInfomation.messageShowForDeveloper;


	MessageBox(NULL,
		TEXT(errorMessageOnErrorDialog.c_str()),
		TEXT("�v���I�ȃG���["),
		MB_OK | MB_ICONERROR);
}

showErrorToUser::~showErrorToUser()
{
}
