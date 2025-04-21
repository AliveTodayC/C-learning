#include"Team.h"
//构造函数
Team::Team()
{
	members = {};
}
//成员函数
void Team::add(const Player& p)
{
	members.push_back(p);
}

void Team::print_team() const
{
	for (const Player& e : members)
	{
		std::cout << e.get_name() << "还剩下" << e.get_health()<<std::endl;
	}
}

void Team::remove_dead()
{
	members.erase(
		std::remove_if(members.begin(), members.end(),
			[](const Player& e) {return e.is_dead(); }),
		members.end()
	);
}
bool Team::is_defeated() const
{
	return members.empty();
}

std::vector<Player>& Team::get_members()
{
	return	members;
}