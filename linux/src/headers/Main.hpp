/*
    Author: rustak
    Github: https://github.com/rustakss
*/

#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <iostream>

#include "_meta.hpp"

void motd ()
{
	const std::string HELP = "История поиска сохраняется в\n  домашний каталог текущего пользователя\n  в файл ~/history.";

	std::string out;
	out = "||||||||";
	for (int i = 0; i < static_cast<int>(_AUTHOR.length()); i++)
		out += "|";
	out += "\n||  " + _AUTHOR + "  ||\n||||||||";
	for (int i = 0; i < static_cast<int>(_AUTHOR.length()); i++)
		out += "|";
	std::cout << out << std::endl << std::endl << HELP;
}

#endif
