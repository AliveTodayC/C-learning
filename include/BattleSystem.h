#pragma once
#include"BattleHelper.h"
class BattleSystem
{
private:
	Team hero;
	Team enemy;
	int round_count;
public:
	//构造函数
	BattleSystem(Team& h, Team& e);
	//成员函数
	void run();
	void run_round();
	bool is_over() const;
	void report();

};