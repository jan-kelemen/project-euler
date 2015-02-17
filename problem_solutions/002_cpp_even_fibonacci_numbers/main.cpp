#include <iostream>
#include <vector>

std::vector<int> fibonacci_numbers = { 0, 1, 1 };
int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	if (fibonacci_numbers[n] != 0) return fibonacci_numbers[n];
	return fibonacci_numbers[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

void generate()
{
	int i{ 3 };
	do
	{
		fibonacci_numbers.emplace_back(0);
		fibonacci(i++);
	} while (fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1] < 4000000);
}
int main()
{
	generate();
	int sum{ 0 };
	for (const auto &i : fibonacci_numbers)
		sum += i % 2 == 0 ? i : 0;
	std::cout << "Sum of all even Fibonacci numbers up to 4000000 is: " << sum << std::endl;
	return 0;
}
