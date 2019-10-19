#pragma once


//同時に存在出来るクラスは1つだけ
class userInputManagement
{
private:
	//WARNING:この変数はDXライブラリの都合上生ポインタにしています。
	//メモリーリーク・範囲外アクセスに十分注意すること!
	char* previousKeyStateAll_DANGERPOINTER;
	//WARNING:この変数はDXライブラリの都合上生ポインタにしています。
	//メモリーリーク・範囲外アクセスに十分注意すること!
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

