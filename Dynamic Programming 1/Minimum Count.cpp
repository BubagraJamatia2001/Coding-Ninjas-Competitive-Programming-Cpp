/*
Minimum Count

Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.

Input Format :
Integer N

Output Format :
Required minimum count

Constraints :
1 <= N <= 1000

Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

bool perfect_square(int n){
    if(pow((int)pow(n,0.5),2)==n)
        return true;
    return false;
}

int minCount(int n, int *dp = new int[1001]()){
    //Write your code here
    if(perfect_square(n))return 1;
    if(n<=3) return n;
    if(dp[n]>0)
        return dp[n];
    int count=n;
    for (int i = 1; i <= pow(n,0.5); ++i) {
        int temp =pow(i,2);
        count=min(1+minCount(n-temp,dp),count);
    }
    dp[n]=count;
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
