//Enemy.h �� ͷ�ļ���������ͽӿڣ�
#pragma once
#include"Player.h"
#include<vector>

class Team
{
private:
	std::vector<Player> members;

public:
	//���캯��
	Team();
	void add(const Player& p);
	void print_team()const;
	void remove_dead();
	bool is_defeated()const;
    std::vector<Player>& get_members();
}
;