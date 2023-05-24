#include <iostream>
#include "lib/str_split/str_split.h"
#include "lib/math_fn/math_fn.cpp"


static const char* err = "Error: variable overload.";

template<class T>
void overload_throw(T orig, T result)
{
	if (result < 0 || (orig != 0 && result == 0))
	{
		throw err;
	}
}

int main()
{
	const std::string in_quest = "[IN]: ";
	const std::string out_sum = "[OUT]: get_sum() =  ";
	const std::string out_count = "[OUT]: get_count() =  ";
	const std::string delimeter = " ";
	int devider = 3;

	std::string user_in = "";

	while(true)
	{
		std::cout << in_quest;
  
		getline(std::cin, user_in);
  
		if (user_in.find(delimeter) == std::string::npos)
		{
			try
			{
				int orig = std::stoi(user_in);

				std::cout << out_sum << orig << std::endl;

				int count = 0;
				if ((orig % devider) == 0) ++count;


				std::cout << out_count << count << std::endl;
			}
			catch(std::invalid_argument const& ex)
			{
				std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
      
			}
			catch(std::out_of_range const& ex)
			{
				std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
			}
			catch (const char* e)
			{
				std::cout << e << "\n";
			}
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::vector<int> orig{};

			for (std::string value_str : str_split(user_in, delimeter))
			{
				try
				{
					int x = std::stoi(value_str);

					orig.push_back(x);
				}
				catch(std::invalid_argument const& ex)
				{
					std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
				}
				catch(std::out_of_range const& ex)
				{
					std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
				}
				catch (const char* e)
				{
					std::cout << e << "\n";
				}
				catch (std::exception e)
				{
					std::cout << e.what() << std::endl;
				}
			}

			math_fn::SumCountD get_sum(orig);
			int sum_result = get_sum();
			std::cout << out_sum << sum_result << std::endl;

			math_fn::SumCountD get_count(orig, devider);
			int count_result = get_count();
			std::cout << out_count << count_result << std::endl;
		}
	}

	return 0;
}
