// ----------------------------------------------
// 実態の挙動
// 
// 処理系
// 可能 or 不可能 が設定できる
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

	// Startの前に処理が実行させる
	// 1度のみ実行
	virtual void Awake(){}

	// Updateの前に処理が実行させる
	// 1度のみ実行
	virtual void Start(){}
	
	// アップデート
	virtual void Update(){}

	// 実行可能にする
	void Enable();

	// 実行不可能にする
	void Preclude();

	// 実行可能かどうかを取得
	bool IsEnable()const{ return isEnable; }

protected:

private:
	bool isEnable;

};