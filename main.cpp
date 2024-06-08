#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	//++++++++++++++++++++  window +++++++++++++++++++++++++
	sf::RenderWindow window(sf::VideoMode(900, 600), "Pong");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::Vector2u windowSize = window.getSize();

	//+++++++++++++++++++++ players ++++++++++++++++++++
	// Left Player
	sf::RectangleShape leftPlayer(sf::Vector2f(20, 100));
	sf::Vector2f playerSize = leftPlayer.getSize();
	leftPlayer.setFillColor(sf::Color(255, 229, 180));
	leftPlayer.setPosition(-playerSize.x / 2, windowSize.y / 2 - playerSize.y / 2);

	//Right Player
	sf::RectangleShape rightPlayer(sf::Vector2f(20, 100));
	rightPlayer.setFillColor(sf::Color(255, 229, 180));
	rightPlayer.setPosition(windowSize.x - playerSize.x / 2, windowSize.y / 2 - playerSize.y / 2);


	//++++++++++++++++++++++++  Ball ++++++++++++++++++++++++++++
	sf::CircleShape ball(10);
	sf::Vector2f ballInitialPos(windowSize.x / 2, windowSize.y / 2);
	ball.setPosition(ballInitialPos);
	sf::Vector2f ballVelocity(8, 2);

	// ++++++++++++++++++++++++ screen line +++++++++++++++++++++++++++++
	sf::RectangleShape line(sf::Vector2f(2,windowSize.y));
	line.setPosition(windowSize.x / 2 - 10, 0);
	line.setFillColor(sf::Color(255, 229, 150));

	//++++++++++++++++++++++++  game loop +++++++++++++++++++++++++++
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			//basic movement for both players (W | S for Left Player - up | Down for right player)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				rightPlayer.move(sf::Vector2f(0, -20));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rightPlayer.move(sf::Vector2f(0, 20));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				leftPlayer.move(sf::Vector2f(0, -20));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				leftPlayer.move(sf::Vector2f(0, 20));
			}

		}

		//+++++++++++++++++++ limit players movement to the window +++++++++++++++++++++++++
		// Left Player
		if (leftPlayer.getPosition().y + leftPlayer.getSize().y > windowSize.y) {
			leftPlayer.setPosition(sf::Vector2f(-playerSize.x / 2, windowSize.y - playerSize.y));
		}
		else if (leftPlayer.getPosition().y < 0) {
			leftPlayer.setPosition(sf::Vector2f(-playerSize.x / 2, 0));
		}

		//Right player
		if (rightPlayer.getPosition().y < 0) {
			rightPlayer.setPosition(sf::Vector2f(windowSize.x - playerSize.x / 2, 0));
		}
		else if (rightPlayer.getPosition().y + playerSize.y > windowSize.y) {
			rightPlayer.setPosition(sf::Vector2f(windowSize.x - playerSize.x / 2, windowSize.y - playerSize.y));
		}

		//+++++++++++++++++++++++++++ ball movement +++++++++++++++++++++++++++++++++s
		ball.move(ballVelocity);

		//+++++++++++++++++++++++++ collision detection +++++++++++++++++++++++

		// check for ball collision with players 
		if (ball.getGlobalBounds().intersects(rightPlayer.getGlobalBounds())) {
			ballVelocity.x = -ballVelocity.x;
			ball.move(ballVelocity);
		}
		if (ball.getGlobalBounds().intersects(leftPlayer.getGlobalBounds())) {
			ballVelocity.x = -ballVelocity.x;
			ball.move(ballVelocity);
		}

		// Check for window collision
		if (ball.getPosition().x < 0 || ball.getPosition().x + ball.getGlobalBounds().width > windowSize.x) {
			// Reverse horizontal velocity
			//ballVelocity.x = -ballVelocity.x;
			ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
		}
		if (ball.getPosition().y < 0 || ball.getPosition().y + ball.getGlobalBounds().height > windowSize.y) {
			// Reverse vertical velocity
			ballVelocity.y = -ballVelocity.y;
		}


		window.clear();
		window.draw(leftPlayer);
		window.draw(rightPlayer);
		window.draw(line);
		window.draw(ball);
		window.display();
	}

	return 0;
}