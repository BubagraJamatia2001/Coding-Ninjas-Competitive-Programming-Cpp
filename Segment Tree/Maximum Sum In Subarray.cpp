/*
Maximum Sum In Subarray

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output
Your program should output the results of the M queries, one 
query per line.

Sample Input:
3 
-1 2 3 
1
1 2

Sample Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
#define rep(i,a,b) for(int i=a; i<b;i++)
typedef  pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
struct node{
    int max_sum,sum,best_sufix_sum,best_prefix_sum;
};

void buildtree(int*arr, node *tree, int start,int end, int tree_node){
    if(start==end){
        tree[tree_node].max_sum=arr[start];
        tree[tree_node].sum=arr[start];
        tree[tree_node].best_prefix_sum=arr[start];
        tree[tree_node].best_sufix_sum=arr[start];
        return;
    }
    int mid =(start+end)/2;
    buildtree(arr,tree,start,mid,2*tree_node);
    buildtree(arr,tree,mid+1,end,2*tree_node+1);
    auto op1=tree[2*tree_node],op2=tree[2*tree_node+1];
    tree[tree_node].max_sum=max(max(max(max(op1.max_sum,op2.max_sum),op1.best_sufix_sum+op2.sum),op1.sum+op2.best_prefix_sum),op1.best_sufix_sum+op2.best_prefix_sum);
    tree[tree_node].sum=op1.sum+op2.sum;
    tree[tree_node].best_prefix_sum=max(op1.best_prefix_sum,op1.sum+op2.best_prefix_sum);
    tree[tree_node].best_sufix_sum=max(op2.best_sufix_sum,op2.sum+op1.best_sufix_sum);
}

node query(node *tree, int start, int end, int tree_node, int left, int right){
    if(start>right||end<left) return {-100000, -100000, -100000, -100000};//this line is important dont return int_min
    if(start>=left && end<=right) return tree[tree_node];
    int mid=(start+end)/2;
    node op1=query(tree,start,mid,2*tree_node,left,right);
    node op2=query(tree,mid+1,end,2*tree_node+1,left,right);
    node ans;
    ans.max_sum=max(max(max(max(op1.max_sum,op2.max_sum),op1.best_sufix_sum+op2.sum),op1.sum+op2.best_prefix_sum),op1.best_sufix_sum+op2.best_prefix_sum);
    ans.sum=op1.sum+op2.sum;
    ans.best_prefix_sum=max(op1.best_prefix_sum,op1.sum+op2.best_prefix_sum);
    ans.best_sufix_sum=max(op2.best_sufix_sum,op2.sum+op1.best_sufix_sum);
    return ans;
}

int main(){
    fast
    int n, q, in1, in2;
    cin>>n;
    auto *arr =new int[n];
    auto *tree = new node[4*n]();
    rep(i,0,n) cin>>arr[i];
    buildtree(arr,tree,0,n-1,1);
    //rep(i,0,3*n) cout<<tree[i].max_sum<<" "; cout<<endl;
    cin>>q;
    while(q--){
        cin>>in1>>in2;
        node temp;
        temp=query(tree,0,n-1,1,in1-1,in2-1);
        cout<<temp.max_sum<<endl;
    }
    delete []arr;
    delete []tree;
    return 0;
}
