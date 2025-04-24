//Player.h �� ͷ�ļ���������ͽӿڣ�
#pragma once
#include <string>
#include<iostream>
#include"Skill.h"
#include<vector>

class Player	
{
private:
	std::string name;
	int health;
	int level;
	int damage;
	Skill skill;

public:
	//���캯��
	Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk);
	//���������������������Լ������Լ�����ȡ�Լ���Ԫ��
	std::string get_name()const;
	int get_health()const;
	int get_level()const;
	int get_damage()const;
	Skill get_skill()const;
	//��Ա����
	void print_info()const;
	void take_damage(int damage);
	void heal_player(int amount);
	bool is_dead()const;
	void attack(Player& target);
	void use_skill_on(Player& t);
	void use_skill_on(std::vector<Player>& t);
};

