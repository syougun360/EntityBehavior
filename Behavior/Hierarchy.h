// ----------------------------------------------
// Hierarchy(�K�w)
// 
// �o�^�E�폜�E�S�폜
// �K�w�̎��Ԏ擾
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "EntityHierarchy.h"

class EntityHierarchy;
class Component;

class Hierarchy
{
public:

	// �o�^
	static void Register(std::shared_ptr<EntityHierarchy> entity);

	// �폜
	static void Deregistration(const std::string& name);

	// �S�폜
	static void Clear();

	void Update();
	void Render();

	// ���O�ŒT��
	static std::shared_ptr<EntityHierarchy> Find(const std::string& name);

	// Tag�ł̃Q�[���I�u�W�F�N�g���擾
	static std::shared_ptr<EntityHierarchy> FindWithTag(const Tags tag);

	// Tag�ł̃Q�[���I�u�W�F�N�g��z��Ŏ擾
	static std::vector<std::shared_ptr<EntityHierarchy>> FindGameObjectsWithTag(const Tags tag);

	// ���O�ŒT��
	template<typename Type>
	static std::shared_ptr<Type> Find(const std::string& name)
	{
		std::cout << " Find<T>()" << std::endl;

		auto findObject = hierarchyList.find(name);
		if (findObject == hierarchyList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " �擾" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// �z����擾
	template<typename Type>
	static std::vector<std::shared_ptr<Type>> FindGameObjects(const std::string& name)
	{
		std::cout << " FindGameObjects<T>()" << std::endl;

		auto findObjects = hierarchyList.equal_range(name);
		std::vector<std::shared_ptr<Type>> components;
		
		components.clear();

		for (auto iterator = findObjects.first; iterator != findObjects.second; iterator++)
		{
			auto target = *iterator;
			components.push_back(std::dynamic_pointer_cast<Type>(target.second));
			std::cout << target.second->Name().c_str() << " �擾" << std::endl;
		}

		std::cout << components.size << " ���擾" << std::endl;

		return components;

	}
	// Tag�ł̃Q�[���I�u�W�F�N�g���擾
	template<typename Type>
	static std::shared_ptr<Type> FindWithTag(const Tags tag)
	{
		std::cout << " FindWithTag<T>()" << std::endl;

		for (auto& hierarchy : hierarchyList)
		{
			if (hierarchy.second->Tag() != tag) continue;

			auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

			std::cout << tagObject->Name() << " �擾" << std::endl;

			return tagObject;
		}
	}

	// Tag�ł̃Q�[���I�u�W�F�N�g��z��Ŏ擾
	template<typename Type>
	static std::vector<std::shared_ptr<Type>> FindGameObjectsWithTag(const Tags tag)
	{
		std::cout << " FindGameObjectsWithTag<T>()" << std::endl;

		std::vector<std::shared_ptr<Type>> gameObjects;

		for (auto& hierarchy : hierarchyList)
		{
			if (hierarchy.second->Tag() != tag) continue;

			auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

			std::cout << tagObject->Name() << " �擾" << std::endl;

			gameObjects.push_back(tagObject);
		}

		std::cout << gameObjects.size() << " ���擾" << std::endl;

		return gameObjects;
	}

	// �`�揇�̃\�[�g
	static void SortingLayerSort();

private:
	enum class UpdateState
	{
		Awake,
		Start,
		Update,
	};
	UpdateState state;

	static std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

};
