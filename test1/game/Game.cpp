#include "Game.h"

//private func
void Game::initVar()
{
	this->window = nullptr;

	//game logic
	
	this->point =0;	
	this->enemySpawnTimerMax = 100.f;
	this->enemySpawnTimer =this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}


void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	//this->videoMode
	this->window = new sf::RenderWindow(this->videoMode, "Game 1!!", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initEnemy()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);



}

//constructors destructors
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initEnemy();
}

Game::~Game()
{
	delete this->window;
}
//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}



void Game::spawnEnemy()
{
	/*
		spawns enemies and set their color and pos
		-sets a random pos
		-sets a random color
		-add enemy to vector
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);
	this->enemies.push_back(this->enemy);

}

void Game::updateMousePosition()
{
	/*
		Updates the mouse position:
		- mouse position relative to window (vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
}

void Game::updateEnemies()
{
	/*
		update the enemy spawn timer and spawns enemies
		move the enemies downwards.
		remove the enemies at the egde of the screen
	*/
	//updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{	//spawn enemy and reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;

	}

	//move the enemies
	for (auto& e : this->enemies)
	{
		e.move(0.f, 5.f);
	}
	
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}

	}

}

//public func
void Game::update()
{
	this->pollEvents();	
	this->updateMousePosition();
	this->updateEnemies();
	
}

void Game::render()
{
	/*
	* return @void
	- clear old frame
	- render objects
	- display frame in window
	*/

	this->window->clear(sf::Color::Black);


	//draw
	this->renderEnemies();

	this->window->display();
}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}
