#pragma once

//DX���C�u�����f�t�H���g�̎��ۂ̕`��X�y�[�X
constexpr int realDrawScreenWidth = 640;
constexpr int realDrawScreenHeight = 480;

//���z�`��X�y�[�X�͎��ۂ̕`��X�y�[�X�̉��{�Ƃ��邩
constexpr int realBaseVirtualRatio = 100;
constexpr double virtualBaseRealRatio = 1.0 / realBaseVirtualRatio;

//���z���W��������W�֕ϊ�
inline int convertToRealCoordinate(int virtualCoordinate) {
	return (int)(virtualCoordinate * virtualBaseRealRatio);
}


//�����W���牼�z���W�֕ϊ�
inline int convertToVirtualCoordinate(int realCoordinate) {
	return (int)(realCoordinate * realBaseVirtualRatio);
}
