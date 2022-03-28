#include "Player.h"

void Player::initSprite()
{
	//set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.2f, 0.2f);
}

void Player::initTexture()
{
	//load taxture from file
	if (this->texture.loadFromFile("Texture/ship1.jpg") == false)
	{
		std::cout << "Error";
	}
	//this->texture.
}

Player::Player()
{
	this->movementSpeed = 5.f;

	this->initTexture();
	this->initSprite();
	
}

Player::~Player()
{
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
