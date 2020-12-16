/*
    Author: rustzz
    Github: https://github.com/rustzz
*/

#define WORK true

#include <iostream>
#include <string>

#include "../headers/Main.hpp"
#include "BSSID.cpp"


int main (int argc, char * argv[])
{
	motd();
	std::cout << std::endl;
	std::cout << std::endl;
	
	BSSID bssid;
	std::string bssid_code;

	while (WORK)
	{
		std::cout << "BSSID: "; std::getline(std::cin, bssid_code);
		std::cout << bssid.Get(bssid_code);
	}
    return 0;
}
