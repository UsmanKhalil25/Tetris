#pragma once
#include<SFML/Audio.hpp>
#include<iostream>

using namespace sf;
using  namespace std;
class SoundPlay {
private:
	Music gameTheme;
	Sound clearLineSound;
	Sound collisionSound;
	Sound rotationSound;
	SoundBuffer collisionBuffer;
	SoundBuffer movementBuffer;
	SoundBuffer rotationBuffer;
	Sound movementSound;
public:
	SoundPlay() {
		if (!gameTheme.openFromFile("sounds/tetrisThemeSound.wav"))
			cout << "Could not load theme sound" << endl;
		if (!collisionBuffer.loadFromFile("sounds/collision.wav"))
			cout << "Could not load collision sound"<<endl;
		this->collisionSound.setBuffer(collisionBuffer);
		if (!movementBuffer.loadFromFile("sounds/movement.wav"))
			cout << "Could not load movement sound" << endl;
		this->movementSound.setBuffer(movementBuffer);
		if (!rotationBuffer.loadFromFile("sounds/rotation.wav"))
			cout << "Could not load rotation sound" << endl;
		this->rotationSound.setBuffer(rotationBuffer);

	}
	void playThemeSound() {
		this->gameTheme.play();
	}
	void playCollisionSonud() {
		this->collisionSound.play();
	}

	void playMovementSound() {
		this->movementSound.play();
	}
	void playRotationSound() {
		this->rotationSound.play();
	}
};