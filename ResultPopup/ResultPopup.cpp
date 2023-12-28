#include "ResultPopup.h"

bool isMouseOver(const sf::Text& text, const sf::RenderWindow& window) {
    sf::FloatRect bounds = text.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f convertedPosition = window.mapPixelToCoords(mousePosition);
    return bounds.contains(convertedPosition);
}

ResultPopup::ResultPopup(int result) {
    window = new sf::RenderWindow(sf::VideoMode(400, 250), "Game Over", sf::Style::Close);

    font.loadFromFile("../src/NotoSerifSC-Black.otf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(30, 10);

    std::string message;
    if (result == 1) {
        texture.loadFromFile("../src/Black_result.png");
        message = "Black Chess Wins!";
    } else if (result == -1) {
        texture.loadFromFile("../src/White_result.png");
        message = "White Chess Wins!";
    } else if (result == 0) {
        texture.loadFromFile("../src/Draw_result.png");
        message = "Draw!";
    }
    text.setString(message);

    backText.setString("Go Back");
    backText.setFont(font);
    backText.setCharacterSize(20);
    backText.setFillColor(sf::Color::Black);
    backText.setPosition(80, 100);

    againText.setString("Play Again");
    againText.setFont(font);
    againText.setCharacterSize(20);
    againText.setFillColor(sf::Color::Black);
    againText.setPosition(220, 100);

    this->displayResult();
}

void ResultPopup::displayResult() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                int x = mousePosition.x;
                int y = mousePosition.y;

                for (int i = 0; i < 2; i ++){
                    if (x > 115 and x < 280 and y > 150 + i * 50 and y < 180 + i * 50){
                        chose = i + 1;
                        window->close();
                    }
                }
            }
        }

        window->clear(sf::Color::White);
        window->draw(sf::Sprite(texture));
        window->display();
    }
}

