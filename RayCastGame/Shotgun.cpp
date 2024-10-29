#include "Shotgun.h"

Shotgun::Shotgun(const std::string& file) {
	//Load Texture And Sprite
	shotgunTexture.loadFromFile(file);
	ShotgunSprite.setTexture(shotgunTexture);
	ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 90, 150));

	//Set The Shotgun Position and scale
	ShotgunSprite.setPosition(190, 290);
	ShotgunSprite.setScale(1.5, 1.5);

	//Set The Reload Sound
	ReloadBuffer.loadFromFile("../Sounds/Reload.mp3");
	ReloadSound.setBuffer(ReloadBuffer);

	//Set The Attack Sound
	AttackBuffer.loadFromFile("../Sounds/Attack.mp3");
	AttackSound.setBuffer(AttackBuffer);
}

void Shotgun::setSprite(sf::Sprite sprite) {
	this->ShotgunSprite = sprite;
}
sf::Sprite Shotgun::getSprite() {
	return this->ShotgunSprite;
}

sf::Texture Shotgun::getTexture() {
	return this->shotgunTexture;
}
void Shotgun::ReloadAnimate(int &ReloadCount) {
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
void Shotgun::PlayReloadSound() {
	ReloadSound.play();
}
void Shotgun::setAttackState(bool state) {
	this->AttackState = state;
}
bool Shotgun::getAttackState() {
	return this->AttackState;
}
void Shotgun::AttackAnimate(int& ReloadCount) {
	int FrameRefresh = 750;
	if (ReloadCount <= FrameRefresh) {
		ShotgunSprite.setTextureRect(sf::IntRect(35, 170, 90, 120));
		ShotgunSprite.setPosition(190, 400);
	}
	if (ReloadCount > FrameRefresh && ReloadCount <= FrameRefresh * 2) {
		
		ShotgunSprite.setTextureRect(sf::IntRect(155, 170, 90, 120));
		ShotgunSprite.setPosition(190, 400);
	}
	if (ReloadCount > FrameRefresh * 2) {
		ShotgunSprite.setPosition(190, 290);
		ReloadCount = 0;
		setAttackState(false);
		ShotgunSprite.setTextureRect(sf::IntRect(30, 0, 100, 150));


	}
}
void Shotgun::PlayAttackSound() {
	AttackSound.play();
}
void Shotgun::ChangeAmmo(int amount) {
	this->Ammo += amount;
}
void Shotgun::setAmmo(int ammount) {
	this->Ammo = ammount;
}
int Shotgun::getAmmo() {
	
	return this->Ammo;
	
}