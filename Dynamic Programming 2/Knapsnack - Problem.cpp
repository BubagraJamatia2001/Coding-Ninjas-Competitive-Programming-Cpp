/*
Knapsnack - Problem

A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V,
that thief can take ?
Space complexity should be O(W).

Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5

Sample Output :
13
*/

#include<iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b;i++)
#include<algorithm>
//dp with 2 1d array
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int *dp1 =new int[maxWeight+1]();
    int *dp2 =new int[maxWeight+1]();
    rep(i,0,n+1){
        rep(j,1,maxWeight+1){
            dp2[j]=dp1[j];
            if(weights[i]<=j)
                dp2[j]=max(values[i]+dp1[j-weights[i]],dp2[j]);
        }
        rep(i,0,maxWeight+1){
            dp1[i]=dp2[i];
            dp2[i]=0;
        }
    }
    int ans= dp1[maxWeight];
    delete [] dp1;
    delete [] dp2;
    return ans;

}

/*
//Not to be submitted due to runtime error (memory short by ide)
//Memoization method
#define rep(i,a,b) for(int i=a; i<b;i++)
#define irep(i,a,b) for(int i=a; i>=b;i--)
int helper(int* weights, int* values, int n, int maxWeight,int **dp){
    if(n<0)
        return 0;
    if(dp[n][maxWeight]!=-1)
        return dp[n][maxWeight];

    int ans,op1,op2;
    if(maxWeight>=weights[n]){
        op1=helper(weights,values,n-1,maxWeight-weights[n],dp)+values[n];
        op2=helper(weights,values,n-1,maxWeight,dp);
        ans=max(op1,op2);
    }
    else
        ans=helper(weights,values,n-1,maxWeight,dp);

    dp[n][maxWeight]=ans;
    return ans;
}
int knapsack(int* weights, int* values, int n, int maxWeight){
    int **dp =new int*[n];
    rep(i,0,n){
        dp[i]=new int[maxWeight+1];
        rep(j,0,maxWeight+1)
            dp[i][j]= -1;
    }
    int ans = helper(weights,values,n-1,maxWeight,dp);
    rep(i,0,n) delete []dp[i];
    delete []dp;
    return ans;
}

//dp with 2d array
#define rep(i,a,b) for(int i=a; i<b;i++)

int knapsack(int* wt,int* val,int n, int W){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){

			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w){
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		}
	}

	int ans = dp[n][W];
	//delete dp array 
	return ans;
}

*/


int main(){
  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];
  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }
  for(int i = 0; i < n; i++){
    cin >> values[i];
  }
  int maxWeight;
  cin >> maxWeight;
  cout << knapsack(weights, values, n, maxWeight);
}


