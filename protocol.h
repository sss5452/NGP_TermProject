#pragma once

const short SERVER_PORT = 4000;

const int  MAX_NAME_SIZE = 20;
const int  MAX_USER = 10;

const char CS_PACKET_LOGIN = 1;
const char CS_PACKET_MOVE = 2;
const char CS_MOUSE_INPUT = 3;
const char CS_CLOSE_ANIMATION = 4;
const char CS_PUT_BUTTON = 5; 

const char SC_PACKET_LOGIN_OK = 1;
const char SC_PACKET_MOVE = 2;
const char SC_PACKET_PUT_OBJECT = 3;
const char SC_PACKET_REMOVE_OBJECT = 4;
const char SC_SET_ANIMATION = 5;
const char SC_CLEAR_STAGE = 6;
const char SC_PLAYER_COLLISION = 7;


#pragma pack (push, 1)
struct cs_packet_login {
	unsigned char size;
	char	packet_type;
	char	name[MAX_NAME_SIZE];
};

struct sc_login_ok {
	unsigned char size;
	char	packet_type;
	int		id;
	short	x, y;
};


//cs
struct cs_move {
	unsigned char size;
	char packet_type;
	int type; //��,�� ���� 
};

struct cs_mouse_input{
	unsigned char size;
	char packet_type;
	float x,y;
};

struct cs_close_animation{		//�ִϸ��̼� ������ �������� �˸�. 
	unsigned char size;
	char packet_type;
	bool isDone;
};

struct cs_put_button{		//�÷��̾ ��ư�� ������ ������ �˸�. 
	unsigned char size;
	char packet_type;
	bool isPush;
};

//sc

struct sc_move {
	unsigned char size;
	char packet_type;
	float x ,y;
	int dir;
};


struct sc_put_object {
	unsigned char size;
	char packet_type;
	float x,y;
	int type;		//������ ���Դ��� �˸��� ����, Bullet �� Bullet�� ������ �ٸ����̰� Map��ġ�� �ɼ�������. 
};


struct sc_remove_object {
	unsigned char size;
	char packet_type;
	int type;
	int index;
};

struct sc_set_animation{
	unsigned char size;
	char packet_type;
	int type;			//�ִϸ��̼� Ÿ�� ���� 
	int animCount = 0;		//�ִϸ��̼� ���� ī��Ʈ �ʱ�ȭ 
	int maxCount;	//�ִϸ��̼��� �ִ� ī��Ʈ ����
 
};

struct sc_clear_stage{	//�������� ����
	unsigned char size;
	char packet_type;
	int stage;			 
}; 

struct sc_player_collision{	//���Ϳ� ���� �浹
	unsigned char size;
	char packet_type;
	
	float x,y; 				//�÷��̾� �ʱ� ��ġ��.
	
};




#pragma pack(pop)
