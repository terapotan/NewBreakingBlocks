#include "extendException.h"


extendException::extendException()
{
}

std::string extendException::getDetailThisException()
{
	return std::string("��O����");
}


void extendException::setThrowExceptionPlace(std::string fullPathFileName,std::string fileLine)
{
	constexpr const char* pathSeparator = "\\";
	this->throwExceptionLineNumber = fileLine;

	decltype(fullPathFileName)::size_type fileNamePosition = fullPathFileName.rfind(pathSeparator);

	//�p�X�̋�؂�q��������Ȃ������ꍇ(�t�@�C�������n���ꂽ�ꍇ)
	if (fileNamePosition == fullPathFileName.npos) {
		this->throwExceptionFileName = fullPathFileName;
		return;
	}

	fileNamePosition++;

	this->throwExceptionFileName = fullPathFileName.substr(fileNamePosition);
}

extendException::~extendException()
{
}
