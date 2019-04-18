#pragma once
#include "EntityHierarchy.h"

class Player :public EntityHierarchy
{
public:
	Player(std::string name = "Player");

	void Awake();
	void Start();
	void Update();
	void Render();

private:

};

