/*
Roy and Coin Boxes

Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.
After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a

Output
For each query output the result in a new line.

Constraints
1 ≤ N ≤ 1000000
1 ≤ M ≤ 1000000
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 1000000
1 ≤ X ≤ N

Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2

Sample Output
6
0
0
4

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
#define rep(i,a,b) for(int i=a; i<b;i++)
#define irep(i,a,b) for(int i=a; i>=b;i--)
#define mod 1000000007
//int test = read();

int main(){
    fast//the main reason for time delay
    int size,put,que;
    cin>>size>>put;
    int *s= new int[size+1]();
    int *e= new int[size+1]();
    rep(i,0,put){
        int str,end;
        cin>>str>>end;
        s[str]++;
        e[end]++;
    }
    int *dp1 = new int[size+1]();
    dp1[0]=0;
    dp1[1]=s[1];//initialisation//
    rep(i,2,size+1) dp1[i]=dp1[i-1]+s[i]-e[i-1];
    int *temp = new int[size+1]();
    rep(i,0,size+1) temp[dp1[i]]++;
    irep(i,size-1,0) temp[i]+=temp[i+1];
    //rep(i,0,size+1) cout<<temp[i];
    cout<<endl;
    cin>>que;
    rep(i,0,que) {
        int val;
        cin >> val;
        cout <<temp[val]<< endl;
    }
    delete[]dp1;
    delete[]temp;
    delete[]s;
    delete[]e;
    return 0;
}
