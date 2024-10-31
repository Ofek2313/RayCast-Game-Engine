#include "Player.h"
#include "Ray.h"
#include "SFML/Graphics.hpp"
#define FOV 60



float Player::GetAngle() const { return this->PlayerAngle; }

float Player::GetSpeed() const { return Speed; }

void Player::SetAngle(float angle) { this->PlayerAngle = angle; }

void Player::ChangeAngle(float angle) { this->PlayerAngle += angle; }

void Player::SetSpeed(float speed) { this->Speed = speed; }

sf::RectangleShape& Player::GetSprite() { return PlayerSprite; }

void Player::CastRays(std::vector<std::vector<int>> map, sf::RenderWindow& window) {
	Ray ray;
	
	float distance;
	float lineH, lineO;
	bool ver = false;
	float rayAngle = this->PlayerAngle;


	
	for (size_t i = 0; i < FOV; i++)
	{
		 rayAngle += 1;
		ray.CastRay(rayAngle, PlayerSprite.getPosition().x, PlayerSprite.getPosition().y, map, window, distance, ver);
		if (distance > 0) {

		
			lineH = (64 * 320) / distance;
			lineO = 160 - lineH / 2;
		}
		
		

		sf::RectangleShape shape(sf::Vector2f(8, lineH));
		
		
		shape.setFillColor(sf::Color(0, 0, 250 - (distance * 0.5)));
		

		shape.setPosition(i * 8, lineO);
		
		window.draw(shape);
		
	}




}
