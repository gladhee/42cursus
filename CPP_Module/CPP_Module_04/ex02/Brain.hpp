#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

private:
	static const int MAX_IDEAS = 100;
	std::string ideas[MAX_IDEAS];


public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string getIdea(const int index) const;
	void setIdea(const int index, const std::string idea);

};

#endif
