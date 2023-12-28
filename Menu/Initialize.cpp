#include "Initialize.h"
#include "../Basic_Logic/Game/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

enum class MenuOption {
    PvP,
    PvAI,
    Quit
};

enum class GameState {
    Menu,
    PvPGame,
    PvAIGame
};

bool isMouseOver1(const sf::Text& text, const sf::RenderWindow& window) {
    sf::FloatRect bounds = text.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f convertedPosition = window.mapPixelToCoords(mousePosition);
    return bounds.contains(convertedPosition);
}

int Initialize::initialize() {
    //设置棋盘尺寸
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "WuZiQi");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../src/Manu.png");


    sf::Music music;
    music.openFromFile("../src/BGM.flac");
    music.setLoop(true); // 设置音乐循环播放
    music.setVolume(50);
    music.play(); // 播放音乐
    int status = 1;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                int x = mousePosition.x;
                int y = mousePosition.y;

                for (int i = 0; i < 3; i++){
                    if (x > 500 and x < 700 and y > 780 + i * 100 and y < 840 + i * 100) {
                        if (i == 1 or i == 0){
                            window.setVisible(false);
                            //创建游戏
                            while (status == 1){
                                Game new_game = Game(width, height, dotRadius, qi_radius,i);
                                new_game.play();
                                status = new_game.again;
                            }
                            window.setVisible(true);
                        }
                        else if (i == 2){
                            window.close();
                        }
                        break;
                    }
                }

            }

        }
        status = 1;

        window.clear();
        window.draw(sf::Sprite(texture));
        window.display();
    }

    return 0;
}