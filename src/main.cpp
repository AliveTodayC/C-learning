//main.cpp文件
#include"BattleSystem.h"

int main() {
	Team heroTeam;
	heroTeam.add(Player("Yuki", 80, 4, 20));
	heroTeam.add(Player("Claude Yin", 100, 18,30));
	//vector数组初始化的时候元素不能有变量名，即不能是 Player yin，而应该直接写Player
	//vector数组用push_back添加元素，函数的参数包含变量名，意味着元素添加的中间隐含删除变量名的操作？
	Team enemyTeam;
	enemyTeam.add(Player("Aurora Cao", 90, 9, 10)) ;
	enemyTeam.add(Player("Linken wang", 65, 5, 5));
	enemyTeam.add(Player("Dogolas zhang", 65, 5, 5));
	BattleSystem battle(heroTeam, enemyTeam);
	battle.run();
	return 0;
}