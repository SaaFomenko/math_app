#include <iostream>
//#include "lib/math_fn.h"


int main()
{
	std::string user_in = "";

	std::cout << "[IN]: ";

	getline(std::cin, user_in);

	std::cout << "[OUT]: " << user_in << std::endl;

	return 0;
}
