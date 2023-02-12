#include "game.h"
int main()
{

    RenderWindow window(VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT), "Space Invaders", Style::Close);
    window.setView(View(FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
    Game game(&window);
    game.start();
}

