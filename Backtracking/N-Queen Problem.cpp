/*
N-Queen Problem

You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. 
You have to print all such configurations.

Input Format :
Line 1 : Integer N

Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.

Constraints :
1<=N<=10

Sample Input 1:
4

Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

#include<iostream>
#include <cstring>
using namespace std;

int board[11][11];
bool possible(int r, int c, int n){
    for (int i = r-1; i>=0; i--) {
        if(board[i][c]==1)
            return false;
    }
    for (int i=r-1, j=c-1; i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
            return false;
    }
    for (int i=r-1, j=c+1; i>=0 &&j<n;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    return true;
}

void recurpart(int r,int n){
    if(r==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<< board[i][j]<<" ";
            }
        }
        cout<<endl;
    return;
    }
    for(int k=0;k<n;k++) {
        if(possible(r,k,n)){
            board[r][k]=1;
            recurpart(r+1,n);
            board[r][k]=0;
        }
    }
}

void placeNQueens(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Print output as specified in the question
    */
    memset(board,0,11*11* sizeof(int));
    recurpart(0,n);
}

int main(){
  int n; 
  cin >> n ;
  placeNQueens(n);
}


