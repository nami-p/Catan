#pragma once
#include "World.h"
#include "Input.h"
#include "Actions.h"
#include "Asserts.h"

class Game
{
public:
	Input input;
	static World* world;
	Actions* actions;
	Asserts* asserts;

	Game();

	void Play();
	void StartGame();
	void PlaySteps(int& selectedX, int& selectedY);
	void Asserts1();
};

