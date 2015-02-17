#include <iostream>
#include <cmath>
#include <map>
#include <vector>

int triangular_number(int n)
{
	return n*(n + 1) / 2;
}

std::vector<int> generate_primes(int number)
{
	if (number < 10)
		return{ 2, 3, 5, 7 };

	std::vector<bool> numbers(static_cast<size_t>(std::ceil(std::sqrt(number)) + 2), true);
	numbers[0] = numbers[1] = false;

	for (size_t even{ 4 }; even < numbers.size(); even += 2)
		numbers[even] = false;

	std::vector<int> primes{ 2 };
	for (size_t odd{ 3 }; odd < numbers.size(); odd += 2)
		if (numbers[odd] == true)
		{
			primes.emplace_back(static_cast<int>(odd));
			for (size_t multiple{ odd }; multiple < numbers.size(); multiple += odd)
				numbers[multiple] = false;
		}

	return primes;
}

std::map<int, int> prime_factorization(int number)
{
	std::map<int, int> prime_factors;
	for (auto prime : generate_primes(number))
	{
		while (number != 1 && number % prime == 0)
		{
			number /= prime;
			++prime_factors[prime];
		}
	}
	return prime_factors;
}

int number_of_divisors(int number)
{
	int divisors{ 1 };
	for (auto factor : prime_factorization(number))
		divisors *= factor.second + 1;
	return divisors;
}


int main()
{
	int divisors{ 1 };
	for (int i{ 2 }; divisors < 500; ++i)
	{
		int number{ triangular_number(i) };
		divisors = number_of_divisors(number);
		std::cout << i << " " << number << " " << divisors << std::endl;
	}
	return 0;
}