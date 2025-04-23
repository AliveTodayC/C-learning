//2. Player.cpp — 类定义文件
 #include"Player.h"
#include"Skill.h"


Player:: Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk) :
	name(n), health(hp), level(Lv), damage(dm),skill(sk){}

//访问器函数，安全访问自身数据
std::string Player::get_name()const
{
	return name;
}
int Player::get_health()const
{
	return health > 0 ? health : 0; //控制返回的血量在合理区域内，避免之后打印战斗流程出现负数血量
}
int Player::get_damage()const
{
	return damage;
}
int Player::get_level()const
{
	return level;
}
//成员函数，定义类的行为
void Player:: print_info() const
{
	std::cout << "玩家" << name
		<< "血量" << health
		<< "等级" << level
		<< "攻击"<<damage<<std::endl;
}
void Player::take_damage(int damage)
{
	health -= damage;
}//受到外界伤害，扣血，因为damage是敌人施加的伤害，不是调用函数的对象的damage，所以我认为应该保留参数damage
void Player::heal_player(int amount)
{
	health += amount;
}
bool Player::is_dead()const
{
	return health <=0;
}

void Player::attack(Player& target)
{
	if (skill.can_cast())
	{
		if (skill.is_heal_skill())
		{
			std::cout << name << "使用技能" << skill.get_name()
				<< "治疗" << target.get_name()
				<< skill.get_damage() << "点血量" << std::endl;
			target.health += skill.get_damage();
		}
		else
		{
			std::cout << name << "使用技能对" << target.get_name()
				<< "造成了" << skill.get_damage() << "点伤害\n";
			//target.health -= damage;
			target.take_damage(skill.get_damage());
			std::cout << target.get_name() << "还剩下" << target.get_health() << std::endl;
		}
		skill.reset_cooldown();
		return;
	}
	else
	{
		target.take_damage(get_damage());	
		//目前假设一次攻击就是一个回合,所以可以不需要回合变量去控制冷却
		skill.reset_cooldown();
	}
}

