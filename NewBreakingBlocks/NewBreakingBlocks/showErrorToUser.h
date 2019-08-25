#pragma once
//Normal:extendExceptionを継承し、さらに個別のクラスごとに例外を補足している場合
//Extend:extendException自体を補足する箇所で捕捉された場合
//Std:C++標準例外である場合
//System:構造化例外(0除算等)である場合(構造化例外はWindowsにしか存在しない)
class showErrorToUser
{
public:
	showErrorToUser();
	void showNormalExceptionErrorDialog();
	void showExtendExceptionErrorDialog();
	void showStdExceptionErrorDialog();
	void showSystemExceptionErrorDialog();
	virtual ~showErrorToUser();
};

