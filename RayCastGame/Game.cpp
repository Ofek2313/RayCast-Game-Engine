#include "Game.h"
#define PI 3.14159265359
Game::Game() {
	this -> playerX = 200;
	this -> playerY = 300;
	Player player(this->playerResX, this->playerResY);
	player.GetSprite().setFillColor(sf::Color::Yellow);
	player.GetSprite().setPosition(playerX, playerY);
	RednerWindow(512, 512);
	

	
	setMap({ {1,1,1,1,1,1,1,1},
			 {1,0,0,0,0,0,0,1},
			 {1,0,1,0,0,0,0,1},
			 {1,0,1,0,0,0,0,1},
			 {1,0,1,0,0,0,0,1},
			 {1,0,0,0,1,1,0,1},
			 {1,0,0,0,1,1,0,1},
			 {1,1,1,1,1,1,1,1,} });
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
        
        DrawMiniMap(map, player);

       

        window.display();
    }
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
void Game::DrawMiniMap(std::vector<std::vector<int>> map, Player player) {
    sf::RectangleShape player_copy(sf::Vector2f(5, 5));
    sf::RectangleShape line(sf::Vector2f(2, 10));
  
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            sf::RectangleShape box(sf::Vector2f(10, 10));

            line.setFillColor(sf::Color::Yellow);
            line.setRotation(player.GetAngle()-90);
            player_copy.setFillColor(sf::Color::Yellow);
            player_copy.setPosition(player.GetSprite().getPosition().x / 6.4, player.GetSprite().getPosition().y / 6.4);
            line.setPosition(player_copy.getPosition().x, player_copy.getPosition().y);
            if(map[i][j]==1){
                box.setFillColor(sf::Color::White);
            }
            else {
                box.setFillColor(sf::Color::Black);
            }
            box.setPosition(10 * j, 10 * i);
            window.draw(box);
            window.draw(line);
            window.draw(player_copy);
        }
    }
}