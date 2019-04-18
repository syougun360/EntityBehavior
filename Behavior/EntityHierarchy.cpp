#include "EntityHierarchy.h"


EntityHierarchy::EntityHierarchy(const std::string& name,const Tags tag) :
Component(name, tag),
isActive(true),
state(UpdateState::Awake)
{
}

EntityHierarchy::EntityHierarchy(const std::string& name, const SortingLayer sortingLayer) :
Component(name, sortingLayer),
isActive(true)
{
}

EntityHierarchy::EntityHierarchy(const std::string& name, const Tags tag ,const SortingLayer sortingLayer) :
Component(name, tag, sortingLayer),
isActive(true),
state(UpdateState::Awake)
{
}


void EntityHierarchy::Active()
{
	isActive = true;
}

void EntityHierarchy::NonActive()
{
	isActive = false;
}

void EntityHierarchy::Updatable()
{
	switch (state)
	{
	case EntityHierarchy::UpdateState::Awake:
		std::cout << Name().c_str() << " Awake" << std::endl;

		Awake();
		state = UpdateState::Start;
		break;

	case EntityHierarchy::UpdateState::Start:
		std::cout << Name().c_str() << " Start" << std::endl;

		Start();
		state = UpdateState::Update;
		break;
	
	case EntityHierarchy::UpdateState::Update:
		std::cout << Name().c_str() << " Update" << std::endl;

		Update();

		break;
	
	default:
		break;
	}
}

void EntityHierarchy::Renderable()
{

}