#ifndef ENEMY
#define ENEMY
#include <random>
#include "bullet.h"
#include "entity.h"
class Enemy: public Entity{
    enum direction {left=-1,right=1} state;
public:
    Enemy(Image &image, float X, float Y, int W, int H, RenderWindow* i_window);
    void change_frame();
    bool move(int dir);
    void update(float time);
    void move_down();

};
#endif // ENEMY
