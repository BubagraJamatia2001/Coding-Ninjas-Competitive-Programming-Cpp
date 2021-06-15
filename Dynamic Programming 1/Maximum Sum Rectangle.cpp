/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.

Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.

Output
Output a single integer, maximum sum rectangle.

Constraints
1<=n,m<=100

Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
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
#define mod 1000000007
//int test = read();

int kadanes_algo(int *arr, int r){
    int sum=INT_MIN, curr_sum=0;
    rep(i,0,r){
        curr_sum+=arr[i];
        if(curr_sum>sum)
            sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return sum;
}

int max_sum_rectangle( int **a, int r, int c){
    int max_sum=INT_MIN;
    rep(i,0,c){
        int *temp =new int[r]();
        rep(j,i,c){
            rep(k,0,r){ temp[k]+=a[k][j];}
            max_sum = max(max_sum,kadanes_algo(temp,r));
        }
        delete []temp;
    }
    return max_sum;
}

int main(){
    int r,c;
    cin>>r>>c;
    int **tab= new int*[r];
    rep(i,0,r){
        tab[i]=new int[c];
        rep(j,0,c){
        cin>>tab[i][j];
        }
    }
    cout<<max_sum_rectangle(tab,r,c);
    rep(i,0,r)delete [] tab[i];
    delete[] tab;
    return 0;
}
