//main.cpp文件
#include"BattleSystem.h"
#include"Team.h"
#include"Player.h"


int main() {
	Team heroTeam;
	//为什么const std;:string可以写寒冰术，而std::string写寒冰斩会报错
	Skill frost("寒冰斩", 35, false, false);
	Skill heal("治愈术", 20, false, true);

	heroTeam.add(Player("Claude Yin", 100, 5, 10, frost));
	heroTeam.add(Player("Yuki", 80, 4, 15, heal));
	////vector数组初始化的时候元素不能有变量名，即不能是 Player yin，而应该直接写Player
	////vector数组用push_back添加元素，函数的参数包含变量名，意味着元素添加的中间隐含删除变量名的操作？
	//Team enemyTeam;
	//BattleSystem battle(heroTeam, enemyTeam);
	//battle.run();
	return 0;
}