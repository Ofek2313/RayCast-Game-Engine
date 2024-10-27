#include "Shotgun.h"
void Shotgun::setSprite(sf::Sprite sprite) {
	this->ShotgunSprite = sprite;
}
sf::Sprite Shotgun::getSprite() {
	return this->ShotgunSprite;
}

sf::Texture Shotgun::getTexture() {
	return this->shotgunTexture;
}
void Shotgun::spriteAnimate(int &ReloadCount) {
	if (ReloadCount <= 1000) {
		ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 100, 150));
	}
	if(ReloadCount > 1000 && ReloadCount >= 2000) {
		ShotgunSprite.setTextureRect(sf::IntRect(144, 0, 100, 150));
	}
	if(ReloadCount > 2000 && ReloadCount >= 3000) {
		ShotgunSprite.setTextureRect(sf::IntRect(250, 0, 100, 150));
		
	}
	if(ReloadCount > 3000 && ReloadCount >=4000) {
		ShotgunSprite.setTextureRect(sf::IntRect(350, 0, 100, 150));
		
	}
	else {
		ReloadCount = 0;
		setReloadState(false);
	}
}
void Shotgun::setReloadState(bool state) {
	RealodState = state;
}
bool Shotgun::getReloadState() {
	return RealodState;
}
Shotgun::Shotgun(const std::string& file) {
	shotgunTexture.loadFromFile(file);
	ShotgunSprite.setTexture(shotgunTexture);
}