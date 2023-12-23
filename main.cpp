#include "Basic_Logic/Game/Game.h"
#include <SFML/Graphics.hpp>

//int main() {
//    //�������̳ߴ�
//    int width = 1200;
//    int height = 1200;
//    int dotRadius = 4;
//    int qi_radius = 25;
//    //������Ϸ
//    Game game = Game(width, height, dotRadius, qi_radius);
//    //��Ϸ��ʼ
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
    //�������̳ߴ�
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Example");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../src/NotoSerifSC-Black.otf")) {
        // �����������ʧ�ܵ����
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
                    // �������˶�ս��Ϸҳ����߼�
                    //��Ϸ��ʼ
                    window.setVisible(false);

                    //������Ϸ
                    Game game = Game(width, height, dotRadius, qi_radius);
                    game.play();
                    window.setVisible(true);

                }
                else if (isMouseOver(pvaiText, window)) {
                    selectedOption = MenuOption::PvAI;
                    currentState = GameState::PvAIGame;
                    // �����˻���ս��Ϸҳ����߼�
                    // ...
                }
                else if (isMouseOver(quitText, window)) {
                    selectedOption = MenuOption::Quit;
                    window.close();
                }
            }

        }

        // ����ѡ�е�ѡ�������ı���ɫ
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