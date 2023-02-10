#ifndef PLAYER
#define PLAYER
#include <SFML/Graphics.hpp>
#include "globals.h"
#include "bullet.h"
#include <list>
#include "entity.h"
using namespace sf;
using namespace std;
class Player:public Entity{
private:
    unsigned int score;
    enum { left, right, stay} state;
    list<Bullet*> bullet_list;
    list<Bullet*>* enemy_bullets;
    list<Bullet*>::iterator iter;
    Image bullet_img;

    Clock reload_timer;
public:
    Player(Image &image, float X, float Y, int W, int H, RenderWindow* i_window, list<Bullet*>* enemy_bul);
    ~Player();
    void control();
    void reset(bool win);
    void die();
    void update(float time);
    list<Bullet*>* get_player_bullet_list();
    IntRect get_hitbox();
    bool is_alive();
    string get_score();
    void set_score(unsigned int sc);
};
#endif // PLAYER