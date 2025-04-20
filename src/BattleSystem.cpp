#include"BattleSystem.h"

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
	//�����ǳ���Ȩ�Ⱥ�Ĭ���������ȹ�
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
	//������ƽ�ֺ�ʱ�����Ƶ����
	if (enemy.is_defeated())
	{
		std::cout << "����ȫ��ս��ʤ��" << std::endl;
		for (Player& const h : hero.get_members())
			h.print_info();
	}
	else
	{
		std::cout << "���Ķ�Աȫ��������ս��ʧ��" << std::endl;
		for (Player& const e : enemy.get_members())
			e.print_info();
	}
}