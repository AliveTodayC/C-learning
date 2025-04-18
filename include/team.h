//Enemy.h — 头文件（声明类和接口）
#pragma once
#include <string>
#include"player.h"
#include<vector>
#include<iostream>
#include<algorithm>

class Team
{
private:
	std::vector<player> members;

public:
	//构造函数
	Team();
	void add(const player& p);
	void print_team()const;
	void remove_dead();
	bool is_defeated()const;
	std::vector<player>& get_members();
}

