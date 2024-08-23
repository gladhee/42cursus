#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie {
private:

public:
	Zombie();

	~Zombie();

	Zombie(const Zombie &zombie);

	Zombie &operator=(const Zombie &zombie);

	void announce();
};