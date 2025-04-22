#include"Skill.h"

Skill::Skill(const std::string& n,int dm,bool aoe,bool heal):
	name(n),damage(dm),is_aoe(aoe),is_heal(heal){ }

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