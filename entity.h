#ifndef ENTITY
#define ENTITY
#include <SFML/Graphics.hpp>
#include "globals.h"
using namespace sf;
class Entity {
protected:
    float dx, dy, x, y, speed;//äîáàâèëè ïåðåìåííóþ òàéìåð äëÿ áóäóùèõ öåëåé
    int w, h; //ïåðåìåííàÿ “health”, õðàíÿùàÿ æèçíè èãðîêà
    bool life; //ïåðåìåííàÿ “life” æèçíü, ëîãè÷åñêàÿ
    Texture texture;//ñôìë òåêñòóðà
    Sprite sprite;//ñôìë ñïðàéò
    int CurrentFrame;//õðàíèò òåêóùèé êàäð
    RenderWindow* window;
public:
    Entity(Image &image, float X, float Y, int W, int H, RenderWindow* i_window);
    float get_x();
    float get_y();
    void set_y(float tmp_y);
    void set_x(float tmp_x);
    void set_current_frame(int cur_frame);
    int get_current_frame();
    void set_speed(float v);
    void set_life(bool tmp_life);
    bool get_life();
    virtual void update(float time)=0;
};

#endif // ENTITY
