#ifndef BULLET
#define BULLET
#include "entity.h"
class Bullet: public Entity{
public:
    Bullet(Image &image, float X, float Y, int W, int H, RenderWindow* i_window, float i_speed);
    void update(float time);
    IntRect get_hitbox();
    };

#endif // BULLET

