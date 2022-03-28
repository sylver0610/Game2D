#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture& texture, float dirX, float dirY, float movement_Speed)
{
	this->shape.setTexture(texture);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movement_Speed;

}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
