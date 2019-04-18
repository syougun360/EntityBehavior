#include "Player.h"
#include "PlayerMover.h"

Player::Player(std::string name) :
EntityHierarchy(name,Tags::Player,SortingLayer::Player)
{

	AddComponent(std::make_shared<PlayerMover>(*this));
	AddComponent(std::make_shared<PlayerMover>(*this));
	AddComponent(std::make_shared<PlayerMover>(*this));
	AddComponent(std::make_shared<PlayerMover>(*this));

}

void Player::Awake()
{
	ComponentsAwake();

}

void Player::Start()
{
	ComponentsStart();
	auto gets = GetComponents<PlayerMover>("PlayerMover");
}


void Player::Update()
{
	ComponentsUpdate();

}

void Player::Render()
{
	
}
