/*
Maximum Square Matrix With All Zeros

Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.

Input format :

Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output Format:
Line 1 : Size of maximum square sub-matrix

Sample Input :
3 3
1 1 0
1 1 1
1 1 1

Sample Output :
1
*/
#include<iostream>
using namespace std;

int min(int a,int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

int findMaxSquareWithAllZeros(int** arr, int row, int col){

    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int **temp = new int*[row],maxi=1;
    for(int i=0;i<row;i++) temp[i]= new int[col]();

    for(int i=0;i<row;i++) temp[i][0] =arr[i][0]?0:1;
    for(int i=0;i<col;i++) temp[0][i] =arr[0][i]?0:1;
    /*for (int k = 0; k < row; ++k) {
        for (int i = 0; i < col; ++i) {
            cout<<temp[k][i];
        }
        cout<<endl;
    }*/
    for(int i=1;i<row;i++)
        for(int j=1;j<col;j++){
            if(arr[i][j]==0)
                temp[i][j] =min( min(temp[i-1][j],temp[i][j-1]),temp[i-1][j-1])+1;
            maxi=max(temp[i][j],maxi);
        }
    /*for (int k = 0; k < row; ++k) {
        for (int i = 0; i < col; ++i) {
            cout<<temp[k][i];
        }
        cout<<endl;
    }*/
    for(int i=0;i<row;i++) delete [] temp[i];
    delete [] temp;
    return maxi;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
