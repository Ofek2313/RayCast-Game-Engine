#pragma once
#include "SFML/Graphics.hpp"
#include "Ray.h"
class Player
{
	private:
		float PlayerAngle=0;
		float Speed=0.1;
		sf::RectangleShape PlayerSprite;

	public:
		sf::RectangleShape& GetSprite();
	    float GetAngle() const;
		float GetSpeed() const;
		void SetAngle(float angle);
		void ChangeAngle(float angle);
		void SetSpeed(float speed);
		void CastRays(std::vector<std::vector<int>> map, sf::RenderWindow& window);
			
		
};

