#include "Basic_Logic/Game/Game.h"

int main() {
    //�������̳ߴ�
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;
    //������Ϸ
    Game game = Game(width, height, dotRadius, qi_radius);
    //��Ϸ��ʼ
    game.play();

    return 0;
}


//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML RenderTexture Example");
//    window.setFramerateLimit(60);
//
//    sf::RenderTexture renderTexture;
//    renderTexture.create(800, 600);
//
//    sf::Texture texture;
//    if (!texture.loadFromFile("../static/background.png")) {
//        return -1;
//    }
//
//    sf::Sprite sprite(texture);
//
//    renderTexture.clear();
//    renderTexture.draw(sprite);
//
//    // ��RenderTexture�ϻ��ƾ���
//    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
//    rectangle.setFillColor(sf::Color::Red);
//    rectangle.setPosition(200, 200);
//    renderTexture.draw(rectangle);
//
//    renderTexture.display();
//
//    sf::Sprite renderSprite(renderTexture.getTexture());
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        window.clear();
//        window.draw(renderSprite);
//        window.display();
//    }
//
//    return 0;
//}
