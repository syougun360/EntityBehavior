// ----------------------------------------------
// GameObject
// 
// �I�u�W�F�N�g�̃f�[�^
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

	// �`�揇��ݒ�
	void SetSortingLayer(SortingLayer sortingLayer);

	// �Q�[���I�u�W�F�N�g��Hierarchy�ɓo�^���āA��������
	// �߂�l�Ƃ��ẮA�o�^�����Q�[���I�u�W�F�N�g
	static std::shared_ptr<GameObject> Instantiate(std::shared_ptr<EntityHierarchy> gameObject);

protected:
	Tags tag; // �I�u�W�F�N�g�̃^�O

private:
	SortingLayer sortingLayer; // �`�揇���C���[

};

