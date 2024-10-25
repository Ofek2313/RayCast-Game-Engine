#include "Player.h"
#include "Ray.h"
#include "SFML/Graphics.hpp"




float Player::GetAngle() const {return this->PlayerAngle;}

float Player::GetSpeed() const { return Speed; }

void Player::SetAngle(float angle) { this->PlayerAngle = angle; }

void Player::ChangeAngle(float angle){ this->PlayerAngle += angle; }

void Player::SetSpeed(float speed) { this->Speed = speed; }

sf::RectangleShape& Player::GetSprite() { return PlayerSprite; }

void Player::CastRays(std::vector<std::vector<int>> map,sf::RenderWindow &window) {
	Ray ray;
	float rayAngle = this->PlayerAngle;
	float distance;
	float lineH,lineO;
	bool ver = false;
	for (size_t i = 0; i < 60; i++)
	{
		if (i < 30)  rayAngle -= 1;
		if (i == 30) rayAngle = this->PlayerAngle;
		else rayAngle += 1;

		ray.CastRay(rayAngle, PlayerSprite.getPosition().x, PlayerSprite.getPosition().y, map, window, distance, ver);
		lineH = (64 * 320) / distance;
		lineO = 160 - lineH / 2;
		if (lineH > 320) lineH = 320;

		sf::RectangleShape shape(sf::Vector2f(8, lineH ));
		if (ver) {
			shape.setFillColor(sf::Color::Green);
		}
		else {
			shape.setFillColor(sf::Color(0, 200, 0));
		}
		
		shape.setPosition(i * 8, lineO);
		window.draw(shape);
	}
		
	
	
	
}

