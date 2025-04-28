//2. Player.cpp — 类定义文件
 #include"Player.h"
#include"Skill.h"
#include<vector>


Player:: Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk) :
	name(n), health(hp), max_health(hp),level(Lv), damage(dm),skill(sk){}

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
Skill Player::get_skill()const
{
	return skill;
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
void Player::heal_player(const int amount)
{
	health = std::min(max_health, health + amount);
}
bool Player::is_dead()const
{
	return health <=0;
}

//攻击分普工和技能，技能分伤害和治疗，对象分群体和单体
void Player::attack(Player& target)
{
	std::vector<Player> targets = { target };
	if (should_use_skill(targets))
	{
		use_skill_on(target);
	}
	else
	{
		use_basic_attack_on(target);
	}
}
void Player::attack(std::vector<Player>& t)
{
	if (should_use_skill(t))
	{
		use_skill_on(t);
	}
	else
	{
		use_basic_attack_on(t);
	}
}

//技能范围
void Player::use_skill_on(Player& t)
{
	if (skill.is_heal_skill())
	{
		std::cout << name << "使用技能" << skill.get_name()
			<< "治疗" << t.get_name()
			<< skill.get_damage() << "点血量" << std::endl;
		t.heal_player(skill.get_damage());
	}
	else
	{
		std::cout << name << "使用技能对" << t.get_name()
			<< "造成了" << skill.get_damage() << "点伤害\n";
		t.take_damage(skill.get_damage());
		std::cout << t.get_name() << "还剩下" << t.get_health() << std::endl;
	}
	skill.reset_cooldown();
}
void Player::use_skill_on(std::vector<Player>& t)
{
	if (skill.is_heal_skill())
	{
		for (Player& target : t)
		{
			std::cout << name << "使用技能" << skill.get_name()
				<< "治疗" << target.get_name()
				<< skill.get_damage() << "点血量" << std::endl;

			target.heal_player(skill.get_damage());
		}
	}
	else
	{
		for (Player& target : t)
		{
			std::cout << name << "使用技能对" << target.get_name()
				<< "造成了" << skill.get_damage() << "点伤害\n";
			target.take_damage(skill.get_damage());
			std::cout << target.get_name() << "还剩下" << target.get_health() << std::endl;
		}
	}
	skill.reset_cooldown();
}

//普工范围
void Player::use_basic_attack_on(Player & target)
{
	target.take_damage(get_damage());
	//目前假设一次攻击就是一个回合,所以可以不需要回合变量去控制冷却
	skill.reduce_cooldown();
}
void Player::use_basic_attack_on(std::vector<Player>& target)
{
	for (Player& t : target)
	{
		t.take_damage(get_damage());
		//目前假设一次攻击就是一个回合,所以可以不需要回合变量去控制冷却
		skill.reduce_cooldown();
	}
}

//技能使用判断
bool Player::should_use_skill(const std::vector<Player>&enemy)const
{
	if (!skill.can_cast())
		return false;

	if (skill.is_heal_skill() && health < max_health / 2)
	{
		std::cout << name << " 因血量低于 50%，释放了技能「" << skill.get_name() << "」。\n";
		return true;
	}

	if (skill.is_aoe_attack() && enemy.size() >= 2)
	{
		std::cout << name << "技能是aoe且敌方数量大于二,释放了技能[" << skill.get_name() << "」。\n";
	}
		return true;

	std::cout << name << " 使用普通攻击，因为技能冷却中或无适合释放时机。\n";
	return false;
}