#include "player.h"
Player::Player(Image &image, float X, float Y, int W, int H, RenderWindow* i_window, list<Bullet*>* enemy_bul) :Entity(image, X,
Y, W, H, i_window),enemy_bullets(enemy_bul){
    score=0;
    bullet_list.clear();
    state = stay;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    bullet_img.loadFromFile("Resources/Images/PlayerBullet.png");

}
Player::~Player(){
    while(!bullet_list.empty()){
        iter= bullet_list.begin();
        bullet_list.erase(iter);
    }
}
void Player::control(){
    
}
void Player::reset(bool win){
    x=0;
    y=SCREEN_HEIGHT-BASE_SIZE-1;
    if (!win){
        score=0;
        life=true;
    }
    while(!bullet_list.empty()){
        iter= bullet_list.begin();
        bullet_list.erase(iter);
    }
}
void Player::die(){
    life=false;
}
void Player::update(float time) //метод "оживлени¤/обновлени¤" объекта класса.
{

}
}
list<Bullet*>* Player::get_player_bullet_list(){
    return &bullet_list;
}
IntRect Player::get_hitbox()
{
    return IntRect(x + 0.125f * BASE_SIZE, y + 0.125f * BASE_SIZE, 0.75f * BASE_SIZE, 0.75f * BASE_SIZE);
}
bool Player::is_alive(){
    return life;
}
string Player::get_score(){
    string str = to_string(score);
    return str;
}
void Player::set_score(unsigned int sc){
    score=sc;
}