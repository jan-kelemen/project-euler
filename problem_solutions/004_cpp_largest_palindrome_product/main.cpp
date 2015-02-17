#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(int number)
{
	std::string num_str = std::to_string(number);

	auto front_first = num_str.cbegin();
	auto front_last = num_str.cend();
	auto back_first = num_str.crbegin();
	auto back_last = num_str.crend();

	for (; front_first != front_last; ++front_first, ++back_first)
		if (*front_first != *back_first)
			return false;
	return true;
}

int largest_palindrome()
{
	std::vector<int> palindromes;

	for (int i{ 100 }; i != 1000; ++i)
		for (int j{ i + 1 }; j != 1000; ++j)
			if (is_palindrome(i*j) == true)
				palindromes.push_back(i*j);

	return *std::max_element(palindromes.begin(), palindromes.end());
}

int main()
{
	std::cout << "Largest palindrome product of two 3-digit numbers is: " << largest_palindrome() << std::endl;
	return 0;
}
