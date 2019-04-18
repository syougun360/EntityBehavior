#pragma once
#include "EntityBehavior.h"

class Player;

class PlayerMover :public EntityBehavior
{
public:
	PlayerMover(const Player& player);

	void Awake();
	void Update();

private:

};

