#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using uint_t = std::uint64_t;

using std::cout;
using std::endl;

uint_t collatz(uint_t n)
{
	if (n == 1)	return 1;
	if (n % 2 == 0)	return collatz(n / 2) + 1;
	return  collatz(3 * n + 1);
}

int main()
{
	const uint_t limit{ 1000000 };
	std::vector<uint_t> sequence_lenghts(1000000 + 1, 0);

	for (uint_t i{ 1 }; i < limit; ++i)
		sequence_lenghts[i] = collatz(i);

	auto largest_chain = std::max_element(sequence_lenghts.begin(), sequence_lenghts.end());

	cout << largest_chain - sequence_lenghts.begin() << endl;
	system("PAUSE");
	return 0;
}
