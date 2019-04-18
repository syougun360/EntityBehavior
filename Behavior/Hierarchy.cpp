#include "Hierarchy.h"
#include <algorithm>

std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> Hierarchy::hierarchyList;


void Hierarchy::SortingLayerSort()
{
	std::vector<std::shared_ptr<EntityHierarchy>> ehList;

	for (auto& hierarchy : hierarchyList)
	{
		ehList.push_back(hierarchy.second);
	}

	Clear();

	std::sort(ehList.begin(), ehList.end(), 
		[](const std::shared_ptr<EntityHierarchy> left, const std::shared_ptr<EntityHierarchy> right)
	{
		return left->GetSortingLayer() < right->GetSortingLayer();
	});

	for (auto& eh : ehList)
	{
		hierarchyList.insert(std::make_pair(eh->Name(), eh));
	}
}

void Hierarchy::Register(std::shared_ptr<EntityHierarchy> entity)
{
	std::cout << entity->Name().c_str() << " �ǉ�" << std::endl;

	hierarchyList.insert(std::make_pair(entity->Name(), entity));

}

void Hierarchy::Deregistration(const std::string& name)
{
	auto itr = hierarchyList.find(name);
	if (itr != hierarchyList.end()) return;

	std::cout << itr->second->Name().c_str() << " �폜" << std::endl;

	hierarchyList.erase(itr);
}

void Hierarchy::Clear()
{
	hierarchyList.clear();
}

void Hierarchy::Update()
{
	for (auto& hierarchy : hierarchyList)
	{
		hierarchy.second->Updatable();
	}
}

void Hierarchy::Render()
{
	std::cout << "---------- Hierarchy Render ----------" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		std::cout << hierarchy.second->Name().c_str() << " Render" << std::endl;

		hierarchy.second->Renderable();
	}
}



std::shared_ptr<EntityHierarchy> Hierarchy::Find(const std::string& name)
{
	std::cout << " Find()" << std::endl;

	auto findObject = hierarchyList.find(name);
	if (findObject == hierarchyList.end()) return nullptr;

	std::cout << findObject->second->Name().c_str() << " �擾" << std::endl;

	return findObject->second;
}


// Tag�ł̃Q�[���I�u�W�F�N�g���擾
std::shared_ptr<EntityHierarchy> Hierarchy::FindWithTag(const Tags tag)
{
	std::cout << " FindWithTag()" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->GetTag() != tag) continue;

		std::cout << hierarchy.second->Name().c_str() << " �擾" << std::endl;

		return hierarchy.second;
	}

	return nullptr;
}

// Tag�ł̃Q�[���I�u�W�F�N�g��z��Ŏ擾
std::vector<std::shared_ptr<EntityHierarchy>> Hierarchy::FindGameObjectsWithTag(const Tags tag)
{
	std::cout << " FindGameObjectsWithTag()" << std::endl;

	std::vector<std::shared_ptr<EntityHierarchy>> gameObjects;
	gameObjects.clear();

	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->GetTag() != tag) continue;

		std::cout << hierarchy.second->Name().c_str() << " �擾" << std::endl;

		gameObjects.push_back(hierarchy.second);
	}
	
	std::cout << gameObjects.size() << " ���擾" << std::endl;

	return gameObjects;
}
