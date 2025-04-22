#pragma once
#include<string>
class Skill
{
public:
	//构造函数
	Skill(const std::string& n, int dm, bool is_aoe, bool is_heal);
	//成员函数
	std::string get_name()const;
	int get_damage()const;
	bool is_aoe_attack()const;
	bool is_heal_skill()const;

private:
	std::string name;
	int damage;
	bool is_aoe;
	bool is_heal;
};