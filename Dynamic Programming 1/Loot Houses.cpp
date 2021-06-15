/*Loot Houses
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house

Output Format
 Line 1 : Maximum amount of money looted

Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4

Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/
#include <iostream>
using namespace std;

int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
   int *dp =new int[n];
    for (int i = 1; i <n; ++i) {
        dp[i]=0;
    }
    dp[0]=arr[0];
    int ans =dp[0];
    for (int j = 1; j <n; ++j) {
        dp[j]=arr[j];
        for (int i = 0; i <= j-2; ++i) {
            int pos = arr[j]+dp[i];
            if( pos>dp[j])
            dp[j]=pos;
        }
        if(dp[j]>ans)
            ans=dp[j];
    }
    delete [] dp;
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

