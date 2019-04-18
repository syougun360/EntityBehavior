#pragma once
#include <string>

class Object
{
public:
	Object(const std::string &name);
	Object();
	virtual ~Object() = default;


	// 名前を取得
	std::string Name()const
	{
		return name;
	}

private:
	std::string name; // オブジェクトの名前

};

