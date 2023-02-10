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
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if(!(x+BASE_SIZE/2<0)){
        state = left;
        speed = 0.1;}
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) ) {
        if(!(x+BASE_SIZE/2>SCREEN_WIDTH)){
            state = right;
            speed = 0.1;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (reload_timer.getElapsedTime().asMilliseconds() > RELOAD_TIME){
            Bullet* tmp_bullet= new Bullet(bullet_img,x,y-BASE_SIZE,BASE_SIZE,BASE_SIZE,window,-0.2);
            bullet_list.push_back(tmp_bullet);
            reload_timer.restart();
        }
    }
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
if (life) {//провер¤ем, жив ли герой
    control();//функци¤ управлени¤ персонажем
    switch (state)//делаютс¤ различные действи¤ в зависимости от состо¤ни¤
    {
    case right:{
        dx = speed;
        break;
    }
    case left:{
        dx = -speed;
        break;
    }
    case stay:{//стоим
        dy = speed;
        dx = speed;
        break;
    }
    }
    x += dx*time; //движение по УXФ
    speed = 0; //обнул¤ем скорость, чтобы персонаж остановилс¤..
    sprite.setPosition(x, y);
    window->draw(sprite);
    iter = bullet_list.begin();
    while (iter != bullet_list.end()){
        (*iter)->update(time);
        if((*iter)->get_y()<-BASE_SIZE || (*iter)->get_life()==false){
            if ((*iter)->get_life()==false)
                score+=ENEMY_VALUE;
            bullet_list.erase(iter);
        }
        *iter++;
    }
    for (iter=enemy_bullets->begin();iter!=enemy_bullets->end();iter++){
        if (get_hitbox().intersects((*iter)->get_hitbox())){
            die();
        }
    }
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
