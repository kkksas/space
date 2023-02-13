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
void Enemies::update(float time,std::mt19937& engine, list<Bullet*>* player_bullet){
    move(engine);
    if (!enemy_bullets.empty()){
        bullet_iter=enemy_bullets.begin();
        while(bullet_iter != enemy_bullets.end()){
            (*bullet_iter)->update(time);
            if ((*bullet_iter)->get_y()>SCREEN_HEIGHT){
                enemy_bullets.erase(bullet_iter);
            }
            bullet_iter++;
        }
    }
        if(!enemy_list.empty()){
            iter = enemy_list.begin();
            while(iter != enemy_list.end()){
                (*iter)->update(time);
                if ((*iter)->get_y()>=SCREEN_HEIGHT-3*BASE_SIZE/2){
                    below=true;
                }
                for(bullet_iter=player_bullet->begin();bullet_iter!=player_bullet->end();bullet_iter++){
                    if ((*iter)->check_collisions((*bullet_iter)->get_hitbox())){
                        enemy_list.erase(iter);
                        (*bullet_iter)->set_life(false);
                        break;
                    }
                }

                iter++;
            }
        }


}

void Enemies::move(std::mt19937& engine){
    if (move_timer.getElapsedTime().asMilliseconds()>MOVE_TIME-ENEMY_SPEED_INCREASE*(64-enemy_list.size())){
        if(!need_down){
            if(!enemy_list.empty()){
                iter = enemy_list.begin();

                while(iter != enemy_list.end()){
                    if ((*iter)->move(1)){
                        need_down=true;
                    }
                    if (shoot_distribution(engine)==0){enemy_bullets.push_back((*iter)->shoot(bullet_img));}
                    iter++;
                    }
            }
            move_timer.restart();
        }else{
            move_down();
            need_down=false;
        }
    }
}
void Enemies::move_down(){
    if(!enemy_list.empty()){
        iter = enemy_list.begin();
        while(iter != enemy_list.end()){
            (*iter)->move_down();
            (*iter)->move(-1);
            iter++;
        }
    }
}
list<Bullet*>* Enemies::get_bullet_list(){
    return &enemy_bullets;
}
int Enemies::get_enemies_size(){
    return enemy_list.size();
}

bool Enemies::get_below()
{
    return below;
}
