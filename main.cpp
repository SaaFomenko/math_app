#include <iostream>
#include "lib/str_split/str_split.h"
#include "lib/math_fn/math_fn.cpp"


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
				int x = std::stoi(user_in);
				std::cout << out_request << math_fn::sqrt<int>(x) << std::endl;
			}
			catch(std::invalid_argument const& ex)
      {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
      }
      catch(std::out_of_range const& ex)
      {
        std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
      }
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::vector<int> values;

			for (std::string value_str : str_split(user_in, delimeter))
			{
				try
				{
					int x = std::stoi(value_str);
					values.push_back(x);
				}
				catch(std::invalid_argument const& ex)
        {
          std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
        }
        catch(std::out_of_range const& ex)
        {
          std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
        }
				catch (std::exception e)
				{
					std::cout << e.what() << std::endl;
				}
			}

			math_fn::sqrt<std::vector<int>&>(values);

			std::cout << out_request;
			int i = 0;
			for (int value : values)
			{
				std::cout << (i == 0 ? "" : delimeter) << value;
				++i;
			}
			std::cout << "\n";
		}
	}

	return 0;
}
