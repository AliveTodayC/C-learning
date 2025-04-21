#include<iostream>
#include<algorithm>
#include<vector>
#include<Team.h>


void team_attack(Team& attacker, Team& targets)
{
	if (attacker.is_defeated())
		return;
	for (const Player& atker : attacker.get_members())
	{
		//�ı�0�ı乥������.�������ʵ�����������ָ����ʵ��ָ������
		Player& target = targets.get_members()[0];
		atker.attack(target);
		//���������������,ɾ��,����0��λ�û�������1��Ԫ��
		if (target.is_dead())
			attacker.remove_dead();
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

void print_battle_state( Team& hero,Team& enemy)
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

