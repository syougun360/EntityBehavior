// ----------------------------------------------
// GameObject
// 
// オブジェクトのデータ
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Tag.h"
#include "Layer.h"
#include "Object.h"

class Component;
class EntityHierarchy;

class GameObject:public Object
{
public:
	GameObject(const std::string &name);
	GameObject(const std::string &name, Tags tag);
	GameObject(const std::string &name, Tags tag, SortingLayer sortingLayer);
	GameObject(const std::string &name, SortingLayer sortingLayer);
	GameObject();

	Tags GetTag()const
	{
		return tag;
	}

	SortingLayer GetSortingLayer()const
	{
		return sortingLayer;
	}

	// 描画順を設定
	void SetSortingLayer(SortingLayer sortingLayer);

	// ゲームオブジェクトをHierarchyに登録して、生成する
	// 戻り値としては、登録したゲームオブジェクト
	static std::shared_ptr<GameObject> Instantiate(std::shared_ptr<EntityHierarchy> gameObject);

protected:
	Tags tag; // オブジェクトのタグ

private:
	SortingLayer sortingLayer; // 描画順レイヤー

};

