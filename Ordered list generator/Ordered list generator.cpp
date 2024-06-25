// 
// Problem text: Using the Standard Library and C++(03, 11 or 14) write a function with the following signature that 
// generates a list of random numbers between 1 and 1000, sort them comparing the remainder of a division by 11 and 
// starting from the bigger remainder, and print them on the standard output.
// 
// For instance:
// 
//  void PrintRndByEleven(int n /* numbers to generate */)
//  {
// 	 // Your code goes here
//  }
// 
//  PrintRndByEleven(5) could generate 741, 985, 168, 73, 12 and print “73, 985, 741, 168, 12”
// 
// 



#include <iostream>
#include <vector>
#include <algorithm>

void PrintRndByEleven(const int n /* generate n numbers */)
{
	std::vector<int> v;	// Vector to hold random numbers

	static bool firstCall = true;
	if (firstCall)
	{
		std::srand(static_cast<unsigned int>(time(0)));	// Make numbers more random - call this once when the program starts
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
