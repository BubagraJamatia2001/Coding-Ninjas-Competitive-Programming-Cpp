/*
Magic Grid Problem

You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero 
has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and 
a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical 
stone can revive him.
Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move 
either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey 
to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the 
Sorcerer's Stone. Please help him once again.

Input (STDIN)
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in
R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain
dragons, others contain magic potions.

Output (STDOUT):
Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey 
to the cell (R,C).

Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ S[i][j] ≤ 10^3
S[1][1] = S[R][C] = 0

Sample Input
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0

Sample Output
2
1
2
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
typedef float f;
typedef long l;
typedef string str;
typedef  long long ll;
typedef  long long int lli;
typedef char c;
typedef double d;
typedef vector<int> vi;
#define mod 1000000007
//int test = read();

int min_health(int **grid, int r, int c){
    int **dp= new int*[r], ans;
    for (int i = 0; i < r; ++i) {
        dp[i]=new int[c]();
        for (int j = 0; j < c; ++j) {
            dp[i][j]=0;
        }
    }
    dp[r-1][c-1]=1;
    dp[r-2][c-1]=1;
    dp[r-1][c-2]=1;
    for (int k = c-3; k>=0 ;--k){
        if(grid[r-1][k+1]<0)
            dp[r-1][k]=dp[r-1][k+1]-grid[r-1][k+1];
        else
            dp[r-1][k]= max(1,dp[r-1][k+1]-grid[r-1][k+1]);
    }
    for (int k = r-3; k>=0 ;--k) {
        if(grid[k+1][c-1]<0)
            dp[k][c-1] = dp[k+1][c-1]-grid[k+1][c-1];
        else
            dp[k][c-1] = max(1,dp[k+1][c-1]-grid[k+1][c-1]);
    }
    for (int i = r-2; i >=0 ; --i) {
        for (int j = c-2; j >=0 ; --j) {
            int option1, option2;
            if(grid[i+1][j]<0)
                option1 = dp[i+1][j]-grid[i+1][j];
            else
                option1 = max(1,dp[i+1][j]-grid[i+1][j]);
            if(grid[i][j+1]<0)
                option2 = dp[i][j+1]-grid[i][j+1];
            else
                option2 = max(1,dp[i][j+1]-grid[i][j+1]);
            dp[i][j]=min(option2,option1);
        }
    }
    ans =dp[0][0];
    for (int m = 0; m < r; ++m) {
        delete [] dp[m];
    }
    delete[] dp;
    return ans;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int row, col;
        cin>>row>>col;
        int **grid = new int*[row];
        for(int i = 0; i < row; ++i) {
            grid[i]= new int[col];
            for (int j = 0; j < col; ++j) {
                cin>>grid[i][j];
            }
        }
        cout<<min_health(grid,row,col)<<endl;
        for (int k = 0; k < row; ++k) {
            delete [] grid[k];
        }
        delete [] grid;
    }
    return 0;
}


