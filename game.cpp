#include "game.h"
Game::Game(RenderWindow* wind):window(wind){
    font.loadFromFile(TIMES_NEW_ROMAN);
    text=new Text("", font, 16);
    text->setColor(Color::Blue);
    engine.seed(std::time(nullptr));
    background_texture.loadFromFile(BACKGROUND);
    background_sprite.setTexture(background_texture);
    enemies=new Enemies(window);
    Image player_img;
    player_img.loadFromFile(PLAYER_IMG);
    player=new Player(player_img, 0,SCREEN_HEIGHT-BASE_SIZE-1, BASE_SIZE, BASE_SIZE, window, enemies->get_bullet_list());
}
void Game::start(){
    while (window->isOpen()){
        window->clear(); //Очищаем экран
        sf::Event event; //Переменная для события
        while (window->pollEvent(event)) //Опрос событий
        {
            if (event.type == sf::Event::Closed)
                window->close();//Закрываем окно, если событие “Closed”
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window->close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            enemies->reset();
            player->reset(false);
        }else{
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            if (player->get_life()&& !(enemies->get_below())){
                if(enemies->get_enemies_size()==0){
                    player->reset(true);
                    enemies->reset();
                }

                window->draw(background_sprite);
                enemies->update(time, engine,player->get_player_bullet_list());
                player->update(time);
                text->setPosition(0, -5);
                text->setString("score:"+player->get_score());
                window->draw(*text);
            }else{
                text->setPosition(0, -5);
                text->setString("score:"+player->get_score());
                text->setPosition(60, 60);
                if (!player->get_life()){
                    text->setString("Game Over(you were killed)");
                }else{

                    text->setString("Game Over(enemies reached you)");
                }
                window->draw(*text);
                text->setPosition(110, 77);
                text->setString("Your score:"+player->get_score());
                window->draw(*text);
                text->setPosition(90, 93);
                text->setString("Press 'space' to start");
                window->draw(*text);
            }
        }
        window->display(); //Отображаем круг на экран
    }

}
