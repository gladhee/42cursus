#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

#define SOUND "BraiiiiiiinnnzzzZ..."

class Zombie {
private:
	std::string _name;


public:
	Zombie();

	Zombie(const std::string &name);

	~Zombie();

	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif