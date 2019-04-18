#include "Hierarchy.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	std::unique_ptr<Hierarchy> hierarchy;
	hierarchy = std::make_unique<Hierarchy>();

	hierarchy->Register(std::make_shared<Enemy>());
	hierarchy->Register(std::make_shared<Player>());

	hierarchy->Update();
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	auto player = Hierarchy::Find("Player");
	player->Instantiate(std::make_shared<Player>("Player2"));

	hierarchy->Update();
	hierarchy->Update();
	hierarchy->Update();

	auto playerTagObject = Hierarchy::FindWithTag(Tags::Player);
	auto playerTagObjects = Hierarchy::FindGameObjectsWithTag(Tags::Player);
	

	return 0;
}