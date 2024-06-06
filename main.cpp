#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //=============== window ====================== 
    sf::RenderWindow window(sf::VideoMode(900, 600), "Pong");
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    //============== players =====================

    sf::RectangleShape leftPlayer(sf::Vector2f(20, 150));
    sf::Vector2f playerSize = leftPlayer.getSize();
    leftPlayer.setFillColor(sf::Color(255, 229, 180));
    leftPlayer.setPosition(playerSize.x / 2, windowSize.y / 2);
    leftPlayer.setOrigin(sf::Vector2f(playerSize.x / 2, playerSize.y /2));

    sf::RectangleShape rightPlayer(sf::Vector2f(20, 150));
    rightPlayer.setFillColor(sf::Color(255, 229, 180));
    rightPlayer.setPosition(windowSize.x - playerSize.x / 2, windowSize.y / 2);
    rightPlayer.setOrigin(sf::Vector2f(playerSize.x / 2, playerSize.y / 2));

    //=============== game loop ==================
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
        window.draw(leftPlayer);
        window.draw(rightPlayer);
        window.display();
    }

    return 0;
}