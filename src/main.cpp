//main.cpp文件
#include"BattleSystem.h"

int main() {
	Player gamer("Claude Yin", 100, 18,30);
	//vector数组初始化的时候元素不能有变量名，即不能是 Player yin，而应该直接写Player
	//vector数组用push_back添加元素，函数的参数包含变量名，意味着元素添加的中间隐含删除变量名的操作？
	Player AC("Aurora Cao", 90, 9, 10) ;
	Player LW("Linken wang", 65, 5, 5) ;
	Player DZ("Dogolas zhang", 65, 5, 5);
	Team hero_array;
	hero_array.add(gamer);
	Team enemy_array;
	enemy_array.add(AC);
	enemy_array.add(LW);
	enemy_array.add(DZ);
	BattleSystem battle(hero_array, enemy_array);
	battle.run();
	return 0;
}