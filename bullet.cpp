#include "bullet.h"
Bullet::Bullet(Image &image, float X, float Y, int W, int H, RenderWindow* i_window, float i_speed) :Entity(image, X,Y, W, H, i_window){
    speed= i_speed;
}
void Bullet::update(float time){
    if (life==true){
        dy=speed;
        y +=dy*time;
        sprite.setPosition(x,y);
        window->draw(sprite);
    }
}
IntRect Bullet::get_hitbox(){
        return sf::IntRect(x + 0.375f * BASE_SIZE, y + 0.375f * BASE_SIZE, 0.25f * BASE_SIZE, 0.25f * BASE_SIZE);
    }

