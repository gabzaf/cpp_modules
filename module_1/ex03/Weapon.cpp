
#include "Weapon.hpp"

Weapon::Weapon(std:string type)
{
	this->type = type;
}

Weapon::~Weapon() {}

const std::string &Weapon::get_type()
{
	return (this->type);
}

void	Weapon::set_type(std::string ntype)
{
	this->type = ntype;
}
