#pragma once
#include <iostream>
#include <vector>
#include <ctime>

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

	//game logic
	int point;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//game obj
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	void initVar();
	void initWindow();
	void initEnemy();
public:
	Game();
	virtual ~Game();

	const bool running() const;

	//functions
	void spawnEnemy();
	
	void updateMousePosition();
	void updateEnemies();
	void update();

	void pollEvents();
	
	void render();
	void renderEnemies();
};

