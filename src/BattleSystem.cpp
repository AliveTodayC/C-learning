#include"BattleSystem.h"
#include"Player.h"
#include"Team.h"
#include<iostream>
#include"BattleHelper.h"

//���캯��
BattleSystem::BattleSystem(Team& h, Team& e) :
	hero(h), enemy(e) ,round_count(1){}

void BattleSystem::run()
{
	while (!is_over())
	{
		std::cout << "=========��" << round_count++ << "�غ�=========" << std::endl;
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
	////�����ǳ���Ȩ�Ⱥ�Ĭ���������ȹ�
	team_attack(hero, enemy);
	team_attack(enemy, hero);
	print_battle_state(hero, enemy);
}

void BattleSystem::report()
{
	//������ƽ�ֺ�ʱ�����Ƶ����
	if (enemy.is_defeated())
	{
		std::cout << "����ȫ��ս��ʤ��" << std::endl;
		for (Player& h : hero.get_members())
			h.print_info();
	}
	else
	{
		std::cout << "���Ķ�Աȫ��������ս��ʧ��" << std::endl;
		for (Player& e : enemy.get_members())
			e.print_info();
	}
}