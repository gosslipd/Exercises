// Problem statement:
//
// “Given three integer arrays sorted in ascending order, return the smallest number that is common in all three arrays. Return -1 if there is no common number.”
//
// Hints:
//
// The arrays are already sorted so their smallest element is at index 0.
// Use three pointers [PDG: I will use iterators which are better, especially since the given solution uses indices and not pointers!]
//

#include <iostream>
#include <vector>
#include <algorithm>

int find_least_common_number(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3)
{
	int commonValue = -1;

	for (auto & n : arr1)
	{
		std::vector<int>::const_iterator it2 = std::find(arr2.cbegin(), arr2.cend(), n);
		std::vector<int>::const_iterator it3 = std::find(arr3.cbegin(), arr3.cend(), n);

		if (it2 != arr2.cend() && it3 != arr3.cend())
		{
			// Value exisits in all three arrays - we're done
			commonValue = n;
			break;
		}
	}

	return commonValue;
}

int find_least_common_number2(std::vector<int> & arr1, std::vector<int> & arr2, std::vector<int> & arr3)
{
	const std::vector<int>::iterator it1 = arr1.begin();

	int searchValue = -1;

	for (std::vector<int>::const_iterator it1 = arr1.cbegin(); it1 != arr1.cend(); it1++)
	{
		searchValue = *it1;

		std::vector<int>::const_iterator it2 = std::find(arr2.cbegin(), arr2.cend(), searchValue);
		std::vector<int>::const_iterator it3 = std::find(arr3.cbegin(), arr3.cend(), searchValue);

		if (it2 != arr2.cend() && it3 != arr3.cend())
		{
			// Value exisits in all three arrays - we're done
			break;
		}

		if (it1 == arr1.cend() - 1)
		{
			searchValue = -1;
		}
	}

	return searchValue;
}

int main(int argc, char * argv[])
{
	std::cout << "Find the smallest common number in all three arrays" << std::endl;
	
	std::vector<int> v1 = {6, 7, 10, 25, 30, 63, 64};
	std::vector<int> v2 = {1, 4, 5, 6, 7, 8, 50};
	std::vector<int> v3 = {1, 6, 10, 14};

	int result = find_least_common_number(v1, v2, v3);

	std::cout << "Least Common Number v1-v3: " << result << std::endl;
	std::vector<int> v4 = {3, 7, 11, 25, 31, 63, 80};
	std::vector<int> v5 = {2, 4, 5, 6, 7, 9, 50};
	std::vector<int> v6 = {4, 6, 15, 20};

	result = find_least_common_number2(v4, v5, v6);

	std::cout << "Least Common Number v4-v6: " << result << std::endl;
}

