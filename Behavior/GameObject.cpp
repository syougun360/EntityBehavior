#include "GameObject.h"
#include "Hierarchy.h"
#include "EntityHierarchy.h"
#include "Component.h"

GameObject::GameObject(const std::string &name):
Object(name),
tag(Tags::Default),
sortingLayer(SortingLayer::Default)
{

}

GameObject::GameObject(const std::string &name, Tags tag) :
tag(tag),
Object(name),
sortingLayer(SortingLayer::Default)

{

}


GameObject::GameObject(const std::string &name, SortingLayer sortingLayer) :
tag(Tags::Default),
Object(name),
sortingLayer(sortingLayer)
{

}



GameObject::GameObject(const std::string &name, Tags tag, SortingLayer sortingLayer) :
tag(tag),
Object(name),
sortingLayer(sortingLayer)
{

}


GameObject::GameObject():
Object("GameObject"),
tag(Tags::Default),
sortingLayer(SortingLayer::Default)

{

}

// ゲームオブジェクトをHierarchyに登録して、生成する
// 戻り値としては、登録したゲームオブジェクト
std::shared_ptr<GameObject> GameObject::Instantiate(std::shared_ptr<EntityHierarchy> gameObject)
{
	std::cout << " Instantiate()" << std::endl;

	Hierarchy::Register(gameObject);
	auto object = Hierarchy::Find(gameObject->Name());
	return object;
}


// 描画順を設定
void GameObject::SetSortingLayer(SortingLayer sortingLayer)
{
	this->sortingLayer = sortingLayer;
	Hierarchy::SortingLayerSort();
}
