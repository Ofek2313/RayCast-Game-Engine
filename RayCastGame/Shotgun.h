#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Shotgun
{
private:
    sf::Texture shotgunTexture;
    sf::Sprite ShotgunSprite;
    int Ammo = 10;
    //Reload
    bool RealodState = false;
    sf::SoundBuffer ReloadBuffer;
    sf::Sound ReloadSound;

    //Atack
    bool AttackState = false;
    sf::SoundBuffer AttackBuffer;
    sf::Sound AttackSound;
public:
    Shotgun(const std::string &file);
    sf::Sprite getSprite();
    sf::Texture getTexture();
    void setSprite(sf::Sprite sprite);
    void setTexture(sf::Texture);
    

    //Reload
    void ReloadAnimate(int& ReloadCount);
    void setReloadState(bool state);
    bool getReloadState();
    void PlayReloadSound();

    //Attack
    void AttackAnimate(int& ReloadCount);
    void setAttackState(bool state);
    bool getAttackState();
    void PlayAttackSound();
    
    void ChangeAmmo(int amount);
    void setAmmo(int amount);
    int getAmmo();
    
    
    
    
};