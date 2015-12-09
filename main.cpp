#include <DxLib.h>
#include "Model.h"
#include "SceneMgr.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);
	Model m("R-9A2.pmd");
	//(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
	SceneMgr sceneMgr;
	sceneMgr.Init();
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !GetHitKeyStateAll(Key) && !Key[KEY_INPUT_ESCAPE]){
		m.Draw();
		sceneMgr.Update();
		sceneMgr.Draw();
	}

	sceneMgr.Final();
	DxLib_End();
	return 0;
}