#include"Skill.h"

Skill::Skill(const std::string& n,int dm,bool aoe,bool heal,int cd_max,int cd):
	name(n),damage(dm),is_aoe(aoe),is_heal(heal),cooldown(cd),cooldown_max(cd_max){ }

std::string Skill::get_name()const
{
	return name;
}
int Skill::get_damage()const
{
	return damage;
}

bool Skill::is_aoe_attack()const
{
	return is_aoe;
}

bool Skill::is_heal_skill()const
{
	return is_heal;
}

bool Skill::can_cast()const
{
	return cooldown == 0;
}

void Skill::reduce_cooldown()
{
	cooldown > 0 && cooldown--;
}

void Skill::reset_cooldown()
{
	cooldown = cooldown_max;
}