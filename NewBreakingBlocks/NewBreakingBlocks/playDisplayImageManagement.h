#pragma once
//LoadGraph関数の戻り値で-1は既に予約されているため
//-1はグラフィックハンドルの値としては存在しない。(DXライブラリ公式ドキュメント参照。)
constexpr int NULL_GRAPHICHANDLE = -1;
class playDisplayImageManagement
{
private:
	int barImageHandle = NULL_GRAPHICHANDLE;
	int blockImageHandle = NULL_GRAPHICHANDLE;
	int ballImageHandle = NULL_GRAPHICHANDLE;
public:
	playDisplayImageManagement();
	int getBarImageHandle() const;
	int getBlockImageHandle() const;
	int getBallImageHandle() const;
	virtual ~playDisplayImageManagement();
};

