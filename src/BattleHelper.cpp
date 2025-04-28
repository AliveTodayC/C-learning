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
			//�ı�0�ı乥������.�������ʵ������������������԰�0���ɲ����Ӷ�ָ������
			atker.attack(targets.get_members()[0]);		
			//���������������,ɾ��,����0��λ�û�������1��Ԫ��
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
		//�������ȫ��,ս����ǰ����
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
	std::cout << "\n====== ��ǰ״̬���� ======\n";
	std::cout << "[���Ƕ���]" << std::endl;
	for (const Player& player : hero.get_members()) {
		player.print_info();
	}

	std::cout << "[���˶���]" << std::endl;
	for (const Player& e : enemy.get_members()) {
		e.print_info();
	}
	std::cout << "===========================\n\n";
}

