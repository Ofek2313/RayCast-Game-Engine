#include "Game.h"
#define PI 3.14159265359
Game::Game(){
	this -> playerX = 200;
	this -> playerY = 300;
    player.GetSprite().setSize(sf::Vector2f(10, 10));
	player.GetSprite().setFillColor(sf::Color::Yellow);
	player.GetSprite().setPosition(playerX, playerY);
	RednerWindow(512, 512);

	setMap({ {1,1,1,1,1,1,1,1},
			 {1,0,0,0,0,0,0,1},
			 {1,1,1,1,1,0,0,1},
			 {1,0,0,0,0,0,0,1},
			 {1,0,0,0,0,0,0,1},
			 {1,0,0,0,0,1,0,1},
			 {1,0,0,0,0,1,0,1},
			 {1,1,1,1,1,1,1,1,} });
   
}
void Game::setMap(const std::vector<std::vector<int>> map) {
	this -> map = map;
}
void Game::RednerWindow(const float x, const float y) {
	this->window.create(sf::VideoMode(x, y),"doom");
}
float Game::getRadian(float angle) {
        return angle * (PI / 180);
}
void Game::startGame() {
    while (window.isOpen())
    {



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        //Player Movment And Angle Handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

            player.ChangeAngle(-0.05);

            if (player.GetAngle() < 0) {
                player.ChangeAngle(360);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            player.ChangeAngle(0.05);

            if (player.GetAngle() > 360) {
                player.ChangeAngle(-360);
            }
        }
        deltaX = cos(getRadian(player.GetAngle())) * 0.1;
        deltaY = sin(getRadian(player.GetAngle())) * 0.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.GetSprite().move(deltaX, deltaY);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.GetSprite().move(-deltaX, -deltaY);
        }

        window.clear();
        player.CastRays(map, window);//Cast Rays
        window.display();
    }
}