#pragma once
#include <string>
#include"Player.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<Team.h>
#include<BattleSystem.h>

void Player_attack_all(Player& attacker, std::vector<Player>& targets)
{
	for (Player& enemy : targets)
	{
		attacker.attack(enemy);
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

void const print_battle_state(const Player& hero, const std::vector<Player>& enemies)
{
	std::cout << "\n====== ��ǰ״̬���� ======\n";
	std::cout << "[���Ƕ���]" << std::endl;
	hero.print_info();

	std::cout << "[���˶���]" << std::endl;
	for (const Player& e : enemies) {
		e.print_info();
	}
	std::cout << "===========================\n\n";
}

