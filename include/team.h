//Enemy.h — 头文件（声明类和接口）
#pragma once
#include"Player.h"
#include<vector>

class Team
{
private:
	std::vector<Player> members;

public:
	//构造函数
	Team();
	void add(const Player& p);
	void print_team()const;
	void remove_dead();
	bool is_defeated()const;
    std::vector<Player>& get_members();
}
;