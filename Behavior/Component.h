// ----------------------------------------------
// コンポーネント
// 
// 追加、削除、取得、親の取得ができる
// 
// ----------------------------------------------

#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include "GameObject.h"

class EntityBehavior;

class Component :public GameObject
{
public:
	Component(const std::string &name);
	Component(const std::string &name, Tags tag);
	Component(const std::string &name, SortingLayer sortingLayer);
	Component(const std::string &name, Tags tag, SortingLayer sortingLayer);
	Component(const std::string &name, const std::string& parentName);
	Component();
	
	// 追加
	void AddComponent(std::shared_ptr<EntityBehavior> gameObject);

	// 削除
	void Destroy();

	// 名前で削除
	void Destroy(const std::string &name);


	// 親を取得
	std::shared_ptr<Component> GetComponentInParent()const ;

	// 取得
	template<typename Type>
	std::shared_ptr<Type> GetComponent(const std::string& name)
	{
		std::cout << " GetComponent<T>()" << std::endl;

		auto findObject = childrenList.find(name);
		if (findObject == childrenList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " 取得" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// 配列を取得
	template<typename Type>
	std::vector<std::shared_ptr<Type>> GetComponents(const std::string& name)
	{
		std::cout << " GetComponents<T>()" << std::endl;

		auto findObjects = childrenList.equal_range(name);
		std::vector<std::shared_ptr<Type>> components;
		
		components.clear();

		for (auto iterator = findObjects.first; iterator != findObjects.second; iterator++)
		{
			auto target = *iterator;
			components.push_back(std::dynamic_pointer_cast<Type>(target.second));
			std::cout << target.second->Name().c_str() << " 取得" << std::endl;
		}

		std::cout << components.size() << " 個を取得" << std::endl;

		return components;
	}

	// 取得
	template<typename Type>
	std::shared_ptr<Type> GetComponent()
	{
		std::cout << " GetComponent<T>()" << std::endl;

		std::cout << gameObject->Name().c_str() << " 取得" << std::endl;

		return std::dynamic_pointer_cast<Type>(gameObject);
	}

protected:
	void ComponentsAwake();
	void ComponentsStart();
	void ComponentsUpdate();

private:
	std::unordered_multimap<std::string, std::shared_ptr<EntityBehavior>> childrenList;
	std::shared_ptr<GameObject> gameObject;
	std::string parentName;

};

