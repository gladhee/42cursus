#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

#define SOUND "BraiiiiiiinnnzzzZ..."

class Zombie {
private:
	std::string _name;

public:
	Zombie();

	Zombie(std::string name);

	~Zombie();

	Zombie(const Zombie &zombie);

	Zombie &operator=(const Zombie &zombie);

	void announce(void);
};

#endif