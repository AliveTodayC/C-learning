//2. Player.cpp �� �ඨ���ļ�
 #include"player.h"
#include<iostream>


player:: player(const std::string &n, int hp, int Lv, int dm) :
	name(n), health(hp), level(Lv), damage(dm){}

//��������������ȫ������������
std::string player::get_name()const
{
	return name;
}
int player::get_health()const
{
	return health > 0 ? health : 0; //���Ʒ��ص�Ѫ���ں��������ڣ�����֮���ӡս�����̳��ָ���Ѫ��
}
int player::get_damage()const
{
	return damage;
}
int player::get_level()const
{
	return level;
}
//��Ա���������������Ϊ
void player:: print_info() const
{
	std::cout << "���" << name
		<< "Ѫ��" << health
		<< "�ȼ�" << level
		<< "����"<<damage<<std::endl;
}
void player::take_damage(int damage)
{
	health -= damage;
}//�ܵ�����˺�����Ѫ����Ϊdamage�ǵ���ʩ�ӵ��˺������ǵ��ú����Ķ����damage����������ΪӦ�ñ�������damage
void player::heal_player(int amount)
{
	health += amount;
}
bool player::is_dead()const
{
	return health <=0;
}

void player::attack(player& target)
{
	std::cout << name << "������" << target.get_name() << std::endl;
	target.health -= damage;
	std::cout << target.get_name() << "��ʣ��" << target.get_health() << std::endl;
}

