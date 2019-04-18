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

// �Q�[���I�u�W�F�N�g��Hierarchy�ɓo�^���āA��������
// �߂�l�Ƃ��ẮA�o�^�����Q�[���I�u�W�F�N�g
std::shared_ptr<GameObject> GameObject::Instantiate(std::shared_ptr<EntityHierarchy> gameObject)
{
	std::cout << " Instantiate()" << std::endl;

	Hierarchy::Register(gameObject);
	auto object = Hierarchy::Find(gameObject->Name());
	return object;
}


// �`�揇��ݒ�
void GameObject::SetSortingLayer(SortingLayer sortingLayer)
{
	this->sortingLayer = sortingLayer;
	Hierarchy::SortingLayerSort();
}
