#include"GameClearScene.h"
#include"DxLib.h"
#include"SceneManager.h"

/********************************************
* �}�N����`
********************************************/


/********************************************
* �^��`
********************************************/


/********************************************
* �ϐ��錾
********************************************/
int GameClearImage;
int GameClearSE;
int GameClearFlag;

/********************************************
* �v���g�^�C�v�錾
********************************************/


/********************************************
* �Q�[���N���A���:����������
* ����:�Ȃ�
* �߂�l:�G���[���
********************************************/
int GameClearScene_Initialize(void)
{
	int ret = 0;

	//�摜�̓Ǎ���
	GameClearImage = LoadGraph("images/gameclear.png");
	//�����̓Ǎ���
	GameClearSE = LoadSoundMem("sounds/���x���A�b�v.mp3");

	GameClearFlag = 0;

	//�G���[�`�F�b�N
	if (GameClearImage == -1)
	{
		ret = -1;
	}
	if (GameClearSE == -1)
	{
		ret = -1;
	}

	return ret;
}

/********************************************
* �Q�[���N���A���:�X�V����
* ����:�Ȃ�
* �߂�l:�Ȃ�
********************************************/
void GameClearScene_Update(void)
{
	//�Q�[���N���A���ʉ��Đ��`�F�b�N
	if (CheckSoundMem(GameClearSE) == 0)
	{
		if (GameClearFlag == TRUE)
		{
			Change_Scene(E_GAMEMAIN);
		}
		else
		{
			PlaySoundMem(GameClearSE, DX_PLAYTYPE_BACK);
			GameClearFlag = TRUE;
		}
	}
}

/********************************************
* �Q�[���N���A���:�`�揈��
* ����:�Ȃ�
* �߂�l:�Ȃ�
********************************************/
void GameClearScene_Draw(void)
{
	DrawGraph(0, 0, GameClearImage, FALSE);
}