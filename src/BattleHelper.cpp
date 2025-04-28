#include<iostream>
#include<algorithm>
#include<vector>
#include"Player.h"
#include"Team.h"


void team_attack(Team& attacker, Team& targets)
{
	if (attacker.is_defeated())
		return;
	for ( Player& atker : attacker.get_members())
	{
		Skill sk = atker.get_skill();
		
		switch (sk.get_skill_type()) 
		{
		case SkillTargetType::EnemySingle:
			//改变0改变攻击对象.加随机数实现随机攻击，后续可以把0换成参数从而指定攻击
			atker.attack(targets.get_members()[0]);		
			//如果攻击对象死亡,删除,数组0的位置会变成数组1的元素
		if (targets.get_members()[0].is_dead())
			targets.remove_dead();
			break;
		case SkillTargetType::EnemyAll:
			atker.attack(targets.get_members());
			targets.remove_dead();
			break;
		case SkillTargetType::AllSingle:
			atker.attack(attacker.get_members()[0]);
			break;
		case SkillTargetType::AllAll:
			for (Player& partner : attacker.get_members())
			{
				atker.attack(partner);
			}
			break;
		case SkillTargetType::self:
			atker.attack(atker);
		}
		//如果敌人全灭,战斗提前结束
		if (attacker.is_defeated())
			break;
	}
}

void enemies_attack(Player& hero, std::vector<Player>& enemies)
{
	for (Player& e : enemies)
	{
		e.attack(hero);
		if (hero.is_dead())
			break;
	}
}

void remove_dead(std::vector<Player>& vec)
{
	vec.erase(
		std::remove_if(
			vec.begin(), vec.end(), [](const Player& e) {return e.is_dead(); }),
		vec.end()
	);
}

void print_battle_state(  Team& hero, Team& enemy)
{
	std::cout << "\n====== 当前状态报告 ======\n";
	std::cout << "[主角队列]" << std::endl;
	for (const Player& player : hero.get_members()) {
		player.print_info();
	}

	std::cout << "[敌人队列]" << std::endl;
	for (const Player& e : enemy.get_members()) {
		e.print_info();
	}
	std::cout << "===========================\n\n";
}

