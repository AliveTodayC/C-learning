//Enemy.h �� ͷ�ļ���������ͽӿڣ�
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
	//���캯��
	Team();
	void add(const player& p);
	void print_team()const;
	void remove_dead();
	bool is_defeated()const;
	std::vector<player>& get_members();
}

