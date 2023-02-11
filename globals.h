#ifndef GLOBALS
#define GLOBALS
#include <iostream>
using namespace std;
//���� ������� ����������
//������������ ������
const string PLAYER_BULLET = "Resources/Images/PlayerBullet.png";
const string PLAYER_IMG="Resources/Images/Player.png";
const string BACKGROUND="Resources/Images/Background.png";
const string ENEMY_IMG = "Resources/Images/Enemy0.png";
const string ENEMY_BULLET="Resources/Images/EnemyBullet.png";
const string TIMES_NEW_ROMAN="Resources/TimesNewRoman.ttf";
//��������� ����
const unsigned short SCREEN_HEIGHT = 180;
const unsigned short SCREEN_WIDTH = 320;
const unsigned char SCREEN_RESIZE = 4;
//��������� ��� ������
const unsigned short BASE_SIZE=16;//������ �������(������ � ������)
const unsigned int RELOAD_TIME=200;
const unsigned int ENEMY_VALUE=5;
//��������� ������
const unsigned int MOVE_TIME=705;
const unsigned char STEP=1;
const float ENEMY_BULLET_SPEED = 0.0625;
const unsigned int ENEMY_SHOOT_RATE =255;
const unsigned char ENEMY_SPEED_INCREASE=11;
#endif // GLOBALS

