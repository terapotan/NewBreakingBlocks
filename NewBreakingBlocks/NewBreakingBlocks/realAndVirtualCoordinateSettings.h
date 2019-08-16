#pragma once

//DXライブラリデフォルトの実際の描画スペース
constexpr int realDrawScreenWidth = 640;
constexpr int realDrawScreenHeight = 480;

//ユーザー(開発者)が用いる仮想的な描画スペース
constexpr int virtualDrawScreenWidth = 64000;
constexpr int virtualDrawScreenHeight = 48000;

//仮想描画スペースは実際の描画スペースの何倍か
constexpr double realBaseVirtualWidthRatio = (double)virtualDrawScreenWidth / realDrawScreenWidth;
constexpr double realBaseVirtualHeightRatio = (double)virtualDrawScreenHeight / realDrawScreenHeight;

//実際の描画スペースは仮想描画スペースの何倍か
constexpr double virtualBaseRealWidthRatio = (double)realDrawScreenWidth / virtualDrawScreenWidth;
constexpr double virtualBaseRealHeightRatio = (double)realDrawScreenHeight / virtualDrawScreenHeight;





//仮想座標から実座標へ変換
inline int convertToRealCoordinateX(int virtualCoordinateX) {
	return (int)(virtualCoordinateX * virtualBaseRealWidthRatio);
}

inline int convertToRealCoordinateY(int virtualCoordianteY) {
	return (int)(virtualCoordianteY * virtualBaseRealHeightRatio);
}


//実座標から仮想座標へ変換
inline int convertToVirtualCoordinateX(int realCoordinateX) {
	return (int)(realCoordinateX * realBaseVirtualWidthRatio);
}

inline int convertToVirtualCoordinateY(int realCoordinateY) {
	return (int)(realCoordinateY * realBaseVirtualHeightRatio);
}
