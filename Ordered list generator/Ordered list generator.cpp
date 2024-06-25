#include <iostream>
#include <vector>
#include <algorithm>

void PrintRndByEleven(const int n /* generate n numbers */)
{
	std::vector<int> v;	// Vector to hold random numbers

	static bool firstCall = true;
	if (firstCall)
	{
		std::srand(time(0));	// Make numbers more random - call this once when the program starts
		firstCall = false;
	}

	// Load the vector with random numbers 
	for (int i = 0; i < n; ++i)
		v.push_back(std::rand() % 1000 + 1);

	// Sort vector
	std::sort(v.begin(), v.end(), [](int a, int b) { return (a % 11 > b % 11); });

	// Output the result
	for (int i = 0; i < n; ++i)
	{
		std::cout << v[i];
		if (i < n - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main() {

	PrintRndByEleven(5);

	return 0;
}
