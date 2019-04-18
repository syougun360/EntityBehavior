// ----------------------------------------------
// Hierarchy(階層)
// 
// 登録・削除・全削除
// 階層の実態取得
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

	// 登録
	static void Register(std::shared_ptr<EntityHierarchy> entity);

	// 削除
	static void Deregistration(const std::string& name);

	// 全削除
	static void Clear();

	void Update();
	void Render();

	// 名前で探す
	static std::shared_ptr<EntityHierarchy> Find(const std::string& name);

	// Tagでのゲームオブジェクトを取得
	static std::shared_ptr<EntityHierarchy> FindWithTag(const Tags tag);

	// Tagでのゲームオブジェクトを配列で取得
	static std::vector<std::shared_ptr<EntityHierarchy>> FindGameObjectsWithTag(const Tags tag);

	// 名前で探す
	template<typename Type>
	static std::shared_ptr<Type> Find(const std::string& name)
	{
		std::cout << " Find<T>()" << std::endl;

		auto findObject = hierarchyList.find(name);
		if (findObject == hierarchyList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " 取得" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// 配列を取得
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
			std::cout << target.second->Name().c_str() << " 取得" << std::endl;
		}

		std::cout << components.size << " 個を取得" << std::endl;

		return components;

	}
	// Tagでのゲームオブジェクトを取得
	template<typename Type>
	static std::shared_ptr<Type> FindWithTag(const Tags tag)
	{
		std::cout << " FindWithTag<T>()" << std::endl;

		for (auto& hierarchy : hierarchyList)
		{
			if (hierarchy.second->Tag() != tag) continue;

			auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

			std::cout << tagObject->Name() << " 取得" << std::endl;

			return tagObject;
		}
	}

	// Tagでのゲームオブジェクトを配列で取得
	template<typename Type>
	static std::vector<std::shared_ptr<Type>> FindGameObjectsWithTag(const Tags tag)
	{
		std::cout << " FindGameObjectsWithTag<T>()" << std::endl;

		std::vector<std::shared_ptr<Type>> gameObjects;

		for (auto& hierarchy : hierarchyList)
		{
			if (hierarchy.second->Tag() != tag) continue;

			auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

			std::cout << tagObject->Name() << " 取得" << std::endl;

			gameObjects.push_back(tagObject);
		}

		std::cout << gameObjects.size() << " 個を取得" << std::endl;

		return gameObjects;
	}

	// 描画順のソート
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
