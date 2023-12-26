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

    sf::Font font;
    if (!font.loadFromFile("../src/NotoSerifSC-Black.otf")) {
        // 处理字体加载失败的情况
        return -1;
    }
    sf::Texture texture;
    texture.loadFromFile("../src/background.png");
    sf::Text titleText("Game Menu", font, 80);
    titleText.setPosition(350, 300);
    titleText.setFillColor(sf::Color::Cyan);

    sf::Text pvpText("PVP", font, 60);
    pvpText.setPosition(535, 680);

    sf::Text pvaiText("PVE", font, 60);
    pvaiText.setPosition(535, 790);

    sf::Text quitText("Quit", font, 60);
    quitText.setPosition(535, 900);

    MenuOption selectedOption = MenuOption::PvP;
    GameState currentState = GameState::Menu;
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
                if (isMouseOver1(pvpText, window)) {
                    selectedOption = MenuOption::PvP;
                    currentState = GameState::PvPGame;
                    // 进入人人对战游戏页面的逻辑
                    //游戏开始
                    window.setVisible(false);

                    //创建游戏
                    while (status == 1){
                        Game new_game = Game(width, height, dotRadius, qi_radius,0);
                        new_game.play();
                        status = new_game.again;
                    }
                    window.setVisible(true);

                }
                else if (isMouseOver1(pvaiText, window)) {
                    selectedOption = MenuOption::PvAI;
                    currentState = GameState::PvAIGame;
                    // 进入人机对战游戏页面的逻辑
                    // ...
                    while (status == 1){
                        Game new_game = Game(width, height, dotRadius, qi_radius,0);
                        new_game.play();
                        status = new_game.again;
                    }

                    window.setVisible(true);
                }
                else if (isMouseOver1(quitText, window)) {
                    selectedOption = MenuOption::Quit;
                    window.close();
                }
            }

        }

        // 根据选中的选项设置文本颜色
        pvpText.setFillColor(selectedOption == MenuOption::PvP ? sf::Color::Red : sf::Color::Yellow);
        pvaiText.setFillColor(selectedOption == MenuOption::PvAI ? sf::Color::Red : sf::Color::Yellow);
        quitText.setFillColor(selectedOption == MenuOption::Quit ? sf::Color::Red : sf::Color::Yellow);

        window.clear();
        window.draw(sf::Sprite(texture));
        window.draw(titleText);
        window.draw(pvpText);
        window.draw(pvaiText);
        window.draw(quitText);
        window.display();
    }

    return 0;
}