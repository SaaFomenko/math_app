#include <iostream>
#include "lib/str_split/str_split.h"
#include "lib/math_fn/math_fn.h"


int main()
{
	const std::string delimeter = ", ";

	std::string user_in = "";

	while(true)
	{
		std::cout << "[IN]: ";
  
		getline(std::cin, user_in);
  
		//	std::cout << "[OUT]: " << user_in << std::endl;
  
		if (user_in.find(delimeter) == std::string::npos)
		{
			try
			{
				int x = std::stoi(user_in);
				std::cout << "[OUT]: " << math_fn::sqrt<int>(x) << std::endl;
			}
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Функция пока не умеет работать с несколькими значениями.\n";
		}
	}

	return 0;
}
