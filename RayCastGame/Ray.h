#pragma once
#include "SFML/Graphics.hpp"
class Ray
{
public:
	float distance(float x1, float x2, float y1, float y2);
	void CastRay(float RayAngle, float playerX, float playerY, std::vector<std::vector<int>> map, sf::RenderWindow& window, float& distance, bool &vertical);
	float Get_RadianAngle(float angle);
private:
	int RayAngle;
};

