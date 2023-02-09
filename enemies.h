#ifndef ENEMIES
#define ENEMIES
#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include "enemy.h"
#include "globals.h"

using namespace std;
class Enemies{
    Image enemy_img;
    Image bullet_img;
    String map;
    list<Enemy*> enemy_list;
    list<Enemy*>::iterator iter;
    RenderWindow* window;
    Clock move_timer;
    float move_pause;
    bool need_down, below;
    uniform_int_distribution<unsigned short> shoot_distribution;
    list<Bullet*> enemy_bullets;
    list<Bullet*>::iterator bullet_iter;
public:
    ~Enemies();
    Enemies(RenderWindow* i_window);
    void reset();
    void update(float time,std::mt19937& engine, list<Bullet*>* player_bullet);
    void move(std::mt19937& engine);
    void move_down();
    list<Bullet*>* get_bullet_list();
    int get_enemies_size();
    bool get_below();
};
#endif // ENEMIES
