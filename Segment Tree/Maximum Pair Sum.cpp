/*
Maximum Pair Sum

You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12

*/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);
#define rep(i,a,b) for(int i=a; i<b;i++)
typedef  pair<int,int> pii;
#define mp(a,b) make_pair(a,b)
void buildtree(int*arr, pii *tree, int start,int end, int tree_node){
    if(start==end){
        tree[tree_node]=mp(arr[start],0);
        return;
    }
    int mid =(start+end)/2;
    buildtree(arr,tree,start,mid,2*tree_node);
    buildtree(arr,tree,mid+1,end,2*tree_node+1);
    pii left=tree[2*tree_node],right=tree[2*tree_node+1];
    int op1=max(left.first,right.first);
    int op2=min(max(left.first,right.second),max(right.first,left.second));
    tree[tree_node]=mp(op1,op2);
}

void update_tree(int*arr, pii *tree, int start, int end,int tree_node, int index, int value) {
    if (start == end) {
        arr[index] = value;
        tree[tree_node] = mp(arr[index], INT_MIN);
        return;
    }
    int mid = (start + end) / 2;
    if (mid < index) update_tree(arr, tree, mid + 1, end, 2 * tree_node + 1, index, value);
    else update_tree(arr, tree, start, mid, 2 * tree_node, index, value);
    pii left = tree[2 * tree_node], right = tree[2 * tree_node + 1];
    int op1 = max(left.first, right.first);
    int op2=min(max(left.first,right.second),max(right.first,left.second));
    tree[tree_node] = mp(op1, op2);
}

pii query(pii *tree, int start, int end, int tree_node, int left, int right){
    if(start>right||end<left) return mp(0,0);
    if(start>=left && end<=right) return tree[tree_node];
    int mid=(start+end)/2;
    pii op1=query(tree,start,mid,2*tree_node,left,right);
    pii op2=query(tree,mid+1,end,2*tree_node+1,left,right);
    int o1=max(op1.first,op2.first);
    int o2=min(max(op1.first,op2.second),max(op2.first,op1.second));
    return mp(o1,o2);
}

int main(){
    fast
    int n, q, in1, in2;
    char a;
    cin>>n;
    auto *arr =new int[n];
    auto *tree = new pii[3*n]();
    rep(i,0,n) cin>>arr[i];
    buildtree(arr,tree,0,n-1,1);
    //rep(i,0,3*n) cout<<tree[i].first<<" "<<tree[i].second<<endl;
    cin>>q;
    while(q--){
        cin>>a>>in1>>in2;
        switch(a){
            case 'Q': {pii temp;
            temp=query(tree,0,n-1,1,in1-1,in2-1);
            cout<<temp.first+temp.second<<endl;
            break;}
            case 'U': update_tree(arr,tree,0,n-1,1,in1-1,in2);
        }
    }
    return 0;
}
