#pragma once

//DXライブラリデフォルトの実際の描画スペース
constexpr int realDrawScreenWidth = 640;
constexpr int realDrawScreenHeight = 480;

//仮想描画スペースは実際の描画スペースの何倍とするか
constexpr int realBaseVirtualRatio = 100;
constexpr double virtualBaseRealRatio = 1.0 / realBaseVirtualRatio;

//仮想座標から実座標へ変換
inline int convertToRealCoordinate(int virtualCoordinate) {
	return (int)(virtualCoordinate * virtualBaseRealRatio);
}


//実座標から仮想座標へ変換
inline int convertToVirtualCoordinate(int realCoordinate) {
	return (int)(realCoordinate * realBaseVirtualRatio);
}
