#include "extendException.h"


extendException::extendException()
{
}

std::string extendException::getDetailThisException() const
{
	return std::string("何らかのユーザー定義例外が発生しました。");
}


void extendException::setThrowExceptionPlace(std::string fullPathFileName,int fileLine)
{
	constexpr const char* pathSeparator = "\\";
	this->throwExceptionLineNumber = fileLine;

	decltype(fullPathFileName)::size_type fileNamePosition = fullPathFileName.rfind(pathSeparator);

	//パスの区切り子が見つからなかった場合(ファイル名が渡された場合)
	if (fileNamePosition == fullPathFileName.npos) {
		this->throwExceptionFileName = fullPathFileName;
		return;
	}

	fileNamePosition++;

	this->throwExceptionFileName = fullPathFileName.substr(fileNamePosition);
}

std::string extendException::getThrowExceptionFileName() const
{
	return this->throwExceptionFileName;
}

int extendException::getThrowExceptionLineNumber() const
{
	return this->throwExceptionLineNumber;
}

std::string extendException::getExceptionTypeName() const
{
	return std::string("extendException");
}

extendException::~extendException()
{
}
