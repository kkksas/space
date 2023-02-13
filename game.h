#ifndef GAME
#define GAME
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
using namespace sf;
#include "globals.h"
#include "player.h"
#include "enemies.h"
class Game{
private:
    Font font;
    Text* text;
    std::mt19937 engine;
    Texture background_texture;
    Sprite background_sprite;
    Clock clock;
    RenderWindow* window;
    Enemies* enemies;
    Player* player;
public:
    Game(RenderWindow* wind);
    void start();
};
#endif // GAME