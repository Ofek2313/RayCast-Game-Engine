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
	int FrameRefresh = 750;
	if (ReloadCount <= FrameRefresh) {
		ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 90, 150));
	}
	if(ReloadCount > FrameRefresh && ReloadCount <= FrameRefresh*2) {
		ShotgunSprite.setTextureRect(sf::IntRect(145, 0, 90, 150));
	}
	if(ReloadCount > FrameRefresh*2 && ReloadCount <= FrameRefresh*3) {
		ShotgunSprite.setTextureRect(sf::IntRect(245, 0, 90, 150));
		
	}
	if(ReloadCount > FrameRefresh * 3 && ReloadCount <= FrameRefresh * 4) {
		ShotgunSprite.setTextureRect(sf::IntRect(345, 0, 90, 150));
		
	}
	if (ReloadCount > FrameRefresh * 4 && ReloadCount <= FrameRefresh* 5) {
		ShotgunSprite.setTextureRect(sf::IntRect(445, 0, 90, 150));

	}
	if (ReloadCount > FrameRefresh * 5&& ReloadCount <= FrameRefresh*6) {
		ShotgunSprite.setTextureRect(sf::IntRect(545, 0, 90, 150));

	}
	if(ReloadCount > FrameRefresh*6) {
		ReloadCount = 0;
		setReloadState(false);
		ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 100, 150));
	}
}
void Shotgun::setReloadState(bool state) {
	this->RealodState = state;
}
bool Shotgun::getReloadState() {
	return this->RealodState;
}
Shotgun::Shotgun(const std::string& file) {
	shotgunTexture.loadFromFile(file);
	ShotgunSprite.setTexture(shotgunTexture);
	ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 90, 150));
	ShotgunSprite.setPosition(190, 280);
	ShotgunSprite.setScale(1.5, 1.5);
}