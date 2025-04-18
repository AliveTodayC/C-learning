#include"Team.h"

Team::Team()
{
	members = {};
}

void Team::add(const player& p)
{
	members.push_back(p);
}

void Team::print_team() const
{
	for (const player& e : members)
	{
		std::cout << e.get_name() << "»¹Ê£ÏÂ" << e.get_health()<<std::endl;
	}
}

void Team::remove_dead()
{
	members.erase(
		std::remove_if(members.begin(), members.end(),
			[](const player& e) {return e.is_dead(); })
	);
}
bool Team::is_defeated() const
{
	return members.empty();
}

std::vector<player>& Team::get_members()
{
	return	members;
}