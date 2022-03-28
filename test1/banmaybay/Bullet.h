#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Bullet
{
	private:
		sf::Sprite shape;
		sf::Texture* texture;

		sf::Vector2f direction;
		float movementSpeed;

	public:
		Bullet();
		Bullet(sf::Texture &texture,float dirX,float dirY,float movement_Speed);
		~Bullet();

		void update();
		void render(sf::RenderTarget& target);
};


#endif // !BULLET_H