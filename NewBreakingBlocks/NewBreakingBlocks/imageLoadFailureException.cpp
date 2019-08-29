#include "imageLoadFailureException.h"


imageLoadFailureException::imageLoadFailureException()
{
}

std::string imageLoadFailureException::getDetailThisException() const
{
	return std::string(this->loadFailureFileName + "�̓ǂݍ��݂Ɏ��s���܂����B");
}

std::string imageLoadFailureException::getExceptionTypeName() const
{
	return std::string("imageLoadFailureException");
}

void imageLoadFailureException::setLoadFailureFileName(std::string failureFileName)
{
	this->loadFailureFileName = failureFileName;
}


imageLoadFailureException::~imageLoadFailureException()
{
}
