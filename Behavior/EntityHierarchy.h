// ----------------------------------------------
// ���Ԃ̊K�w
// 
// �K�w�ɓ���N���X�Ɍp���������
// �A�N�e�B�u�E��A�N�e�B�u��ݒ�ł���
//
// ----------------------------------------------

#pragma once
#include "Component.h"

class EntityHierarchy :public Component
{
public:
	EntityHierarchy(const std::string& name, const Tags tag);
	EntityHierarchy(const std::string& name, const SortingLayer sortingLayer);
	EntityHierarchy(const std::string& name, const Tags tag, const SortingLayer sortingLayer);

	// �`��
	void Updatable();
	
	// �`��
	void Renderable();

protected:
	// Start�̑O�ɏ��������s������
	virtual void Awake(){}

	// Update�̑O�ɏ��������s������
	virtual void Start(){}
	
	// �A�b�v�f�[�g
	virtual void Update(){}
	
	// �`��
	virtual void Render(){}

	// �A�N�e�B�u�ɂ���
	void Active();

	// ��A�N�e�B�u�ɂ���
	void NonActive();

	// �A�N�e�B�u���擾
	bool IsActive()const{ return isActive; }

private:
	enum class UpdateState
	{
		Awake,
		Start,
		Update,
	};

	UpdateState state;
	bool isActive;
};

