/*
Minimum In SubArray

Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.

Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.

Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N

Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output :
1
1
2
1
*/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
#define rep(i,a,b) for(int i=a; i<b;i++)

void buildtree(int*arr, int *tree, int start,int end, int treenode){
    if(start==end){
        tree[treenode]=arr[start];
        return;
    }
    int mid =(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
    return;
}

void update_tree(int*arr, int *tree, int start, int end,int tree_node, int index, int value){
    if(start == end ){
        arr[index]=value;
        tree[tree_node]=value;
        return;
    }
    int mid = (start+end)/2;
    if(mid<index) update_tree(arr,tree,mid+1,end,2*tree_node+1,index,value);
    else update_tree(arr,tree,start,mid,2*tree_node,index,value);
    tree[tree_node]= min(tree[2*tree_node],tree[2*tree_node+1]);
}
int query(int*tree, int start, int end, int tree_node, int left, int right){
    if(start>right||end<left) return INT_MAX;
    if(start>=left && end<=right) return tree[tree_node];
    int mid=(start+end)/2;
    int op1=query(tree,start,mid,2*tree_node,left,right);
    int op2=query(tree,mid+1,end,2*tree_node+1,left,right);
    return min(op1,op2);
}

int main(){
    fast
    int n, q, in1, in2;
    char a;
    cin>>n>>q;
    auto *arr =new int[n];
    auto *tree = new int[4*n];
    rep(i,0,n) cin>>arr[i];
    buildtree(arr,tree,0,n-1,1);
    while(q--){
        cin>>a>>in1>>in2;
        switch(a){
            case 'q': cout<<query(tree,0,n-1,1,in1-1,in2-1)<<endl; break;
            case 'u': arr[in1-1]=in2;update_tree(arr,tree,0,n-1,1,in1-1,in2); break;
        }
    }
    return 0;
}
