/*
Balika Vadhu- Problem

Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. 
Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus
he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of
characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath 
comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.

Input Specification
First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.

Constraint
1 <= t <= 50
1 <= length(b1) , length(b2) <= 100 
1 <= K <= 100

Sample Input
2
asdf
asdf
3
anandi
jagya
3

Sample Output
317
0
*/
#include <bits/stdc++.h>
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
#define rep(i,a,b) for(int i=a; i<b;i++)
#define irep(i,a,b) for(int i=a; i>=b;i--)
#define mod 1000000007
//int test = read();

int solve(str s1,str s2, int k,int m,int n, int ***dp){
    if(m<k||n<k||k==0)
        return 0;
    if(dp[m][n][k]>=0)
        return dp[m][n][k];
    int ans;
    if(s1[0]==s2[0]){
        int op1 =solve(s1.substr(1),s2.substr(1),k-1,m-1,n-1,dp);
        if(op1==0 && k>1) op1=0;
        else op1+= s1[0];
        int op2 =solve(s1.substr(1),s2,k,m-1,n,dp);
        int op3 =solve(s1,s2.substr(1),k,m,n-1,dp);
        ans = max(op1,max(op2,op3));
    }
    else{
        int op1 =solve(s1.substr(1),s2,k,m-1,n,dp);
        int op2 =solve(s1,s2.substr(1),k,m,n-1,dp);
        ans = max(op1,op2);
    }
    dp[m][n][k]=ans;
    return ans;
}

int main(){
    int test,k;
    cin>>test;
    str s1,s2;
    while(test--){
        cin>>s1>>s2>>k;
        int m=s1.length(), n=s2.length();
        auto ***dp = new int**[m+1];
        rep(i,0,m+1){
            dp[i]=new int *[n+1];
            rep(j,0,n+1){
                dp[i][j]= new int[k+1]();
                rep(m,0,k+1)
                    dp[i][j][m]=-1;
            }
        }
        int ans = solve(s1,s2,k,m,n,dp);
        cout<<ans<<endl;
        rep(i,0,m+1){
            rep(j,0,n+1)
                delete []dp[i][j];
            delete [] dp[i];
        }
        delete [] dp;
    }
    return 0;
}