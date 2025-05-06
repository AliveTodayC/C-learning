//2. Player.cpp �� �ඨ���ļ�
 #include"Player.h"
#include"Skill.h"
#include<vector>
#include<random>

//�������ȡ����
int get_random_number(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<>	dis(min, max);
	return dis(gen);
}

Player:: Player(const std::string &n, int hp, int Lv, int dm,const Skill& sk,StrategyType st) :
	name(n), health(hp), max_health(hp),level(Lv), damage(dm),
	skill(sk),strategy(st),defending(false),escaped(false){}

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
	if (is_defending())
		health -= damage / 2;
	else
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

//��Ϊ�ж�
void Player::take_action(Player& target)
{
	switch (strategy)
	{
	case StrategyType::Aggressive:
	{
		attack(target);
		break;
	}

	case StrategyType::Defensive:
	{
		if (health < max_health * 0.5)
		{
			if (flee())
			{

				std::cout << name << "Ѫ�����ͣ����ܳɹ���\n";
				return;
			}
			else
			{
				defend();
				std::cout << name << "�������״̬�������ܵ��˺���\n";
				return;
			}
		}
		attack(target);
		break;
	}
	case StrategyType::Random:
	{
		int rd=get_random_number(0, 2);
		if (rd == 0)
		{
			std::cout << name << " ѡ���˹���" << std::endl;
			attack(target);
		}
		if (rd == 1)
		{
			defend();
			std::cout << name << " ѡ���˷���" << std::endl;
		}
		else
		{
			flee();
			std::cout << name << " ѡ��������" << std::endl;
		}
		break;
	}
	}
	
	;
}
void Player::take_action(std::vector<Player>& target)
{
	if (health < max_health * 0.3 && flee())
	{
		std::cout << name << "Ѫ�����ͣ����ܳɹ���\n";
		return;
	}
	if (health < 0.5 * max_health)
	{
		defend();
		std::cout << name << "�������״̬�������ܵ��˺���\n";
	}
	attack(target);
}

//ս����Ϊ���������չ��ͼ��ܣ����ܷ��˺������ƣ������Ⱥ��͵���
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
		return true;
	}

	std::cout << name << " ʹ����ͨ��������Ϊ������ȴ�л����ʺ��ͷ�ʱ����\n";
	return false;
}

//����״̬����
void Player::defend()
{
	defending = 1;
}

bool Player::is_defending()const
{
	return defending;
}

void Player::reset_defend_status()
{
	defending = 0;
}

//���ܺ���
bool Player::flee()
{
	if (get_random_number(0, 99) % 100 <= 35)
	{
		escaped = true;
		return true;
	}
	return false;
}

bool Player::has_flee()
{
	return escaped;
}