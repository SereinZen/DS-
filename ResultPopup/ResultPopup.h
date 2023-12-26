#ifndef RESULTPOPUP_H
#define RESULTPOPUP_H

#include <SFML/Graphics.hpp>

class ResultPopup {
public:
    ResultPopup(int val);
    void displayResult();
    // 1 again
    // 2 back
    int chose;

private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text text;
    sf::Text backText;
    sf::Text againText;
};

#endif // RESULTPOPUP_H