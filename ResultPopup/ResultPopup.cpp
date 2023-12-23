#include "ResultPopup.h"

ResultPopup::ResultPopup(int result) {
    window = new sf::RenderWindow(sf::VideoMode(500, 300), "结算", sf::Style::Close);

    font.loadFromFile("../src/NotoSerifSC-Black.otf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(100, 100);
//    sf::RenderTexture renderTexture;
    std::string message;
    if (result == 1) {
        message = "Black Chess Wins!";
    } else if (result == -1) {
        message = "White Chess Wins!";
    } else if (result == 0) {
        message = "Draw!";
    }

    text.setString(message);
//    renderTexture.draw(text);

//    renderTexture.draw();
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

        window->clear(sf::Color::White);
        window->draw(text);
        window->display();
    }
}