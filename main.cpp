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
	const std::string out_request = "[OUT]: ";
	const std::string delimeter = ", ";

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
				int result = math_fn::sqrt<int>(orig);
				overload_throw<int>(orig, result);

				std::cout << out_request << result << std::endl;
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

			std::vector<int> result = math_fn::sqrt<std::vector<int>>(orig);

			std::cout << out_request;
			int i = 0;
			for (int value_result : result)
			{
				try
				{
					overload_throw(orig[i], value_result);
					std::cout << (i == 0 ? "" : delimeter) << value_result;
				}
				catch (const char* e)
				{
					std::cout << e << "\n";
				}

				++i;
			}
			std::cout << "\n";
		}
	}

	return 0;
}
