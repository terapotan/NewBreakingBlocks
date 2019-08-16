#pragma once

//DX���C�u�����f�t�H���g�̎��ۂ̕`��X�y�[�X
constexpr int realDrawScreenWidth = 640;
constexpr int realDrawScreenHeight = 480;

//���[�U�[(�J����)���p���鉼�z�I�ȕ`��X�y�[�X
constexpr int virtualDrawScreenWidth = 64000;
constexpr int virtualDrawScreenHeight = 48000;

//���z�`��X�y�[�X�͎��ۂ̕`��X�y�[�X�̉��{��
constexpr double realBaseVirtualWidthRatio = (double)virtualDrawScreenWidth / realDrawScreenWidth;
constexpr double realBaseVirtualHeightRatio = (double)virtualDrawScreenHeight / realDrawScreenHeight;

//���ۂ̕`��X�y�[�X�͉��z�`��X�y�[�X�̉��{��
constexpr double virtualBaseRealWidthRatio = (double)realDrawScreenWidth / virtualDrawScreenWidth;
constexpr double virtualBaseRealHeightRatio = (double)realDrawScreenHeight / virtualDrawScreenHeight;





//���z���W��������W�֕ϊ�
inline int convertToRealCoordinateX(int virtualCoordinateX) {
	return (int)(virtualCoordinateX * virtualBaseRealWidthRatio);
}

inline int convertToRealCoordinateY(int virtualCoordianteY) {
	return (int)(virtualCoordianteY * virtualBaseRealHeightRatio);
}


//�����W���牼�z���W�֕ϊ�
inline int convertToVirtualCoordinateX(int realCoordinateX) {
	return (int)(realCoordinateX * realBaseVirtualWidthRatio);
}

inline int convertToVirtualCoordinateY(int realCoordinateY) {
	return (int)(realCoordinateY * realBaseVirtualHeightRatio);
}
