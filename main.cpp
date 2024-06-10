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
	leftPlayer.setPosition(-playerSize.x / 2, windowSize.y / 2 - playerSize.y / 2);

	//Right Player
	sf::RectangleShape rightPlayer(sf::Vector2f(20, 100));
	rightPlayer.setPosition(windowSize.x - playerSize.x / 2, windowSize.y / 2 - playerSize.y / 2);


	//++++++++++++++++++++++++  Ball ++++++++++++++++++++++++++++
	sf::CircleShape ball(10);
	sf::Vector2f ballInitialPos(windowSize.x / 2, windowSize.y / 2);
	ball.setPosition(ballInitialPos);
	sf::Vector2f ballVelocity(8, 2);

	// ++++++++++++++++++++++++ screen line +++++++++++++++++++++++++++++
	sf::RectangleShape line(sf::Vector2f(2, windowSize.y));
	line.setPosition(windowSize.x / 2 - 10, 0);
	line.setFillColor(sf::Color(128, 128, 128, 140));

	//++++++++++++++++++ SCore ++++++++++++++++++++++++++++++++++
	sf::Font font;
	if (!font.loadFromFile("../assets/fonts/font.ttf")) {
		std::cerr << "Error loading font from file @ assets/fonts/font.ttf\n";
		return 1; // Exit the program if the font fails to load
	}

	sf::Text lScore, rScore;
	int leftVal{ 0 }, rightVal{ 0 };

	lScore.setFont(font);
	rScore.setFont(font);

	lScore.setCharacterSize(20);
	rScore.setCharacterSize(20);

	lScore.setString(std::to_string(leftVal));
	rScore.setString(std::to_string(rightVal));

	float totalScoreWidth = lScore.getGlobalBounds().width + rScore.getGlobalBounds().width;
	float x = (windowSize.x - totalScoreWidth) / 2.0f;

	rScore.setPosition(x + lScore.getGlobalBounds().width + 10, 20);
	lScore.setPosition(x - 30, 20); // Adjust spacing as needed

	//++++++++++++++++++++++++  game loop +++++++++++++++++++++++++++
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			//basic movement for both players (W | S for Left Player - up | Down for right player)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				rightPlayer.move(sf::Vector2f(0, -25));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rightPlayer.move(sf::Vector2f(0, 25));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				leftPlayer.move(sf::Vector2f(0, -25));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				leftPlayer.move(sf::Vector2f(0, 25));
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

			//update score
			if (ball.getPosition().x < 0) {
				rightVal++;
				rScore.setString(std::to_string(rightVal));
			}
			else if (ball.getPosition().x + ball.getGlobalBounds().width > windowSize.x) {
				leftVal++;
				lScore.setString(std::to_string(leftVal));
			}

			// Reverse horizontal velocity
			ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
		}
		if (ball.getPosition().y < 0 || ball.getPosition().y + ball.getGlobalBounds().height > windowSize.y) {
			// Reverse vertical velocity
			ballVelocity.y = -ballVelocity.y;
		}

		if (rightVal != 10 && leftVal != 10) {
			window.clear();
			window.draw(leftPlayer);
			window.draw(rightPlayer);
			window.draw(line);
			window.draw(ball);
			window.draw(lScore);
			window.draw(rScore);
			window.display();
		}
		else if (rightVal >= 10) {
			sf::Text winText;
			winText.setFont(font);
			winText.setString("Right Player  Won");
			winText.setPosition(windowSize.x / 2 - (winText.getGlobalBounds().width / 2), windowSize.y / 2 - winText.getGlobalBounds().height / 2);
			window.clear(sf::Color::Black);
			window.draw(winText);
			window.display();
		}
		else if (leftVal >= 10) {
			sf::Text winText;
			winText.setFont(font);
			winText.setString("Left Player  Won");
			winText.setPosition(windowSize.x / 2 - (winText.getGlobalBounds().width / 2), windowSize.y / 2 - winText.getGlobalBounds().height / 2);
			window.clear(sf::Color::Black);
			window.draw(winText);
			window.display();
		}
		
	}

	return 0;
}