//2. Player.cpp �� �ඨ���ļ�
 #include"Player.h"
#include<iostream>


Player:: Player(const std::string &n, int hp, int Lv, int dm) :
	name(n), health(hp), level(Lv), damage(dm){}

//��������������ȫ������������
std::string Player::get_name()const
{
	return name;
}
int Player::get_health()const
{
	return health > 0 ? health : 0; //���Ʒ��ص�Ѫ���ں��������ڣ�����֮���ӡս�����̳��ָ���Ѫ��
}
int Player::get_damage()const
{
	return damage;
}
int Player::get_level()const
{
	return level;
}
//��Ա���������������Ϊ
void Player:: print_info() const
{
	std::cout << "���" << name
		<< "Ѫ��" << health
		<< "�ȼ�" << level
		<< "����"<<damage<<std::endl;
}
void Player::take_damage(int damage)
{
	health -= damage;
}//�ܵ�����˺�����Ѫ����Ϊdamage�ǵ���ʩ�ӵ��˺������ǵ��ú����Ķ����damage����������ΪӦ�ñ�������damage
void Player::heal_player(int amount)
{
	health += amount;
}
bool Player::is_dead()const
{
	return health <=0;
}

void Player::attack(Player& target)
{
	std::cout << name << "������" << target.get_name() << std::endl;
	target.health -= damage;
	std::cout << target.get_name() << "��ʣ��" << target.get_health() << std::endl;
}

