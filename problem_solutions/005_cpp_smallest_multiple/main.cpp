#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

	std::vector<int> divisors;

	for (auto prime : primes)
	{
		bool successful_division{ false };
		do
		{
			successful_division = false;
			for (auto &number : numbers)
			{
				if (number % prime == 0)
				{
					number /= prime;
					successful_division = true;
				}
			}
			if (successful_division == true)
				divisors.emplace_back(prime);
		} while (successful_division == true);

		int number_of_ones{ 0 };
		for (auto number : numbers)
			if (number == 0)
				++number_of_ones;
		if (number_of_ones == numbers.size())
			break;
	}

	int smallest_multiple{ 1 };
	for (auto divisor : divisors)
		smallest_multiple *= divisor;

	std::cout << smallest_multiple << std::endl;
	return 0;
}