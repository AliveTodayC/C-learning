#pragma once
#include"BattleHelper.h"
class BattleSystem
{
private:
	Team hero;
	Team enemy;
	int round_count;
public:
	//���캯��
	BattleSystem(Team& h, Team& e);
	//��Ա����
	void run();
	void run_round();
	bool is_over() const;
	void report();

};