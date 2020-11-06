/*
    Author: rustak
    Github: https://github.com/rustakss
*/

#include <map>
#include <string>
#include <iostream>

#include "../headers/_meta.hpp"


class Checkers {
public:
	Checkers () {};
	~Checkers () {};

	bool ValidBSSID (std::string bssid)
	{
		return bssid.length() != 12 ? false : true;
	}

	bool ValidLocation (std::map<std::string, std::string> location)
	{
		return location["longitude"].length() != 0 && location["latitude"].length() != 0 ? true : false;
	}
private:
protected:
};
