#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		float movementSpeed;

		void initSprite();
		void initTexture();

	public:
		Player();
		~Player();

		void move(const float dirX, const float dirY);

		void update();
		void render(sf::RenderTarget& target);

};

