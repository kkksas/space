#include "enemies.h"
Enemies::~Enemies(){
    while(!enemy_list.empty()){
        iter= enemy_list.begin();
        enemy_list.erase(iter);
    }
    while(!enemy_bullets.empty()){
        bullet_iter=enemy_bullets.begin();
        enemy_bullets.erase(bullet_iter);
    }
}
Enemies::Enemies(RenderWindow* i_window){
    need_down=false;
    move_timer.restart();
    window=i_window;
    enemy_img.loadFromFile(ENEMY_IMG);
    bullet_img.loadFromFile(ENEMY_BULLET);
    map = "0000000000000000\n0000000000000000\n0000000000000000\n0000000000000000";
    reset();
}
void Enemies::reset(){
    below=false;
    unsigned char enemy_x = 0;
    unsigned char enemy_y = 0;
    while(!enemy_list.empty()){
        iter= enemy_list.begin();
        enemy_list.erase(iter);
    }
    while(!enemy_bullets.empty()){
        bullet_iter=enemy_bullets.begin();
        enemy_bullets.erase(bullet_iter);
    }
    shoot_distribution = uniform_int_distribution<unsigned short>(0,ENEMY_SHOOT_RATE);
    for(char map_part : map){
        enemy_x++;
        switch(map_part){
            case '\n':
            {
                enemy_x=0;
                enemy_y++;
                break;
            }
            case '0':
            {
                Enemy* tmp_enemy = new Enemy(enemy_img,BASE_SIZE*(1+enemy_x),BASE_SIZE*(1+enemy_y),BASE_SIZE,BASE_SIZE,window);
                if ((enemy_x+enemy_y)%2){
                    tmp_enemy->change_frame();
                }
                enemy_list.push_back(tmp_enemy);
                break;
            }

        }
    }
}
