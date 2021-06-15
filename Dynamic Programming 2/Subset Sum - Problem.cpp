/*
Subset Sum - Problem

Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.

Sample Input
3
1 2 3
4

Sample Output
Yes
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b;i++)

bool subsetsum(int *arr, bool **dp, int sum, int s){
    rep(i,1,s+1){
        rep(j,1,sum+1){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
        }
    }
    /*rep(i,0,s+1){
        rep(j,0,sum+1) cout<<dp[i][j];
        cout<<endl;
    }*/
    bool flag =dp[s][sum];
    return flag;
}
int main(){
    int size,sum;
    cin>>size;
    int *arr=new int[size];
    rep(i,0,size) cin>>arr[i];
    cin>>sum;
    bool **dp =new bool*[size+1];
    rep(i,0,size+1)
        dp[i]=new bool[sum+1]();
    rep(i,0,size+1) dp[i][0] =true;
    bool flag = subsetsum(arr,dp,sum,size);
    cout<<(flag?"Yes":"No")<<endl;
    rep(i,0,size+1) delete [] dp[i];
    delete []dp;
    delete [] arr;
    return 0;
}
