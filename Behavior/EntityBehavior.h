// ----------------------------------------------
// ���Ԃ̋���
// 
// �����n
// �\ or �s�\ ���ݒ�ł���
// 
// ----------------------------------------------

#pragma once
#include <memory>
#include <string>
#include "Component.h"

class EntityBehavior :public Component
{
public:
	EntityBehavior(const std::string& name);
	EntityBehavior(const std::string& name, const std::string& parentName);

	// Start�̑O�ɏ��������s������
	// 1�x�̂ݎ��s
	virtual void Awake(){}

	// Update�̑O�ɏ��������s������
	// 1�x�̂ݎ��s
	virtual void Start(){}
	
	// �A�b�v�f�[�g
	virtual void Update(){}

	// ���s�\�ɂ���
	void Enable();

	// ���s�s�\�ɂ���
	void Preclude();

	// ���s�\���ǂ������擾
	bool IsEnable()const{ return isEnable; }

protected:

private:
	bool isEnable;

};