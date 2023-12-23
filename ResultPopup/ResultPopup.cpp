#include "ResultPopup.h"

ResultPopup::ResultPopup(int result) {
    window = new sf::RenderWindow(sf::VideoMode(400, 200), "Game Result", sf::Style::Close);

    font.loadFromFile("../src/NotoSerifSC-Black.otf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 80);

    std::string message;
    if (result == 1) {
        message = "黑棋获胜!";
    } else if (result == -1) {
        message = "白棋获胜!";
    } else if (result == 0) {
        message = "平局!";
    }

    text.setString(message);
    this->displayResult();
}

void ResultPopup::displayResult() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::Black);
        window->draw(text);
        window->display();
    }
}