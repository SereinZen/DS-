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

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "WuZiQi");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../src/NotoSerifSC-Black.otf")) {
        // �����������ʧ�ܵ����
        return -1;
    }
    sf::Texture texture;
    texture.loadFromFile("../src/background.png");
    sf::Text titleText("Game Menu", font, 80);
    titleText.setPosition(350, 150);

    sf::Text pvpText("PVP", font, 60);
    pvpText.setPosition(200, 500);

    sf::Text pvaiText("PvE", font, 60);
    pvaiText.setPosition(900, 500);

    sf::Text quitText("Quit", font, 60);
    quitText.setPosition(550, 750);

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