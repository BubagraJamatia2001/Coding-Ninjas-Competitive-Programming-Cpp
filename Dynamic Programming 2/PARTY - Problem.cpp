/*
PARTY - Problem

You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. 
The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the 
most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually
pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve 
the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.
The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number 
indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.
The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.
There are many test cases. Input ends with 0 0.

Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated 
by a single space. 

Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b;i++)
#define irep(i,a,b) for(int i=a; i>=b;i--)
typedef pair<int,int> pii;

pii max(pii a, pii b){
    if(a.second>b.second)
        return a;
    else if(a.second<b.second)
        return b;
    else{
        if(a.first<=b.first)
            return a;
        else return b;
    }
}

pii solve(pii *arr, int bud, int n){
    pii *dp1 = new pii[bud+1]();
    pii *dp2 = new pii[bud+1]();
    rep(i,0,n){
        rep(j,1,bud+1){
            dp2[j]=dp1[j];
            if(arr[i].first<=j){
                dp2[j]=max(make_pair(dp1[j-arr[i].first].first+arr[i].first,dp1[j-arr[i].first].second+arr[i].second),dp2[j]);
            }
        }
        rep(i,0,bud+1){
            dp1[i].first=dp2[i].first;
            dp1[i].second=dp2[i].second;
            dp2[i].first=dp2[i].second=0;
        }
    }
    pii ans= dp1[bud];
    delete [] dp1;
    delete [] dp2;
    return ans;
}

int main(){
    int budget, n;
    while(scanf("%d %d",&budget, &n), budget && n){
        pii *arr =new pii[n];
        rep(i,0,n) cin>>arr[i].first>>arr[i].second;
        pair<int,int> ans=solve(arr,budget,n);
        delete [] arr;
        cout<<ans.first<<" "<< ans.second<<endl;
    }
    return 0;
}

