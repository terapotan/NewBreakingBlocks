# _GetSystemInfo関数について
DXライブラリでは、システム情報を取得する関数として``_GetSystemInfo``関数が用意されている。  
公式ドキュメントには存在しないが、ここでこの関数について解説する。  
## ソースコード
DXライブラリバージョン3.20f時点では次のように実装されていた。
~~~c++
// ＤＸライブラリと DirectX のバージョンと Windows のバージョンを得る
extern int NS__GetSystemInfo( int *DxLibVer, int *DirectXVer, int *WindowsVer )
{
	if( DxLibVer ) *DxLibVer = DXLIB_VERSION ;
	if( DirectXVer ) *DirectXVer = WinData.DirectXVersion ;
	if( WindowsVer ) *WindowsVer = WinData.WindowsVersion ;

	// 終了
	return 0 ;
}
~~~
``NS__GetSystemInfo``は``#define``によって、``_GetSystemInfo``に置換される。  
また、``DXLIB_VERSION``はその名の通りDXライブラリのバージョンを示しており、バージョン3.20f時点では``0x320f``に置換される。  
WinData.DirectXVersion,WinData.WindowsVersionはそれぞれDirectX,Windowsのバージョンを表す。  
## NULLチェック
ソースコードを見る限り、NULLチェックが行われておりNULLであるときは、代入操作を行わないようになっている。  
## DXライブラリバージョン
DXライブラリのバージョンは``X.YY.Z``のような形式になっている。この形式をつなげた``XYYZ``を16進表記にした``0xXYYZ``が内部のバージョンとして使用されているようである。  
## Windows,DirectXバージョン
関数から帰ってくる数値とバージョンの関係は以下の通り。(バージョン3.02f時点での実装)  

~~~c++
// ＷＩＮＤＯＷＳのバージョンマクロ
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_8							(0x10A)
#define DX_WINDOWSVERSION_8_1						(0x10B)
#define DX_WINDOWSVERSION_10						(0x10C)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// DirectXのバージョン
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)
~~~