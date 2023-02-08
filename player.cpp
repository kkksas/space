#include "player.h"
Player::Player(Image &image, float X, float Y, int W, int H, RenderWindow* i_window, list<Bullet*>* enemy_bul) :Entity(image, X, Y, W, H, i_window),enemy_bullets(enemy_bul){
    
}
Player::~Player(){
    
}
void Player::control(){
    
}
void Player::reset(bool win){
    
}
void Player::die(){
    
}
void Player::update(float time) //метод "оживлени¤/обновления" объекта класса.
{

}
list<Bullet*>* Player::get_player_bullet_list(){
    
}
IntRect Player::get_hitbox()
{
    
}
bool Player::is_alive(){
    
}
string Player::get_score(){
    
}
void Player::set_score(unsigned int sc){
    
}