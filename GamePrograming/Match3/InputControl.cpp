#include"DxLib.h"
#include"Inputcontrol.h"

/********************************************
* �ϐ��錾
********************************************/
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/********************************************
* �v���g�^�C�v�錾
********************************************/


/********************************************
* ���͐���@�\:����������
* ����:�Ȃ�
* �߂�l:�Ȃ�
********************************************/
void Inpu_Initialize(void)
{
	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;
}

/********************************************
* ���͐���@�\:�X�V����
* ����:�Ȃ�
* �߂�l:�Ȃ�
********************************************/
void Input_Update(void)
{
	//�}�E�X���͏��̎擾
	old_button = now_button;
	now_button = GetMouseInput();

	//�}�E�X�J�[�\�����W�̎擾
	GetMousePoint(&mouse_position_x, &mouse_position_y);
}

/********************************************
* ���͐���@�\:ESC�L�[���̓`�F�b�N
* ����:�Ȃ�
* �߂�l:TRUE(���͂��ꂽ),FALSE(������)
********************************************/
int Input_Escape(void)
{
	int ret = FALSE;

	//ESC�L�[�������ꂽ�烋�[�v���甲����
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/********************************************
* ���͐���@�\:���͏��擾����(�������u��)
* ����:�w�肷��}�E�X�̃{�^��
* �߂�l:TRUE(���͂��ꂽ),FALSE(������)
********************************************/
int GetOldkey(int key)
{
	int ret = FALSE;

	if ((key & old_button) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

/********************************************
* ���͐���@�\:���͏��擾����(�����Ă���)
* ����:�w�肷��}�E�X�̃{�^��
* �߂�l:TRUE(���͂��ꂽ),FALSE(������)
********************************************/
int GetNowKey(int key)
{
	int ret = FALSE;

	if ((key & now_button) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

/********************************************
* ���͐���@�\:���͏��擾����(�������u��)
* ����:�w�肷��}�E�X�̃{�^��
* �߂�l:TRUE(���͂��ꂽ),FALSE(������)
********************************************/
int getKeyFlag(int Key)
{
	int ret = FALSE;
	int keyflg = now_button & ~old_button;

	if ((Key & keyflg) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

/********************************************
* ���͐���@�\:�}�E�X���W�擾����
* ����:�Ȃ�
* �߂�l:�}�E�X�J�[�\����X���W���
********************************************/
int GetMousePositionX(void)
{
	return mouse_position_x;
}

/********************************************
* ���͐���@�\:�}�E�X���W�擾����
* ����:�Ȃ�
* �߂�l:�}�E�X�J�[�\����Y���W���
********************************************/
int GetMousePositionY(void)
{
	return mouse_position_y;
}