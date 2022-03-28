#include "Game.h"

//private func
void Game::initVar()
{
	this->window = nullptr;

	//game logic
	this->endGame = false;
	this->points =0;	
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer =this->enemySpawnTimerMax;
	this->maxEnemies = 15;
	this->health = 10;
	this->mouseHeld = false;
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
	/*this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);*/



}

void Game::initFont()
{
	if (this->font.loadFromFile("Font/Dosis-Light.ttf"))
	{
		std::cout << "Error :: game :: initfont :: failed" << "\n";
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(50);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
}

//constructors destructors
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initFont();
	this->initText();
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

const bool Game::getEndGame() const
{
	return this->endGame;
}



void Game::spawnEnemy()
{
	/*
		spawns enemies and set their types and colors. spawns them at random pos
		-sets a random type(diff)
		-sets a random pos
		-sets a random color
		-add enemy to vector
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	int type = rand() % 5;
	
	switch (type)
	{
	case 0:
		this->enemy.setSize(sf::Vector2f(10.f, 10.f));
		this->enemy.setFillColor(sf::Color::Green);
		break;
	case 1:
		this->enemy.setSize(sf::Vector2f(30.f, 30.f));
		this->enemy.setFillColor(sf::Color::Blue);
		break;
	case 2:
		this->enemy.setSize(sf::Vector2f(40.f, 40.f));
		this->enemy.setFillColor(sf::Color::Yellow);
		break;
	case 3:
		this->enemy.setSize(sf::Vector2f(50.f, 50.f));
		this->enemy.setFillColor(sf::Color::Red);
		break;
	case 4:
		this->enemy.setSize(sf::Vector2f(60.f, 60.f));
		this->enemy.setFillColor(sf::Color::White);
		break;
	default:
		this->enemy.setSize(sf::Vector2f(100.f, 100.f));
		this->enemy.setFillColor(sf::Color::Cyan);
		break;
	}



	
	this->enemies.push_back(this->enemy);

}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points<<"\n"
		<<"Health: "<<this->health;
	this->uiText.setString(ss.str());
}

void Game::updateMousePosition()
{
	/*
		Updates the mouse position:
		- mouse position relative to window (vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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
	for (int i = 0; i < this->enemies.size();i++)
	{
		

		this->enemies[i].move(0.f, 1.f);	

		//if the enemy in past the bottom of the screen
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "health: " << this->health << std::endl;
		}
	}
	
	//check if click upon

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0;i<this->enemies.size() && deleted == false;i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					//delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
					//gain point
					this->points += 10.f;
					std::cout << "point: " << this->points << std::endl;
				}
			}
		}
		else
		{
			this->mouseHeld = false;
		}
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

	if (this->endGame == false)
	{
		this->updateMousePosition();
		this->updateText();
		this->updateEnemies();
	}
	//endgame condition
	if (this->health <= 0)
		this->endGame = true;
}

void Game::renderEnemies(sf::RenderTarget& taget)
{
	for (auto& e : this->enemies)
	{
		taget.draw(e);
	}
}

void Game::renderText(sf::RenderTarget& taget)
{
	taget.draw(this->uiText);
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
	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();
}


