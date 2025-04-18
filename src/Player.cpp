//2. Player.cpp — 类定义文件
 #include"player.h"
#include<iostream>


player:: player(const std::string &n, int hp, int Lv, int dm) :
	name(n), health(hp), level(Lv), damage(dm){}

//访问器函数，安全访问自身数据
std::string player::get_name()const
{
	return name;
}
int player::get_health()const
{
	return health > 0 ? health : 0; //控制返回的血量在合理区域内，避免之后打印战斗流程出现负数血量
}
int player::get_damage()const
{
	return damage;
}
int player::get_level()const
{
	return level;
}
//成员函数，定义类的行为
void player:: print_info() const
{
	std::cout << "玩家" << name
		<< "血量" << health
		<< "等级" << level
		<< "攻击"<<damage<<std::endl;
}
void player::take_damage(int damage)
{
	health -= damage;
}//受到外界伤害，扣血，因为damage是敌人施加的伤害，不是调用函数的对象的damage，所以我认为应该保留参数damage
void player::heal_player(int amount)
{
	health += amount;
}
bool player::is_dead()const
{
	return health <=0;
}

void player::attack(player& target)
{
	std::cout << name << "攻击了" << target.get_name() << std::endl;
	target.health -= damage;
	std::cout << target.get_name() << "还剩下" << target.get_health() << std::endl;
}

