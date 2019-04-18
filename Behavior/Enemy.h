#pragma once
#include "EntityHierarchy.h"

class Enemy :public EntityHierarchy
{
public:
	Enemy(std::string name = "Enemy");

	void Awake();
	void Start();
	void Update();
	void Render();

private:

};
