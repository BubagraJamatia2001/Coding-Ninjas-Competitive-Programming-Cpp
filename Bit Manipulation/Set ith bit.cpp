/*
Set ith bit

You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
Counting of bits start from 0 from right to left.

Input Format :
Two integers N and i (separated by space)

Output Format :
Updated N

Sample Input 1 :
4 1

Sample Output 1 :
6

Sample Input 2 :
4 4

Sample Output 2 :
20
*/

#include <iostream>
using namespace std;

int turnOnIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     return n|(1<<i);    
}

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOnIthBit(n, i) <<endl;
		
	return 0;
}

