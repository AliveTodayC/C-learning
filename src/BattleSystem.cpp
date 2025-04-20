#include"BattleSystem.h"

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
	//不考虑出手权先后，默认主角团先攻
	for (Player& h : hero.get_members())
	{
		Player_attack_all(h, enemy.get_members());
		remove_dead(enemy.get_members());
		if (enemy.is_defeated())
			break;
	}
	for (Player& e : enemy.get_members())
	{
		Player_attack_all(e, hero.get_members());
		remove_dead(hero.get_members());
		if (hero.is_defeated())
			break;
	}
}

void BattleSystem::report()
{
	//不考虑平局和时间限制的情况
	if (enemy.is_defeated())
	{
		std::cout << "敌人全灭，战斗胜利" << std::endl;
		for (Player& const h : hero.get_members())
			h.print_info();
	}
	else
	{
		std::cout << "您的队员全部阵亡，战斗失败" << std::endl;
		for (Player& const e : enemy.get_members())
			e.print_info();
	}
}