
// Problem Statement
// 
// “Given an integer array, move all elements that are 0 to the left while maintaining the order of other elements in the array. The array must be modified in-place.”
// 
// Hints:
// 
// Use reader/writer indexes
// You cannot use a simple chronological sort as elements other than zeros must maintain their position.
// 

#include <iostream>
#include <vector>
#include <algorithm>

/// @brief Solution given for the problem - yuck!
/// @param A Data input / output.
/// @param n Length of data in A.
void moveZerosToLeftGiven(int A[], int n) {
   
  if (n < 1) return;
  
  int write_index = n - 1;
  int read_index = n - 1;

  while(read_index >= 0) {
    if(A[read_index] != 0) {
      A[write_index] = A[read_index];
      write_index--;
    }

    read_index--;
  }

  while(write_index >= 0) {
    A[write_index] = 0;
    write_index--;
  }
}

/// @brief My solution to the problem using STL containers - barely worth a function...
/// @param A Data input / output
void moveZerosToLeft(std::vector<int> & A)
{
    // Note: std::partition would not have preserved the order of the non-zero elements, unlike std::stable_partition
    std::stable_partition(A.begin(), A.end(), [&](int x) { return x == 0; });
}

int main() {
  int v[] = {1, 10, 20, 0, 63, 59, 0, 88, 0};
  int n = sizeof(v) / sizeof(v[0]);

  std::cout << "Original Array" << std::endl;
  
  for(int x=0 ; x<n; x++) {
    std::cout << v[x];
    std::cout << ", ";
  }  
  
  std::vector<int> vv(v, v + n);
  moveZerosToLeft(vv);
  //moveZerosToLeftGiven(v, n);
  
  std::cout << std::endl << "After Moving Zeroes to Left" << std::endl;
  for(int i=0 ; i<n; i++) {
    std::cout << vv[i];
    std::cout << ", ";
  }  
}  