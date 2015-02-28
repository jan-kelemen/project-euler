#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void tens_to_string(std::vector<std::string> &numbers)
{
	const std::vector<std::string> tens{ "", "", "twenty", "thirty", "forty", "fifty", "sixty", \
		"seventy", "eighty", "ninety" };
	for(size_t number{ 20 }; number != 100; ++number)
	{
		if(number % 10 == 0)
		{
			numbers[number] = tens[number / 10];
		}
		else
		{
			numbers[number] = tens[number / 10] + "-" + numbers[number % 10];
		}
	}
}
void hundreds_to_string(std::vector<std::string> &numbers)
{
	for(size_t number{ 100 }; number != 1000; ++number)
	{
		if(number % 100 == 0)
		{
			numbers[number] = numbers[number / 100] + " hundred";
		}
		else
		{
			numbers[number] = numbers[number / 100] + " hundred and " + numbers[number % 100];
		}
	}
}

int count_letters(const std::vector<std::string> &numbers)
{
	int letters{ 0 };
	for(const auto &number : numbers)
	{
		for(const auto letter : number)
		{
			if(std::isalpha(letter))
			{
				++letters;
			}
		}
	}
	return letters;
}

int main()
{
	std::vector<std::string> numbers{ "", "one", "two", "three", "four", "five", \
		"six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", \
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }; //special cases
	numbers.resize(1000 + 1);
	numbers[1000] = "one thousand";
	tens_to_string(numbers);
	hundreds_to_string(numbers);
	std::cout << count_letters(numbers) << std::endl;
	return 0;
}