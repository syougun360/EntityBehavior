#include "PlayerMover.h"
#include "Player.h"

PlayerMover::PlayerMover(const Player& player) :
EntityBehavior("PlayerMover", player.Name())
{
}

void PlayerMover::Awake()
{
	auto parent = GetComponentInParent();
	auto player = parent->GetComponent<Player>();

}

void PlayerMover::Update()
{

}