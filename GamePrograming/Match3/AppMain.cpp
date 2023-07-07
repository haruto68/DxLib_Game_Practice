#include"Dxlib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nShowCmd)
{
	//ウィドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//入力待機
	WaitKey();

	//Dxライブラリ使用の終了処理
	DxLib_End();

	return 0;
}