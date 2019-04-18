#include "EntityBehavior.h"
#include "Component.h"

EntityBehavior::EntityBehavior(const std::string& name) :
Component(name),
isEnable(true)
{
	
}

EntityBehavior::EntityBehavior(const std::string& name, const std::string& parentName) :
Component(name, parentName),
isEnable(true)
{

}

void EntityBehavior::Enable()
{
	isEnable = true;
}

void EntityBehavior::Preclude()
{
	isEnable = false;
}
