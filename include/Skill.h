#pragma once
#include<string>
class Skill
{
public:
	//构造函数,考虑到后续可能出改变冷却时间的道具，暂时不加const在cooldown_max上
	Skill(const std::string& n, int dm, bool is_aoe=0, bool is_heal=0,int cooldown_max, int cooldown = 0);
	//成员函数
	std::string get_name()const;
	int get_damage()const;
	bool is_aoe_attack()const;
	bool is_heal_skill()const;
	bool can_cast()const;
	void reduce_cooldown();
	void reset_cooldown();

private:
	std::string name;
	int damage;
	bool is_aoe;
	bool is_heal;
	int cooldown_max;
	int cooldown;
};