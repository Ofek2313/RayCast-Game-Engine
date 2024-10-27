#pragma once
#include "SFML/Graphics.hpp"
class Shotgun
{
private:
    sf::Texture shotgunTexture;
    sf::Sprite ShotgunSprite;
    bool RealodState = false;
public:
    Shotgun(const std::string &file);
    sf::Sprite getSprite();
    sf::Texture getTexture();
    void setSprite(sf::Sprite sprite);
    void setTexture(sf::Texture);
    void spriteAnimate(int &ReloadCount);
    void setReloadState(bool state);
    bool getReloadState();
    
    
};