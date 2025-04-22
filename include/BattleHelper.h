#pragma once
#include<vector>
#include"Team.h"
#include"Player.h"

void team_attack(Team& attacker, Team& targets);

void enemies_attack(Player& hero, std::vector<Player>& enemies);

void remove_dead(std::vector<Player>& vec);

void print_battle_state(Team& hero,Team& enemy);
