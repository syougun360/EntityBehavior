#pragma once
#include <string>

class Object
{
public:
	Object(const std::string &name);
	Object();
	virtual ~Object() = default;


	// ���O���擾
	std::string Name()const
	{
		return name;
	}

private:
	std::string name; // �I�u�W�F�N�g�̖��O

};

