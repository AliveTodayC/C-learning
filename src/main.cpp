//main.cpp文件
#include"player.h"
#include<iostream>
#include<algorithm>
#include<vector>

void player_attack_all(player& attacker, std::vector<player>& targets)
{
	for ( player& enemy : targets)
	{
		attacker.attack(enemy);
	}
}

void enemies_attack(player& hero, std::vector<player>& enemies)
{
	for ( player& e : enemies)
	{
		 e.attack(hero);
		if (hero.is_dead())
			break;
	}
}

void remove_dead(std::vector<player>& vec)
{
	vec.erase(
		std::remove_if(
			vec.begin(), vec.end(),[](const player& e) {return e.is_dead(); }),
		vec.end()
	);
}

void print_battle_state(const player& hero, const std::vector<player>& enemies)
{
	std::cout << "\n====== 当前状态报告 ======\n";
	std::cout << "[主角]" << std::endl;
	hero.print_info();

	std::cout << "[敌人队列]" << std::endl;
	for (const player& e : enemies) {
		e.print_info();
	}
	std::cout << "===========================\n\n";
}

int main() {
	player gamer("Claude Yin", 100, 18,30);
	//vector数组初始化的时候元素不能有变量名，即不能是 player yin，而应该直接写player
	//vector数组用push_back添加元素，函数的参数包含变量名，意味着元素添加的中间隐含删除变量名的操作？
	std::vector<player> enemy =
	{
		player("Aurora Cao", 90, 9, 10),
		player("Linken wang", 65, 5, 5),
		player("Dogolas zhang", 65, 5, 5)
	};
	//准备战斗
	int round = 0;
	while (!enemy.empty() && !gamer.is_dead())
	{
		std::cout << "第" << ++round << "回合" << std::endl;
		for (player &e : enemy)
		{
			gamer.attack(e);
		}
		enemy.erase(
			std::remove_if(enemy.begin(), enemy.end(),
				[](const player& e) {return e.is_dead(); }),
			enemy.end()
		);
		if (enemy.empty() )
			break;
		for (player& e : enemy)
		{
			e.attack(gamer);
			if (gamer.is_dead())
				break;
		}
	}
	std::cout << "战斗持续" << round << "回合" << std::endl;
	std::cout << "\n[玩家状态]\n";
	gamer.print_info();
	if (enemy.empty())
		std::cout << "敌人全部阵亡，" << gamer.get_name() << "获胜" << std::endl;
	if (gamer.is_dead())
		std::cout << gamer.get_name() << "已经阵亡，战斗失败" 
		<<"剩余"<<enemy.size()<<"敌人" << std::endl;

	return 0;
}