/*
Problem text: Write a O(n) function with the following signature that, given a matrix of integers, 
builds a string with the entries of that matrix appended in anticlockwise order. 
For instance, the 3x4 matrix below:

 2, 3, 4, 8
 5, 7, 9, 12
 1, 0, 6, 10

 would make the string “2, 5, 1, 0, 6, 10, 12, 8, 4, 3, 7, 9”
 
 void StringifyMatrix(int* matrix, int rows, int columns, char* outBuffer)
 {
	 // Your code goes here
 } 

outBuffer is guaranteed to be valid and large enough to hold all of the data. 

*/


#include <iostream>
#include <sstream>
#include <string>

#include <string.h>

// Made the assumption that matrix a 1-dimensional array with all rows stored in contiguous memory.
// Also assumed that matrix actually points to a table of size (rows x columns) with each row stored
// consecutaively, starting with row 0.
void StringifyMatrix(const int* matrix, const int rows, const int columns, char* outBuffer)
{
	std::ostringstream sStr;

	if (rows == 0 || columns == 0)
	{
		strcpy_s(outBuffer, sizeof outBuffer, "");
		return;
	}

	int r = -1;		// Current row
	int c = 0;		// Current column
	int rmin = -1;		// 'bottom' limit
	int cmin = 0;		// 'left' limit
	int rmax = rows;	// 'top' limit
	int cmax = columns;	// 'right' limit

	// Spiral anticlockwise through matrix and print the values,
	// starting from the first character in matrix
	while (rmax > rmin && cmax > cmin)
	{
		// Set the limits
		if (rmax > 0)
			--rmax;
		if (cmax > 0)
			--cmax;
		if (rmin < rows - 1)
			++rmin;
		if (cmin < columns - 1)
			++cmin;

		// Traverse 'down' a column
		while (r < rmax)
			sStr << *(matrix + (++r * columns) + (c)) << ",";

		// Traverse 'right' across a row
		while (c < cmax)
			sStr << *(matrix + (r * columns) + (++c)) << ",";

		// Traverse 'up' a column
		while (r > rmin)
			sStr << *(matrix + (--r * columns) + (c)) << ",";

			// Traverse 'left' back across a row
			while (c > cmin)
				sStr << *(matrix + (r * columns) + (--c)) << ",";

	}
	std::string outStr = sStr.str();

	// Last comma is not required
	if (outStr.length() > 0)
		outStr.erase(outStr.length() - 1);

	// Copy result into outBuffer
	strcpy_s(outBuffer, outStr.length() + 1, outStr.c_str());
}

int main() {

	int matrix[] = { 2, 3, 4, 8, 5, 7, 9, 12, 1, 0, 6, 10 };
	char outBuffer[255];

	StringifyMatrix(matrix, 3, 4, outBuffer);

	std::cout << "outBuffer = " << outBuffer;

	return 0;
}

