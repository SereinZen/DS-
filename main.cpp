#include "Basic_Logic/Game/Game.h"
#include <SFML/Graphics.hpp>

//int main() {
//    //设置棋盘尺寸
//    int width = 1200;
//    int height = 1200;
//    int dotRadius = 4;
//    int qi_radius = 25;
//    //创建游戏
//    Game game = Game(width, height, dotRadius, qi_radius);
//    //游戏开始
//    game.play();
//
//    return 0;
//}

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

bool isMouseOver(const sf::Text& text, const sf::RenderWindow& window) {
    sf::FloatRect bounds = text.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f convertedPosition = window.mapPixelToCoords(mousePosition);
    return bounds.contains(convertedPosition);
}

int main() {
    //设置棋盘尺寸
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Example");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../src/NotoSerifSC-Black.otf")) {
        // 处理字体加载失败的情况
        return -1;
    }

    sf::Text titleText("Menu", font, 48);
    titleText.setPosition(350.f, 100.f);

    sf::Text pvpText("1. PvP", font, 24);
    pvpText.setPosition(350.f, 200.f);

    sf::Text pvaiText("2. PvAI", font, 24);
    pvaiText.setPosition(350.f, 250.f);

    sf::Text quitText("3. Quit", font, 24);
    quitText.setPosition(350.f, 300.f);

    MenuOption selectedOption = MenuOption::PvP;
    GameState currentState = GameState::Menu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (isMouseOver(pvpText, window)) {
                    selectedOption = MenuOption::PvP;
                    currentState = GameState::PvPGame;
                    // 进入人人对战游戏页面的逻辑
                    //游戏开始
                    window.setVisible(false);

                    //创建游戏
                    Game game = Game(width, height, dotRadius, qi_radius);
                    game.play();
                    window.setVisible(true);

                }
                else if (isMouseOver(pvaiText, window)) {
                    selectedOption = MenuOption::PvAI;
                    currentState = GameState::PvAIGame;
                    // 进入人机对战游戏页面的逻辑
                    // ...
                }
                else if (isMouseOver(quitText, window)) {
                    selectedOption = MenuOption::Quit;
                    window.close();
                }
            }

        }

        // 根据选中的选项设置文本颜色
        pvpText.setFillColor(selectedOption == MenuOption::PvP ? sf::Color::Red : sf::Color::White);
        pvaiText.setFillColor(selectedOption == MenuOption::PvAI ? sf::Color::Red : sf::Color::White);
        quitText.setFillColor(selectedOption == MenuOption::Quit ? sf::Color::Red : sf::Color::White);

        window.clear();
        window.draw(titleText);
        window.draw(pvpText);
        window.draw(pvaiText);
        window.draw(quitText);
        window.display();
    }

    return 0;
}