/*
	Move Zeros To End
	Given a static-sized array of integers arr, move all zeroes in the array to the end of the array. You should preserve the relative order of items in the array.

	We should implement a solution that is more efficient than a naive brute force.

	Examples:

	input:  arr = [1, 10, 0, 2, 8, 3, 0, 0, 6, 4, 0, 5, 7, 0]
	output: [1, 10, 2, 8, 3, 6, 4, 5, 7, 0, 0, 0, 0, 0]
	Constraints:

	[time limit] 5000ms
	[input] array.integer arr
	0 ≤ arr.length ≤ 20
	[output] array.integer
*/

#import <iostream>
#import <vector>

using namespace std;

vector<int> moveZerosToEnd(const vector<int>& A)
{
  
  int size = A.size();
  int count = 0;

  for(int i=0;i<size;i++){
    
    if(A[i] == 0){ 
      count++;
    }
    else{
      A[i-count] = A[i];
    }
  }
  
  int i = A.size() -1;
  while(count){
    A[i] = 0;
  }
  
  
  
  return A;
  
}

int main() 
{
	return 0;
}
