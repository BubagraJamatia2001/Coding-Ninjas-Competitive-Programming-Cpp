/*
Count BSTs

Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.

Input Format :
Integer n 

Output Format :
Count of BSTs

Contraints :
1<= N <=1000

Sample Input 1:
8


Sample Output 1:
1430

Sample Input 2:
3
Sample Output 2:
5
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007

long long nbst(int n, int *temp){
    if(temp[n]>0)
        return temp[n];
    long long count =0;
    for (int i = 1; i <=n ; ++i) {
        long long left = nbst(i-1,temp)%mod;
        long long right= nbst(n-i,temp)%mod;
        temp[i-1]=left;
        temp[n-i]=right;
        count+=(left*right)%mod;
    }
    temp[n]=count;
    return count;
}

int countBST( int n)
{
    /* Don't write main().
       * Don't read input, it is passed as function argument.
       * Return output and don't print it.
       * Taking input and printing output is handled automatically.
       */
    int *temp=new int[n+1]();
    temp[0]=1;
    temp[1]=1;
    int ans= nbst(n,temp)%mod;
    delete[] temp;
    return ans;
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}

