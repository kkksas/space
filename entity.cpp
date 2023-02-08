#include "entity.h"
Entity::Entity(Image &image, float X, float Y, int W, int H, RenderWindow* i_window){
    x = X; y = Y; //���������� ��������� �������
    w = W; h = H;
    window = i_window;
    dx = 0; dy = 0;
    speed = 0;
    life = true; //���������������� ���������� ���������� �����, ����� ���
    texture.loadFromImage(image); //������� ���� ����������� � ��������
    sprite.setTexture(texture); //�������� ������ ���������
}
float Entity::get_x(){
    return x;
}
float Entity::get_y(){
    return y;
}
void Entity::set_y(float tmp_y){
    y=tmp_y;
}
void Entity::set_x(float tmp_x){
    x=tmp_x;
}
void Entity::set_current_frame(int cur_frame){
    CurrentFrame = cur_frame;
}
int Entity::get_current_frame(){
    return CurrentFrame;
}
void Entity::set_speed(float v){
    speed=v;
}
void Entity::set_life(bool tmp_life){
    life = tmp_life;
}
bool Entity::get_life(){
    return life;
}
