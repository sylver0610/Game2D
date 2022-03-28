#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

	sf::RenderWindow* window;	
	sf::VideoMode videoMode;
	sf::Event ev;

	//mouse pos
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;


	//text
	sf::Text uiText;

	//game logic
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	bool endGame;

	//game obj
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	void initVar();
	void initWindow();
	void initEnemy();
	void initFont();
	void initText();
public:
	Game();
	virtual ~Game();

	//accessors
	const bool running() const;
	const bool getEndGame() const;
	//functions
	void spawnEnemy();
	
	void updateText();
	void updateMousePosition();
	void updateEnemies();
	void update();

	void pollEvents();
	
	void render();
	void renderEnemies(sf::RenderTarget& taget);
	void renderText(sf::RenderTarget& taget);
};

