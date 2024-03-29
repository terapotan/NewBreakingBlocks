#include "imageLoadFailureException.h"


imageLoadFailureException::imageLoadFailureException()
{
}

std::string imageLoadFailureException::getDetailThisException() const
{
	return std::string(this->loadFailureFileName + "の読み込みに失敗しました。");
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
