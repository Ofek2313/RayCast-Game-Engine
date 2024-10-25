#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <cmath>
typedef float float_p;
class Game
{
public:
	Game();
	void RednerWindow(float x, float y);
	void setMap(std::vector<std::vector<int>> map);
	float getRadian(float angle);
	void startGame();
private:
	Player player;
	float_p playerX, playerY;
	float_p playerResX=10, playerResY=10;
	float deltaX, deltaY;
	sf::RenderWindow window;
	std::vector<std::vector<int>> map;
};

