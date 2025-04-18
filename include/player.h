//Player.h — 头文件（声明类和接口）
#pragma once
#include <string>
class player	
{
private:
	std::string name;
	int health;
	int level;
	int damage;

public:
	//构造函数
	player(const std::string &n, int hp, int Lv, int dm);
	//成员函数
	void print_info ()const;
	void take_damage(int damage);
	void heal_player(int amount);
	bool is_dead()const;
	//访问器函数，本质上是自己访问自己，获取自己的元素
	std::string get_name()const;
	int get_health()const;
	int get_level()const;
	int get_damage()const;
	void attack(player& target);
};

