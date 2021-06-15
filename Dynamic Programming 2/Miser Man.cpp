/*
Miser Man

Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered 
from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following 
these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.

Input
Line 1:    N M
Line 2:    NxM Grid
Each row lists the fares the M busses to go form the current city to the next city.

Output
Single Line containing the minimum amount of fare that Jack has to give.

Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b;i++)
#define irep(i,a,b) for(int i=a; i>=b;i--)
#define sep ;cout<<" "<<;;
int minfare(int **arr, int n,int m, int i, int j, int **dp){
    if(i==n) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    int op1= arr[i][j]+ minfare(arr,n,m,i+1,j,dp);
    int op2 =INT_MAX,op3=INT_MAX;
    if(m>j+1) op2 =arr[i][j]+minfare(arr,n,m,i+1,j+1,dp);
    if(j-1>=0) op3= arr[i][j]+minfare(arr,n,m,i+1,j-1,dp);
    dp[i][j]=min(op1,min(op2,op3));
    return dp[i][j];
}

int miser(int**arr, int n, int m){
    int **dp =new int*[n+1];
    rep(i,0,n+1) dp[i]=new int[m+1];
    int ans =INT_MAX;
    rep(i,0,m){
        rep(j,0,n+1) rep(k,0,m+1) dp[j][k]=-1;
        ans=min(ans, minfare(arr,n,m,0,i,dp));
    }
    rep(i,0,n+1) delete [] dp[i];
    delete [] dp;
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    rep(i,0,n) arr[i]= new int[m];
    rep(i,0,n)rep(j,0,m) cin>>arr[i][j];
    int ans = miser(arr,n,m);
    cout<<ans<<endl;
    rep(i,0,n) delete [] arr[i];
    delete [] arr;
    return 0;
}
