#pragma once
#include<string>

class extendException
{
private:
	std::string throwExceptionFileName = "";
	int throwExceptionLineNumber = -1;

public:
	extendException();
	virtual std::string getDetailThisException() const;
	//__FILE__,__LINE__で取得したファイル名や行数を
	//ファイル名はファイル名だけ、行数は数値の型に変換して例外クラスのメンバ変数に格納する。
	//fullPathFileNameには、フルパスのファイル名が格納される。
	void setThrowExceptionPlace(std::string fullPathFileName, int fileLine);
	std::string getThrowExceptionFileName() const;
	int getThrowExceptionLineNumber() const;
	virtual std::string getExceptionTypeName() const;
	virtual ~extendException();
};

