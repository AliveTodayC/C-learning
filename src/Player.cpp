//2. Player.cpp �� �ඨ���ļ�
 #include"Player.h"
#include"Skill.h"


Player:: Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk) :
	name(n), health(hp), level(Lv), damage(dm),skill(sk){}

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
	if (skill.can_cast())
	{
		if (skill.is_heal_skill())
		{
			std::cout << name << "ʹ�ü���" << skill.get_name()
				<< "����" << target.get_name()
				<< skill.get_damage() << "��Ѫ��" << std::endl;
			target.health += skill.get_damage();
		}
		else
		{
			std::cout << name << "ʹ�ü��ܶ�" << target.get_name()
				<< "�����" << skill.get_damage() << "���˺�\n";
			//target.health -= damage;
			target.take_damage(skill.get_damage());
			std::cout << target.get_name() << "��ʣ��" << target.get_health() << std::endl;
		}
		skill.reset_cooldown();
		return;
	}
	else
	{
		target.take_damage(get_damage());	
		//Ŀǰ����һ�ι�������һ���غ�,���Կ��Բ���Ҫ�غϱ���ȥ������ȴ
		skill.reset_cooldown();
	}
}

