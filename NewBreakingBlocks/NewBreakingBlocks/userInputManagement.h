#pragma once


//�����ɑ��ݏo����N���X��1����
class userInputManagement
{
private:
	//WARNING:���̕ϐ���DX���C�u�����̓s���㐶�|�C���^�ɂ��Ă��܂��B
	//�������[���[�N�E�͈͊O�A�N�Z�X�ɏ\�����ӂ��邱��!
	char* previousKeyStateAll_DANGERPOINTER;
	//WARNING:���̕ϐ���DX���C�u�����̓s���㐶�|�C���^�ɂ��Ă��܂��B
	//�������[���[�N�E�͈͊O�A�N�Z�X�ɏ\�����ӂ��邱��!
	char* nowKeyStateAll_DANGERPOINTER;
	int checkKeyStateAll = 0;
public:
	virtual ~userInputManagement();
	void setPreviousKeyStateAll();
	void setNowKeyStateAll();
	int isPreviousFrameNoPushAndNowFramePush(int checkHitKey);
	//int isPreviousFramePushAndNowFrameNoPush(int checkHitKey);
	int checkHitKeyAll();
	userInputManagement();

	userInputManagement(const userInputManagement&) = delete;
	userInputManagement& operator=(const userInputManagement&) = delete;
	userInputManagement(userInputManagement&&) = delete;
	userInputManagement& operator=(userInputManagement&&) = delete;
};

