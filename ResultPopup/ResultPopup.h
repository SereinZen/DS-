#ifndef RESULTPOPUP_H
#define RESULTPOPUP_H

#include <SFML/Graphics.hpp>

class ResultPopup {
public:
    ResultPopup(int val);
    void displayResult();

private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text text;
};

#endif // RESULTPOPUP_H