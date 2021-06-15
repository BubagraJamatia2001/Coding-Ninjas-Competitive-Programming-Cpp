/*
Largest Bitonic Subarray

You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged 
first in strictly ascending order and then in strictly descending order. Such a subsequence is known as bitonic subsequence. A purely increasing or purely 
decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.

Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 

Output Format:
Length of Largest Bitonic subsequence

Input Constraints:
1<= N <= 100000

Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.

Sample Input 2:
2
1 5
Sample Output 2:
2

Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<iostream>
using namespace std;

int* incereasing(int *input,int n){
    int *inc =new int[n];
    inc[0]=1;
    for(int i = 1; i < n; ++i) {
        inc[i]=1;
        for (int j =0; j<i;j++) {
            if(input[i]<=input[j])
                continue;
            inc[i]= max(inc[i],inc[j]+1);
        }
    }
    /*for (int k = 0; k < n; ++k) {
        cout<<inc[k];
    }*/
    return inc;
}

int* decreasing(int *input,int n){
    int *dec =new int[n];
    dec[n-1]=1;
    for (int i = n-2; i >=0 ; i--){
        dec[i]=1;
        for (int j=n-1; j>i; j--) {
            if(input[i]<=input[j])
                continue;
            dec[i] = max(dec[i],dec[j]+1);
        }
    }
    /*for (int k = 0; k < n; ++k) {
        cout<<dec[k];
    }*/
    return dec;
}

int longestBitonicSubarray(int *input, int n) {
    /* Don't write main().
    * the input is already passed as function argument.
    * Taking input and printing output is handled automatically.
    */
    int *inc = incereasing(input,n);
    int *dec = decreasing(input,n) ;
    int best=0;
    for (int i = 0; i < n; ++i) {
        best=max(best,inc[i]+dec[i]-1);
    }
    delete[]inc;
    delete[]dec;
    return best;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
