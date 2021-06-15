/*
link: https://www.hackerrank.com/challenges/sam-and-substrings/problem
Sam and substrings

Samantha and Sam are playing a numbers game. Given a number as a string, no leading zeros, determine the sum of all integer values of substrings of the string. 
For example, if the string is 42, the substrings are 4, 2 and 42. Their sum is 48.
Given an integer as a string, sum all of its substrings cast as integers. As the number may become large, return the value modulo 10^9+7.

Function Description

Complete the substrings function in the editor below. It should return the sum of the integer values of all substrings in a string representation of a number, modulo .

substrings has the following parameter(s):

n: the string representation of an integer
Input Format

A single line containing an integer as a string without leading zeros.

Constraints
1 <= n <= 2*10^5
Output Format

A single line which is sum of the substrings, T%(10^9+7)

Sample Input 0

16
Sample Output 0

23
Explanation 0

The substring of number 16 are 16, 1 and 6 which sums to 23.
*/
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

// Complete the substrings function below.
int substrings(string n) {
    long long totalsum=n[0]-'0';
    long long sum=n[0]-'0';
    for (int i = 1; i < n.length(); ++i) {
        sum=((sum*10)+((n[i]-'0')*(i+1)))%mod;
        totalsum=(totalsum+sum)%mod;
    }
    return totalsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
