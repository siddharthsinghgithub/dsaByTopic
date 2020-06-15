/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence
  such that all elements of the subsequence are sorted in increasing order.
  For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include<bits/stdc++.h>

using namespace std;

int LIS( int array[] , int n ){

    int lis[n];
    for ( auto i=0;i< n ;i++) lis[i] = 1;

    for(int i=0;i < n ;i++){

        for(int j=0;j<i;j++){

            if(array[i] > array[j] and lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    int k = *max_element(lis, lis+n);
    return k;
}
int main(){
  int x , array[] = {2,3,1,4,6,8,2};
  int n = sizeof(array)/sizeof(array[0]);

  x = LIS(array,n);
  cout<<x;
  return 0;
}
