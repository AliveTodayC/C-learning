//Player.h �� ͷ�ļ���������ͽӿڣ�
#pragma once
#include <string>
#include<iostream>
#include"Skill.h"
#include<vector>

enum class StrategyType
{
	Aggressive,
	Defensive,
	Random
};

class Player	
{
private:
	std::string name;
	int health;
	int max_health;
	int level;
	int damage;
	Skill skill;
	bool defending;
	bool escaped;
	StrategyType strategy;

public:
	//���캯��
	Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk,StrategyType strategy=StrategyType::Aggressive);
	//���������������������Լ������Լ�����ȡ�Լ���Ԫ��
	std::string get_name()const;
	int get_health()const;
	int get_level()const;
	int get_damage()const;
	Skill get_skill()const;
	//��Ա����
	void print_info()const;
	void take_damage(const int damage);
	void heal_player(const int amount);
	bool is_dead()const;

	void take_action(Player& target);
	void take_action(std::vector<Player>& target);

	void attack(Player& target);
	void attack(std::vector<Player>& t);

	void use_skill_on(Player& t);
	void use_skill_on(std::vector<Player>& t);

	void use_basic_attack_on(Player& t);
	void use_basic_attack_on(std::vector<Player>& t);

	bool should_use_skill(const std::vector<Player>& enemy)const;

	void defend();
	bool is_defending()const;
	void reset_defend_status();
	
	bool flee();
	bool has_flee();

};

