#pragma once
//Normal:extendException���p�����A����Ɍʂ̃N���X���Ƃɗ�O��⑫���Ă���ꍇ
//Extend:extendException���̂�⑫����ӏ��ŕߑ����ꂽ�ꍇ
//Std:C++�W����O�ł���ꍇ
//System:�\������O(0���Z��)�ł���ꍇ(�\������O��Windows�ɂ������݂��Ȃ�)
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

