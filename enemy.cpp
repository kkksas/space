#include"enemy.h"
Enemy::Enemy(Image &image, float X, float Y, int W, int H, RenderWindow* i_window) :Entity(image, X,
Y, W, H, i_window){
    sprite.setTextureRect(IntRect(CurrentFrame*w,0,w,h));
    state = right;
    sprite.setPosition(x, y);
    window->draw(sprite);
    set_speed(STEP);
}
void Enemy::change_frame(){
    if(CurrentFrame==0){
        set_current_frame(1);
    }else{
        set_current_frame(0);
    }
}

bool Enemy::move(int dir){
    change_frame();
    bool return_value=0;
    if (state==right){
        return_value = (x + BASE_SIZE + STEP >= SCREEN_WIDTH);

    }else{
        return_value= (x - STEP <=0);
    }
    x+=speed*state*dir;
    return return_value;
}

void Enemy::update(float time){
    sprite.setTextureRect(IntRect(CurrentFrame*w,0,w,h));
    sprite.setPosition(x, y);
    window->draw(sprite);
}
void Enemy::move_down(){
    if (state==left){
        state = right;
    }else{
        state = left;
    }
    y+=BASE_SIZE;
}
