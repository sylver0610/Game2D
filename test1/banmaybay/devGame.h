#pragma once
#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Bullet.h"
class devGame
{
	private:
		sf::RenderWindow* window;
		sf::Event ev;
		sf::VideoMode videoMode;
		Player *player;
		
		Bullet* bullet;
		std::map<std::string, sf::Texture> textures;

		void initVar();
		void initWindow();
		void initPlayer();
		void initBullet();
		void initTextures();
	public:
		devGame();
		~devGame();

		const bool isRunning() const;

		void pollEvent();
		void updatePollEvent();

		void updateInput();

		void update();
		void render();

};

