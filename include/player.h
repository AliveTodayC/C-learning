//Player.h �� ͷ�ļ���������ͽӿڣ�
#pragma once
#include <string>
class player	
{
private:
	std::string name;
	int health;
	int level;
	int damage;

public:
	//���캯��
	player(const std::string &n, int hp, int Lv, int dm);
	//��Ա����
	void print_info ()const;
	void take_damage(int damage);
	void heal_player(int amount);
	bool is_dead()const;
	//���������������������Լ������Լ�����ȡ�Լ���Ԫ��
	std::string get_name()const;
	int get_health()const;
	int get_level()const;
	int get_damage()const;
	void attack(player& target);
};

