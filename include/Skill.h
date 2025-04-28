#pragma once
#include<string>
enum class SkillTargetType
{
	EnemySingle,
	EnemyAll,
	AllSingle,
	AllAll,
	self

};

class Skill
{
public:
	//���캯��,���ǵ��������ܳ��ı���ȴʱ��ĵ��ߣ���ʱ����const��cooldown_max��
	Skill(const std::string& n, int dm, bool is_aoe=0, bool is_heal=0,
		int cooldown_max, int cooldown = 0,SkillTargetType st);
	//��Ա����
	std::string get_name()const;
	int get_damage()const;
	bool is_aoe_attack()const;
	bool is_heal_skill()const;
	bool can_cast()const;
	void reduce_cooldown();
	void reset_cooldown();
	SkillTargetType get_skill_type()const;

private:
	std::string name;
	int damage;
	bool is_aoe;
	bool is_heal;
	int cooldown_max;
	int cooldown;
	SkillTargetType skill_type;
};