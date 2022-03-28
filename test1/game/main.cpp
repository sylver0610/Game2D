#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Game.h";

int main() {

	std::srand(time(NULL));

	//Init game
	Game game;

	/*sf::CircleShape circle(100.f);
	circle.setPosition(250, 250);
	circle.setFillColor(sf::Color(98, 232, 252));
	circle.setOrigin(circle.getRadius(), circle.getRadius());*/
	

	while (game.running() && !game.getEndGame()) {

		game.update();

		game.render();

		

	}
	return 0;
}