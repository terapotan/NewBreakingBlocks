#include "showErrorToUser.h"


showErrorToUser::showErrorToUser()
{
}

void showErrorToUser::showNormalExceptionErrorDialog()
{
	constexpr const char* errorMessage = "�摜�̓ǂݍ��݂Ɏ��s���܂����B\n"
		"�ȉ��̍��ڂ��m�F���Ă��������B\n"
		"* resource�t�H���_�̈ʒu��ύX���Ă��Ȃ���\n"
		"* resource�t�H���_�̒��ɉ摜�t�@�C�����S�đ��݂��邩\n"
		"\n"
		"�ȏ�̍��ڂ������A�R���s���[�^�[�E�{�\�t�g�E�F�A�̍ċN���������Ă��G���[���Ĕ�����ꍇ\n"
		"�ȉ��̘A���悩��J���҂ɂ��̃G���[�_�C�A���O�̓��e�ƂƂ��ɂ��A�����������B\n"
		"���̃G���[�_�C�A���O���A�N�e�B�u(�_�C�A���O���N���b�N����)�ɂ�����Ԃ�\n"
		"Ctrl+C(Ctrl�L�[��C�L�[�𓯎�����)����ƁA�_�C�A���O�̓��e���R�s�[���邱�Ƃ��o���܂��B\n"
		"\n"
		"Twitter:https://twitter.com/terapotan\n"
		"���[���A�h���X:gameblog60@gmail.com\n\n"
		"===�J���Ҍ����G���[���O===\n"
		"��O�̌^:imageLoadFailueException\n"
		"�ڍׂȃG���[���e:ball.png�̓ǂݍ��݂Ɏ��s���܂����B\n"
		"�G���[�����������ꏊ:playDisplayImageManagement.cpp xx�s��\n"
		"�A�v���P�[�V������:BreakingBlocks\n"
		"�A�v���P�[�V�����o�[�W����:prealpha6.1\n"
		"�g�pOS:Windows10\n"
		"DX���C�u�����o�[�W����(3.02f)\n"
		"===�J���Ҍ����̑Ώ����@===\n"
		"* exe�t�@�C����2�K�w���1�K�w����resource�t�H���_�����݂��邱��\n"
		"* �p�X�̋�؂莚���Ԉ���Ă��Ȃ�����\n"
		"* �ǂݍ��ݎ��s�����t�@�C�������݂��邱�ƁA�j�����Ă��Ȃ�����"
		"���m�F���Ă��������B\n";

	MessageBox(NULL,
		TEXT(errorMessage),
		TEXT("�G���["),
		MB_OK | MB_ICONERROR);
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

showErrorToUser::~showErrorToUser()
{
}
