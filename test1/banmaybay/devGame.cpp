
#include "devGame.h"

void devGame::initVar()
{
	this->window = nullptr;
}

void devGame::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode,"BanMayBay", sf::Style::Default | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);
}

void devGame::initPlayer()
{
	this->player = new Player();
}

void devGame::initBullet()
{
	this->bullet = new Bullet();
}

void devGame::initTextures()
{
}

devGame::devGame()
{
	this->initVar();
	this->initPlayer();
	this->initBullet();
	this->initWindow();
}

devGame::~devGame()
{
	delete this->window;
	delete this->player;
}

const bool devGame::isRunning() const
{
	return this->window->isOpen();
}

void devGame::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed :
			if (this->ev.key.code == sf::Keyboard::Escape)
			this->window->close();
			break;
		}
	}

	

}

void devGame::updatePollEvent()
{
}

void devGame::updateInput()
{
	//move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(0.f, 1.f);
}

void devGame::update()
{
	this->pollEvent();
	this->updateInput();
	
}

void devGame::render()
{
	

	this->window->clear();

	this->player->render(*this->window);

	this->window->display();
}
