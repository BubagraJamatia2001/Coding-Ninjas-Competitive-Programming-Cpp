/*
Sum Of Squares

Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)),
and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.

Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).
1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.

Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1

Output:
Case 1:
30
7
13
Case 2:
1
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
struct tree_{
    int sum_of_squares;
    int sum;
};
struct lazy_{
    int set = 0;
    int increment = 0;
};
void build_tree(int* arr, tree_* tree, int start, int end, int tree_node){
    if (start == end){
        tree[tree_node].sum_of_squares = arr[start]*arr[start];
        tree[tree_node].sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build_tree(arr, tree, start, mid, 2 * tree_node);
    build_tree(arr, tree, mid + 1, end, 2 * tree_node + 1);
    tree[tree_node].sum = tree[2 * tree_node].sum + tree[2 * tree_node + 1].sum;
    tree[tree_node].sum_of_squares = tree[2 * tree_node].sum_of_squares + tree[2 * tree_node + 1].sum_of_squares;
}
void lazy_update_set(tree_ *tree, lazy_ *lazy, int start, int end, int left, int right, int current_position, int x){
    if (start > end) return;
    if (lazy[current_position].set != 0){
        tree[current_position].sum = (right-left + 1) * lazy[current_position].set;
        tree[current_position].sum_of_squares = (right-left + 1) * (lazy[current_position].set * lazy[current_position].set);
        if (start != end){
            lazy[2 * current_position].set = lazy[current_position].set;
            lazy[2 * current_position+1].set = lazy[current_position].set;
        }
        lazy[current_position].set = 0;
    }
    //completely outside
    if (start > right || end < left) return;
    //complete overlap
    if (start >= left && end <= right){
        tree[current_position].sum_of_squares = (right-left + 1) * (x * x);
        tree[current_position].sum = (right-left + 1) * x;
        if (start != end){
            lazy[2 * current_position].set = x;
            lazy[2 * current_position + 1].set = x;
        }
        return;
    }
    //partial overlap
    int mid = (start + end) / 2;
    lazy_update_set(tree, lazy, start, mid, left, right, 2 * current_position, x);
    lazy_update_set(tree, lazy, mid+1, end, left, right, 2 * current_position+1, x);
    tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
    tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
    return;
}
void lazy_update_increment(tree_* tree, lazy_* lazy, int start, int end, int left, int right, int current_position, int increment){
    if (start > end) return;
    if (lazy[current_position].increment != 0){
        tree[current_position].sum_of_squares += (right-left + 1)*(lazy[current_position].increment*lazy[current_position].increment)+2*lazy[current_position].increment*tree[current_position].sum;
        tree[current_position].sum += (right-left + 1) * lazy[current_position].increment;
        if (start != end){
            lazy[2 * current_position].increment += lazy[current_position].increment;
            lazy[2 * current_position + 1].increment += lazy[current_position].increment;
        }
        lazy[current_position].increment=0;
    }
    if (lazy[current_position].set != 0){
        tree[current_position].sum = (right - left + 1) * (lazy[current_position].set);
        tree[current_position].sum_of_squares = (right - left + 1) * (lazy[current_position].set * lazy[current_position].set);
        if (start != end){
            lazy[2 * current_position].set = lazy[current_position].set;
            lazy[2 * current_position + 1].set = lazy[current_position].set;
        }
        lazy[current_position].set = 0;
    }
    //completely outside
    if (start > right || end < left) return;
    //complete overlap
    if(start>=left&&end<=right){
        tree[current_position].sum_of_squares += (right-left + 1) * (increment * increment) + 2 * increment * tree[current_position].sum;
        tree[current_position].sum += (right-left + 1) * increment;
        if (start != end){
            lazy[2 * current_position].increment += increment;
            lazy[2 * current_position + 1].increment += increment;
        }
        return;
    }
    //partial overlap
    int mid = (start + end) / 2;
    lazy_update_increment(tree, lazy, start, mid, left, right, 2 * current_position, increment);
    lazy_update_increment(tree, lazy, mid+1, end, left, right, 2 * current_position+1, increment);
    tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
    tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
    return;
}

tree_ query(tree_* tree, lazy_ *lazy, int start, int end, int left, int right, int treenode){
    if (start > end) return { 0, 0 };
    if (lazy[treenode].increment != 0){
        tree[treenode].sum_of_squares += 2 * lazy[treenode].increment * tree[treenode].sum + lazy[treenode].increment * lazy[treenode].increment * (right - left + 1);
        tree[treenode].sum += (right - left + 1) * lazy[treenode].increment;
        if (start != end){
            lazy[2 * treenode].increment = lazy[treenode].increment;
            lazy[2 * treenode + 1].increment = lazy[treenode].increment;
        }
        lazy[treenode].increment = 0;
    }
    if (lazy[treenode].set != 0){
        tree[treenode].sum = (right - left + 1) * lazy[treenode].set;
        tree[treenode].sum_of_squares = (right - left + 1) * lazy[treenode].set*lazy[treenode].set;
        if (start != end){
            lazy[2 * treenode].set = lazy[treenode].set;
            lazy[2 * treenode + 1].set = lazy[treenode].set;
        }
        lazy[treenode].set = 0;
    }
    //completely outside
    if (start > right || end < left) return { 0, 0 };
    //fully inside
    if (start >= left && end <= right) return tree[treenode];
    //partial overlap
    int mid = (start + end) / 2;
    tree_ left_child = query(tree, lazy, start, mid, left, right, 2 * treenode);
    tree_ right_child = query(tree, lazy, mid+1, end, left, right, 2 * treenode+1);
    tree_ ans;
    ans.sum = left_child.sum + right_child.sum;
    ans.sum_of_squares = left_child.sum_of_squares + right_child.sum_of_squares;
    return ans;
}

int main(){
    fast
    int t,n,q,type_of_operation,left,right,input;
    cin >> t;
    int case_number = 1;
    while(t--){
        cout << "Case " << case_number << ":" << endl;
        cin >> n >> q;
        int* arr = new int[n];
        rep(i,0,n)cin >>arr[i];
        tree_* tree = new tree_[4 * n]();
        lazy_* lazy = new lazy_[4 * n]();
        build_tree(arr, tree, 0, n - 1, 1);
        while (q--){
            cin >> type_of_operation;
            switch(type_of_operation){
                case 0:{cin>>left>>right>>input;lazy_update_set(tree, lazy, 0, n-1, left-1, right-1, 1, input);break;}
                case 1:{cin>>left>>right>>input;lazy_update_increment(tree, lazy, 0, n-1, left-1, right-1, 1, input);break;}
                case 2:{cin>>left>>right; cout<<query(tree,lazy,0,n-1,left - 1,right-1,1).sum_of_squares<<endl;break;}
            }
        }
        delete [] arr;
        delete [] tree;
        delete [] lazy;
        case_number++;
    }
    return 0;
}
//TA Solution
/*

#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define FORC(it,container) for(typeof(container.begin()) it=container.begin();it!=container.end();++it)
#define INT(x) scanf("%d",&x)
#define LLD(x) scanf("%lld",&x)
#define STR(x) scanf("%s",x)
#define CHAR(x) scanf("%c",&x)
#define PINT(x) printf("%d\n",x)
#define PLLD(x) printf("%lld\n",x)
#define CLR(x) memset(x,0,sizeof(x));
#define F first
#define S second
#define PB push_back

const int INF = INT_MAX;
const int MAX = 100000;
const int MOD = 1e9 + 7;

typedef long long LL;
typedef unsigned long long ULL;
int arr[MAX + 5];

 struct data
 {
 	LL sumsq;
 	LL sum;
	int lazyset;
	int setval;
	int addval;

	void assignleaf()
	{

	}
	void assignleaf(int idx, int val)
	{

 	}

 	void combine(data& l, data& r)
	{
	sumsq = l.sumsq + r.sumsq;
		sum = l.sum + r.sum;
	}
};

data tree[4 * MAX + 5];

 void pushdown(int node, int segs, int sege)
{
 	int mid = segs + sege; mid /= 2;

	if (tree[node].lazyset == 1)
{
		tree[node].lazyset = 0;

	tree[2 * node].lazyset = 1;
	tree[2 * node + 1].lazyset = 1;

		tree[2 * node].setval = tree[node].setval;
	tree[2 * node + 1].setval = tree[node].setval;

	tree[2 * node].sum = (mid - segs + 1) * tree[node].setval;
		tree[2 * node + 1].sum = (sege - mid) * tree[node].setval;

 		tree[2 * node].addval = 0;
		tree[2 * node + 1].addval = 0;

		tree[2 * node].sumsq = (mid - segs + 1) * tree[node].setval * tree[node].setval;
		tree[2 * node + 1].sumsq = (sege - mid) * tree[node].setval * tree[node].setval;;


 	}


	if (tree[node].addval)
	{

	tree[2 * node].addval += tree[node].addval;
		tree[2 * node + 1].addval += tree[node].addval;

		tree[2 * node].sumsq += (mid - segs + 1) * tree[node].addval * tree[node].addval + 2 * tree[node].addval * tree[2 * node].sum;
		tree[2 * node + 1].sumsq += (sege - mid) * tree[node].addval * tree[node].addval + 2 * tree[node].addval * tree[2 * node + 1].sum;

		tree[2 * node].sum += (mid - segs + 1) * tree[node].addval;
	tree[2 * node + 1].sum += (sege - mid) * tree[node].addval;

		tree[node].addval = 0;

	}

 }

 void build_tree(int node, int s, int e)
{
	tree[node].addval = 0;
	tree[node].lazyset = 0;

	if (s > e) return;
 if (s == e)
	{
		tree[node].sum = arr[s];
		tree[node].sumsq = arr[s] * arr[s];
	return;
 	}

	int mid = (s + e) / 2;
 build_tree(2 * node, s, mid);
	build_tree(2 * node + 1, mid + 1, e);

 	tree[node].combine(tree[2 * node], tree[2 * node + 1]);

 }

 LL query(int node, int segs, int sege, int qs, int qe)
 {

	//cout<<" q -- node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<endl;


	if (segs > sege || segs > qe || sege < qs)
	{
		if (tree[node].lazyset || tree[node].addval)
			pushdown(node, segs, sege);

	return 0;

	}

	if (tree[node].lazyset || tree[node].addval)
		pushdown(node, segs, sege);

 	if (segs >= qs && sege <= qe)
 	{

		//cout<<"q1 node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" sumsq  = "<<tree[node].sumsq<<endl;
		return tree[node].sumsq;

	}

 	int mid = segs + sege; mid /= 2;


 	return query(2 * node, segs, mid, qs, qe) + query(2 * node + 1, mid + 1, sege, qs, qe);

}

 //comm=1
 void update_add(int node, int segs, int sege, int qs, int qe, int x)
 {

 	//cout<<" ua -  node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<" x = "<<x<<endl;


 	if (segs > sege || segs > qe || sege < qs)	return;

 	if (segs >= qs && sege <= qe)
	{
 		tree[node].addval += x;
 		tree[node].sumsq += (LL)(sege - segs + 1) * x * x + (LL)2 * x * (tree[node].sum);
		tree[node].sum += (LL)(sege - segs + 1) * x;
		return;
 	}

	int mid = segs + sege; mid /= 2;

 	if (tree[node].lazyset || tree[node].addval)
		pushdown(node, segs, sege);

	update_add(2 * node, segs, mid, qs, qe, x);
	update_add(2 * node + 1, mid + 1, sege, qs, qe, x);

	tree[node].combine(tree[2 * node], tree[2 * node + 1]);


}

 //comm=0
 void update_set(int node, int segs, int sege, int qs, int qe, int x)
{

	//cout<<" node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<" x = "<<x<<endl;

	if (segs > sege || segs > qe || sege < qs)
		return;


 	if (segs >= qs && sege <= qe)
	{
		tree[node].lazyset = 1;
		tree[node].setval = x;
		tree[node].sumsq = (LL)(sege - segs + 1) * x * x;
 		tree[node].sum = (LL)(sege - segs + 1) * x;
 		tree[node].addval = 0;
 		return;
	}

 	if (tree[node].lazyset || tree[node].addval)
 		pushdown(node, segs, sege);


 	int mid = segs + sege;
 	mid /= 2;


	update_set(2 * node, segs, mid, qs, qe, x);
 	update_set(2 * node + 1, mid + 1, sege, qs, qe, x);

	tree[node].combine(tree[2 * node], tree[2 * node + 1]);


 }





 int main(){

 	int test; INT(test);

 	FOR(tt, 1, test + 1)
	{
		int n, q; INT(n); INT(q);


		CLR(arr);
 		CLR(tree);

		FOR(i, 0, n)
			INT(arr[i]);

 		build_tree(1, 0, n - 1);




		printf("Case %d:\n", tt);
		while (q--)
		{

			//FOR(i,1,16)
		//cout<<" node = "<<i<<" sumsq = "<<tree[i].sumsq<<" sum = "<<tree[i].sum<<" lazyset = "<<tree[i].lazyset<<" addval = "<<tree[i].addval<<" setval = "<<tree[i].setval<<endl;


		int comm; int l, r;

 			INT(comm); INT(l); INT(r);


 			if (comm == 0)
			{
 				//set x
				int x; INT(x);
			update_set(1, 0, n - 1, l - 1, r - 1, x);

 			}
			else if (comm == 1)
			{
				//add x
				int x; INT(x);
				update_add(1, 0, n - 1, l - 1, r - 1, x);

 			}
			else if (comm == 2)
 			{
 				LL ans = query(1, 0, n - 1, l - 1, r - 1);

			PLLD(ans);

		}

		}

	}

	return 0;
 }*/


