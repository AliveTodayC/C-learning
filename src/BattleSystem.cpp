#include"BattleSystem.h"
#include"Player.h"
#include"Team.h"
#include<iostream>
#include"BattleHelper.h"

//构造函数
BattleSystem::BattleSystem(Team& h, Team& e) :
	hero(h), enemy(e) ,round_count(1){}

void BattleSystem::run()
{
	while (!is_over())
	{
		std::cout << "=========第" << round_count++ << "回合=========" << std::endl;
		run_round();
	}
	report();
}

bool BattleSystem::is_over()const
{
	return hero.is_defeated() || enemy.is_defeated();
}

void BattleSystem::run_round()
{
	////不考虑出手权先后，默认主角团先攻
	team_attack(hero, enemy);
	team_attack(enemy, hero);
	print_battle_state(hero, enemy);
}

void BattleSystem::report()
{
	//不考虑平局和时间限制的情况
	if (enemy.is_defeated())
	{
		std::cout << "敌人全灭，战斗胜利" << std::endl;
		for (Player& h : hero.get_members())
			h.print_info();
	}
	else
	{
		std::cout << "您的队员全部阵亡，战斗失败" << std::endl;
		for (Player& e : enemy.get_members())
			e.print_info();
	}
}