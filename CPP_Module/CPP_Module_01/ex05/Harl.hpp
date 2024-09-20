#pragma once

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"

#define DEBUG_H 3052704819
#define INFO_H 1797280078
#define WARNING_H 2095466140
#define ERROR_H 1586791304

#define HARL_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define HARL_INFO "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define HARL_WARNING "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
#define HARL_ERROR "This is unacceptable! I want to speak to the manager now."

#include <iostream>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	void (Harl::*getComplain(const std::string &level)) ();
	size_t getHashLevel(const std::string &level) const;


public:
	Harl();
	~Harl();

	void complain(std::string level);

};
