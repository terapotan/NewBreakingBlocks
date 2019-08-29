#pragma once
#include<string>

class extendException
{
private:
	std::string throwExceptionFileName = "";
	int throwExceptionLineNumber = -1;

public:
	extendException();
	virtual std::string getDetailThisException() = 0;
	//__FILE__,__LINE__�Ŏ擾�����t�@�C������s����
	//�t�@�C�����̓t�@�C���������A�s���͐��l�̌^�ɕϊ����ė�O�N���X�̃����o�ϐ��Ɋi�[����B
	//fullPathFileName�ɂ́A�t���p�X�̃t�@�C�������i�[�����B
	void setThrowExceptionPlace(std::string fullPathFileName, int fileLine);
	virtual ~extendException();
};

