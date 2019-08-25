#include "extendException.h"


extendException::extendException()
{
}

std::string extendException::getDetailThisException()
{
	return std::string("例外発生");
}


void extendException::setThrowExceptionPlace(std::string fullPathFileName,std::string fileLine)
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

extendException::~extendException()
{
}
