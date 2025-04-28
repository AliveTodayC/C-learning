//2. Player.cpp �� �ඨ���ļ�
 #include"Player.h"
#include"Skill.h"
#include<vector>


Player:: Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk) :
	name(n), health(hp), max_health(hp),level(Lv), damage(dm),skill(sk){}

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
Skill Player::get_skill()const
{
	return skill;
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
void Player::heal_player(const int amount)
{
	health = std::min(max_health, health + amount);
}
bool Player::is_dead()const
{
	return health <=0;
}

//�������չ��ͼ��ܣ����ܷ��˺������ƣ������Ⱥ��͵���
void Player::attack(Player& target)
{
	std::vector<Player> targets = { target };
	if (should_use_skill(targets))
	{
		use_skill_on(target);
	}
	else
	{
		use_basic_attack_on(target);
	}
}
void Player::attack(std::vector<Player>& t)
{
	if (should_use_skill(t))
	{
		use_skill_on(t);
	}
	else
	{
		use_basic_attack_on(t);
	}
}

//���ܷ�Χ
void Player::use_skill_on(Player& t)
{
	if (skill.is_heal_skill())
	{
		std::cout << name << "ʹ�ü���" << skill.get_name()
			<< "����" << t.get_name()
			<< skill.get_damage() << "��Ѫ��" << std::endl;
		t.heal_player(skill.get_damage());
	}
	else
	{
		std::cout << name << "ʹ�ü��ܶ�" << t.get_name()
			<< "�����" << skill.get_damage() << "���˺�\n";
		t.take_damage(skill.get_damage());
		std::cout << t.get_name() << "��ʣ��" << t.get_health() << std::endl;
	}
	skill.reset_cooldown();
}
void Player::use_skill_on(std::vector<Player>& t)
{
	if (skill.is_heal_skill())
	{
		for (Player& target : t)
		{
			std::cout << name << "ʹ�ü���" << skill.get_name()
				<< "����" << target.get_name()
				<< skill.get_damage() << "��Ѫ��" << std::endl;

			target.heal_player(skill.get_damage());
		}
	}
	else
	{
		for (Player& target : t)
		{
			std::cout << name << "ʹ�ü��ܶ�" << target.get_name()
				<< "�����" << skill.get_damage() << "���˺�\n";
			target.take_damage(skill.get_damage());
			std::cout << target.get_name() << "��ʣ��" << target.get_health() << std::endl;
		}
	}
	skill.reset_cooldown();
}

//�չ���Χ
void Player::use_basic_attack_on(Player & target)
{
	target.take_damage(get_damage());
	//Ŀǰ����һ�ι�������һ���غ�,���Կ��Բ���Ҫ�غϱ���ȥ������ȴ
	skill.reduce_cooldown();
}
void Player::use_basic_attack_on(std::vector<Player>& target)
{
	for (Player& t : target)
	{
		t.take_damage(get_damage());
		//Ŀǰ����һ�ι�������һ���غ�,���Կ��Բ���Ҫ�غϱ���ȥ������ȴ
		skill.reduce_cooldown();
	}
}

//����ʹ���ж�
bool Player::should_use_skill(const std::vector<Player>&enemy)const
{
	if (!skill.can_cast())
		return false;

	if (skill.is_heal_skill() && health < max_health / 2)
	{
		std::cout << name << " ��Ѫ������ 50%���ͷ��˼��ܡ�" << skill.get_name() << "����\n";
		return true;
	}

	if (skill.is_aoe_attack() && enemy.size() >= 2)
	{
		std::cout << name << "������aoe�ҵз��������ڶ�,�ͷ��˼���[" << skill.get_name() << "����\n";
	}
		return true;

	std::cout << name << " ʹ����ͨ��������Ϊ������ȴ�л����ʺ��ͷ�ʱ����\n";
	return false;
}