#include "Enemy.h"

Enemy::Enemy(std::string name) :
EntityHierarchy(name, Tags::Enemy, SortingLayer::Enemy)
{

}

void Enemy::Awake()
{
	ComponentsAwake();

}

void Enemy::Start()
{
	ComponentsStart();

}


void Enemy::Update()
{
	ComponentsUpdate();

}

void Enemy::Render()
{

}