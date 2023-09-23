#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define mp make_pair
#define rsz resize
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define cont continue
#define inf 1000000007
#define endl '\n'
#define ednl '\n'
#define test int t;cin>>t;while(t--)
#define vin(v,n) vi (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vlln(v,n) vector<ll> (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vvin(v,n,m) vector<vi>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pi 3.1415926535
#define vvlln(v,n,m) vector<vector<ll>>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pq priority_queue
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
ll minimum(ll x, ll y)
{
	if (x < y)
		return x;
	return y;
}
/*
This is the list of all the segment_tree that i have implemented
*/
class segment_tree
{
	struct item
	{
		ll sum;
	};
	item single(ll i)
	{
		return { i };
	}
	item merge(item x, item y)
	{
		item ans;
		ans.sum = x.sum + y.sum;
		return ans;
	}
	vector<item> tree;
	vector<item>A;
	int height;
	item neutral = { 0 };
public:void build(vll& B)
{
	int	n = B.size();
	height = log2(n + 1) + 1;
	A.rsz(n);
	tree.rsz((1 << height + 1) - 1);
	F0R(i, n)A[i] = single(B[i]);
	A.rsz(1 << height, neutral);
	build(A, 0, 0, (1 << height) - 1);
}
	   void build(vector<item>& A, int v, int tl, int tr)
	   {
		   if (tl == tr)
			   tree[v] = A[tl];
		   else
		   {
			   int mid = (tl + tr) / 2;
			   build(A, 2 * v + 1, tl, mid);
			   build(A, 2 * v + 2, mid + 1, tr);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:ll query(int l, int r)
{
	return query(0, 0, (1 << height) - 1, l, r).sum;
}
	   item query(int v, int tl, int tr, int l, int r)
	   {
		   if (r<tl || l>tr)return neutral;
		   if (l <= tl && r >= tr)
		   {
			   return tree[v];
		   }
		   int mid = (tl + tr) / 2;
		   return merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid + 1, tr, l, r));
	   }
	   //assign
public:void update(int pos, ll val)
{
	update(0, 0, (1 << height) - 1, pos, single(val));
}
	   void update(int v, int tl, int tr, int pos, item val)
	   {
		   if (tl == tr)
		   {
			   tree[v] = val;
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   if (pos <= mid)
				   update(2 * v + 1, tl, mid, pos, val);
			   else
				   update(2 * v + 2, mid + 1, tr, pos, val);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:int get(int k)
{
	return get(0, 0, (1 << height) - 1, k);
}
	   int get(int v, int tl, int tr, int k)
	   {
		   if (tl == tr)return tl;
		   int mid = (tl + tr) / 2;
		   if (k > tree[2 * v + 1].sum)
			   return get(2 * v + 2, mid + 1, tr, k - tree[2 * v + 1].sum);
		   return get(2 * v + 1, tl, mid, k);
	   }
};

struct FenwickTree {
	vector<int> bit;  // binary indexed tree
	int n;

	FenwickTree() {}

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			update(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	int query(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void update(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};

class segment_tree_lazy
{
	struct item
	{
		ll sum, add, update;
	};
	item single(ll i)
	{
		return { i,0,0 };
	}
	item merge(item x, item y)
	{
		item ans;
		ans.sum = x.sum + y.sum;
		ans.add = 0;
		ans.update = 0;
		return ans;
	}
	vector<item> tree;
	vector<item>A;
	int height;
	item neutral = { 0,0,0 };
	void push(int i, int tl, int tr)
	{
		if (tree[i].update)
		{
			tree[i].update += tree[i].add;
			tree[i].add = 0;
			tree[i].sum = tree[i].update * (tr - tl + 1);
			if (tl != tr)
			{
				tree[2 * i + 1].add = 0; tree[2 * i + 1].update = tree[i].update;
				tree[2 * i + 2].add = 0; tree[2 * i + 2].update = tree[i].update;
			}
			tree[i].update = 0;
		}
		else
		{
			tree[i].sum += tree[i].add * (tr - tl + 1);
			if (tl != tr)
			{
				tree[2 * i + 1].add += tree[i].add;
				tree[2 * i + 2].add += tree[i].add;
			}
			tree[i].add = 0;
		}
	}
public:void build(vll& B)
{
	int	n = B.size();
	height = log2(n - 1) + 1;
	A.rsz(n);
	tree.rsz((1 << height + 1) - 1);
	F0R(i, n)A[i] = single(B[i]);
	A.rsz(1 << height, neutral);
	build(A, 0, 0, (1 << height) - 1);
}
	   void build(vector<item>& A, int v, int tl, int tr)
	   {
		   if (tl == tr)
			   tree[v] = A[tl];
		   else
		   {
			   int mid = (tl + tr) / 2;
			   build(A, 2 * v + 1, tl, mid);
			   build(A, 2 * v + 2, mid + 1, tr);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:ll query(int l, int r)
{
	return query(0, 0, (1 << height) - 1, l, r).sum;
}
	   item query(int v, int tl, int tr, int l, int r)
	   {
		   if (r<tl || l>tr)return neutral;
		   push(v, tl, tr);
		   if (l <= tl && r >= tr)
		   {
			   return tree[v];
		   }
		   int mid = (tl + tr) / 2;
		   return merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid + 1, tr, l, r));
	   }
public:void update(int l, int r, ll val)
{
	update(0, 0, (1 << height) - 1, l, r, val);
}
	   void update(int v, int tl, int tr, int l, int r, int val)
	   {
		   push(v, tl, tr);
		   if (tl > r || tr < l)return;
		   if (tl >= l && tr <= r)
		   {
			   tree[v].update = val;
			   tree[v].add = 0;
			   push(v, tl, tr);
			   //tree[v].sum = ((ll)tr - tl + 1) * val;
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   update(2 * v + 1, tl, mid, l, r, val);
			   update(2 * v + 2, mid + 1, tr, l, r, val);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:void add(int l, int r, int val)
{
	add(0, 0, (1 << height) - 1, l, r, val);
}
	   void add(int v, int tl, int tr, int l, int r, int val)
	   {
		   push(v, tl, tr);
		   if (tl > r || tr < l)return;
		   if (tl >= l && tr <= r)
		   {
			   tree[v].add += val;
			   push(v, tl, tr);
			   //tree[v].sum += ((ll)tr - tl + 1) * val;
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   add(2 * v + 1, tl, mid, l, r, val);
			   add(2 * v + 2, mid + 1, tr, l, r, val);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:int get(int x)
{
	push(0, 0, (1 << height) - 1);
	if (tree[0].sum < x)return -1;
	return get(0, 0, (1 << height) - 1, x);
}
	  int get(int i, int tl, int tr, int x)
	  {
		  push(i, tl, tr);
		  if (tl == tr)return tl;
		  int mid = (tl + tr) / 2;
		  push(2 * i, tl, mid);
		  push(2 * i + 1, mid + 1, tr);
		  if (x > tree[2 * i + 1].sum)
			  return get(2 * i + 2, mid + 1, tr, x - tree[2 * i + 1].sum);
		  return get(2 * i + 1, tl, mid, x);
	  }
};

class max_tree_lazy {

	vi tree;   // array of segment tree
	vi lazy;

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:max_tree_lazy(int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	lazy.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}
public:int leftChild(int k) { return 2 * k + 1; }
public:int rightChild(int k) { return 2 * k + 2; }
public:void buildSegTree(vi& A) {
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}
public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	int mid = (low + high) / 2;
	tree[p] = max(buildSegTreeRec(low, mid, leftChild(p), A)
		, buildSegTreeRec(mid + 1, high, rightChild(p), A));
	return tree[p];
}
public:int get_max(int x, int y) {
	if (x < 0 || ENDINDEX < y)
		return -INT_MAX;
	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}
public:int getSumRec(int low, int high, int l, int r, int node) {
	if (r < low || high < l)   // [x, y] doesn't overlap [low, high]
		return -INT_MAX;
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (low != high)
		{
			lazy[leftChild(node)] += lazy[node];
			lazy[rightChild(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (l <= low && high <= r)  // [x, y] contains [low, high]
		return tree[node];
	int mid = (low + high) / 2;
	return max(getSumRec(low, mid, l, r, leftChild(node))
		, getSumRec(mid + 1, high, l, r, rightChild(node)));
}

	   // add "val" at position "pos": A[pos] += val
public:void addValue(int l, int r, int val) {
	addValueRec(STARTINDEX, ENDINDEX, l, r, val, 0);
}
public:void addValueRec(int low, int high, int l, int r, int val, int node) {
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (low != high)
		{
			lazy[leftChild(node)] += lazy[node];
			lazy[rightChild(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (low > r || high < l)
		return;
	if (low >= l && high <= r)
	{
		tree[node] += val;
		if (low != high)
		{
			lazy[leftChild(node)] += val;
			lazy[rightChild(node)] += val;
		}
		return;
	}
	int mid = low + (high - low) / 2;
	addValueRec(low, mid, l, r, val, leftChild(node));
	addValueRec(mid + 1, high, l, r, val, rightChild(node));
	tree[node] = max(tree[leftChild(node)], tree[rightChild(node)]);
}
public:void print()
{
	print_vector(tree);
	print_vector(lazy);
	cout << ednl;
}
};

class min_tree_lazy {

	vi tree;   // array of segment tree
	vi lazy;

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:min_tree_lazy(int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	lazy.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}
public:int leftChild(int k) { return 2 * k + 1; }
public:int rightChild(int k) { return 2 * k + 2; }
public:void buildSegTree(vi& A) {
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}
public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	int mid = (low + high) / 2;
	tree[p] = min(buildSegTreeRec(low, mid, leftChild(p), A)
		, buildSegTreeRec(mid + 1, high, rightChild(p), A));
	return tree[p];
}
public:int get_min(int x, int y) {
	if (x < 0 || ENDINDEX < y)
		return INT_MAX;
	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}
public:int getSumRec(int low, int high, int l, int r, int node) {
	if (r < low || high < l)   // [x, y] doesn't overlap [low, high]
		return INT_MAX;
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (low != high)
		{
			lazy[leftChild(node)] += lazy[node];
			lazy[rightChild(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (l <= low && high <= r)  // [x, y] contains [low, high]
		return tree[node];
	int mid = (low + high) / 2;
	return min(getSumRec(low, mid, l, r, leftChild(node))
		, getSumRec(mid + 1, high, l, r, rightChild(node)));
}

	   // add "val" at position "pos": A[pos] += val
public:void addValue(int l, int r, int val) {
	addValueRec(STARTINDEX, ENDINDEX, l, r, val, 0);
}
public:void addValueRec(int low, int high, int l, int r, int val, int node) {
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (low != high)
		{
			lazy[leftChild(node)] += lazy[node];
			lazy[rightChild(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (low > r || high < l)
		return;
	if (low >= l && high <= r)
	{
		tree[node] += val;
		if (low != high)
		{
			lazy[leftChild(node)] += val;
			lazy[rightChild(node)] += val;
		}
		return;
	}
	int mid = low + (high - low) / 2;
	addValueRec(low, mid, l, r, val, leftChild(node));
	addValueRec(mid + 1, high, l, r, val, rightChild(node));
	tree[node] = min(tree[leftChild(node)], tree[rightChild(node)]);
}
public:void print()
{
	print_vector(tree);
	print_vector(lazy);
	cout << ednl;
}
};


class lazy_sparse
{
	struct Node {
		int l, r, sum;
		bool z;
		Node* ln, * rn;
		Node() {}
		Node(int _l, int _r) : l(_l), r(_r), sum(0), z(0), ln(nullptr), rn(nullptr) {}

		void upd(int a, int b) {
			if (z) return;
			if (a <= l && b >= r) {
				sum = r - l + 1;
				z = true;
			}
			else {
				int mid = (l + r) / 2;
				if (a <= mid) {
					if (!ln) ln = new Node(l, mid);
					ln->upd(a, b);
				}
				if (b > mid) {
					if (!rn) rn = new Node(mid + 1, r);
					rn->upd(a, b);
				}
				sum = 0;
				if (ln) sum += ln->sum;
				if (rn) sum += rn->sum;
			}
		}

		int qry(int a, int b) {
			if (b < l || a > r) return 0;
			if (a <= l && b >= r) return sum;
			if (z) return min(b, r) - max(a, l) + 1;
			int ret = 0;
			if (ln) ret += ln->qry(a, b);
			if (rn) ret += rn->qry(a, b);
			return ret;
		}
	};
	Node root;
public:void build(int l, int r)
{
	Node t(l, r);
	root = t;
}
public:void upd(int l, int r)
{
	root.upd(l, r);
}
public: int qry(int l, int r)
{
	return root.qry(l, r);
}
};

// remember that this (used to be) is 1-indexed. D:. Requires knowledge of updates beforehand. REMEMBER THAT YOU MUST PUT THE UPDATES FIRST THEN INIT().
template<class T, int SZ> struct OffBIT2D {// IF THIS IS NOT ALLOWED PLEASE LET ME KNOW. 
										   //SOURCE : https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/2D%20Range%20Queries%20(15.2)/BIT2DOff%20(15.2).h
										   // THANK YOU BENQ
	bool mode = 0; // mode = 1 -> initialized
	vpi todo; // locations of updates to process
	int cnt[SZ], st[SZ];
	vi val; vector<T> bit; // store all BITs in single vector
	void init() {
		assert(!mode); mode = 1;
		int lst[SZ]; F0R(i, SZ) lst[i] = cnt[i] = 0;
		sort(all(todo), [](const pii& a, const pii& b) {
			return a.s < b.s; });
		trav(t, todo) for (int x = t.f; x < SZ; x += x & -x)
			if (lst[x] != t.s) lst[x] = t.s, cnt[x] ++;
		int sum = 0; F0R(i, SZ) lst[i] = 0, st[i] = (sum += cnt[i]);
		val.rsz(sum); bit.rsz(sum); reverse(all(todo));
		trav(t, todo) for (int x = t.f; x < SZ; x += x & -x)
			if (lst[x] != t.s) lst[x] = t.s, val[--st[x]] = t.s;
	}
	int rank(int y, int l, int r) {
		return upper_bound(begin(val) + l, begin(val) + r, y) - begin(val) - l;
	}
	void UPD(int x, int y, T t) {
		for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)
			bit[st[x] + y - 1] += t;
	}
	void upd(int x, int y, T t) {
		x++, y++;
		if (!mode) todo.pb({ x,y });
		else for (; x < SZ; x += x & -x) UPD(x, y, t);
	}
	int QUERY(int x, int y) {
		T res = 0;
		for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y) res += bit[st[x] + y - 1];
		return res;
	}
	T query(int x, int y) {
		x++, y++;
		assert(mode);
		T res = 0; for (; x; x -= x & -x) res += QUERY(x, y);
		return res;
	}
	T query(int xl, int xr, int yl, int yr) {
		return query(xr, yr) - query(xl - 1, yr)
			- query(xr, yl - 1) + query(xl - 1, yl - 1);
	}
};

class sum_range_tree
{
	struct node
	{
		int val;
		struct node* C[2];
		node()
		{
			val = 0;
			C[0] = NULL;
			C[1] = NULL;
		}
		node* getc(int c)
		{
			if (C[c] == NULL)
			{
				C[c] = new node;
			}
			return C[c];
		}
		void update(int i, int v, int l, int r)
		{
			if (l == r)
			{
				val = v;
				return;
			}
			int mid = (l + r) / 2;
			if (i <= mid)
				getc(0)->update(i, v, l, mid);
			else
				getc(1)->update(i, v, mid + 1, r);
			val = (C[0] ? C[0]->val : 0) + (C[1] ? C[1]->val : 0);
		}
		int query(int l, int r, int tl, int tr)
		{
			if (tl >= l && tr <= r)
				return val;
			else if (tl>r || l>tr)
				return 0;
			int mid = (tl + tr) / 2;
			return (C[0] ? C[0]->query(l, r, tl, mid) : 0) + (C[1] ? C[1]->query(l, r, mid + 1, tr) : 0);		
		}
	};
	node* top;
public:void build()
{
	top = new node;
}
public:void update(int i, int v)
{
	top->update(i, v, 0, 2 * inf);
}
public:int query(int l, int r)
{
	return top->query(l, r, 0, 2 * inf);
}
};
class sum_range_tree_2D
{
	struct node
	{
		sum_range_tree st;
		struct node* C[2];
		node()
		{
			st.build();
			C[0] = NULL;
			C[1] = NULL;
		}
		node* getc(int c)
		{
			if (C[c] == NULL)
			{
				C[c] = new node;
			}
			return C[c];		
		}
		void update(int x1, int x2, int x, int y, int val)
		{
			if (x<x1 || x>x2)
				return;
			if (x1 == x2)
			{
				st.add_value(y, val);
				return;
			}
			int mid = (x1 + x2) / 2;
			getc(0)->update(x1, mid, x, y, val);
			getc(1)->update(mid + 1, x2, x, y, val);
			int ans = getc(0)->st.query(y, y) + getc(1)->st.query(y, y);
			st.update(y, ans);
		}
		int query(int x1, int x2, int qx1, int qx2, int qy1, int qy2)
		{
			if (x2<qx1 || x1>qx2)
			{
				return 0;
			}
			if (x1 >= qx1 && x2 <= qx2)
			{
				return st.query(qy1, qy2);
			}
			int mid = (x1 +x2) / 2;
			int a = getc(0)->query(x1, mid, qx1, qx2, qy1, qy2);
			int b = getc(1)->query(mid + 1, x2, qx1, qx2, qy1, qy2);
			return a + b;
		}
	};
	node* top;
public:void build()
{
	top = new node;
}
public:void update(int x, int y, int val)
{
	top->update(0, 2 * inf, x, y, val);
}
public:int query(int x1, int y1, int x2, int y2)
{
	return top->query(0, 2 * inf, x1, x2, y1, y2);
}
};

class max_range_tree
{
	struct node
	{
		int val;
		struct node* C[2];
		node()
		{
			val = 0;
			C[0] = NULL;
			C[1] = NULL;
		}
		node* getc(int c)
		{
			if (C[c] == NULL)
			{
				C[c] = new node;
			}
			return C[c];
		}
		void update(int i, int v, int l, int r)
		{
			if (l == r)
			{
				val = maximum(v, val);
				return;
			}
			int mid = ((l + r < 0) ? (l + r - 1) / 2 : (l + r) / 2);
			if (i <= mid)
				getc(0)->update(i, v, l, mid);
			else
				getc(1)->update(i, v, mid + 1, r);
			val = maximum((C[0] ? C[0]->val : 0), (C[1] ? C[1]->val : 0));
		}
		void increment(int i, int v, int l, int r)
		{
			if (l == r)
			{
				val = maximum(val, v);
				return;
			}
			int mid = ((l + r < 0) ? (l + r - 1) / 2 : (l + r) / 2);
			if (i <= mid)
				getc(0)->increment(i, v, l, mid);
			else
				getc(1)->increment(i, v, mid + 1, r);
			val = maximum((C[0] ? C[0]->val : 0), (C[1] ? C[1]->val : 0));
		}
		int query(int ql, int qr, int sl, int sr)
		{
			if (sl >= ql && sr <= qr)
				return val;
			else if (sr<ql || sl>qr)
				return 0;
			int mid = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
			return maximum((C[0] ? C[0]->query(ql, qr, sl, mid) : 0), (C[1] ? C[1]->query(ql, qr, mid + 1, sr) : 0));		
		}
	};
	node* top;
public:void build()
{
	top = new node;
}
public:void update(int i, int v)
{
	top->update(i, v, 0, 2 * inf);
}
public:int query(int l, int r)
{
	return top->query(l, r, 0, 2 * inf);
}
public:void add_value(int i, int v)
{
	top->increment(i, v, 0, 2 * inf);
}
};

class max_range_tree_2D
{
	struct node
	{
		max_range_tree st;
		struct node* C[2];
		node()
		{
			st.build();
			C[0] = NULL;
			C[1] = NULL;
		}
		node* getc(int c)
		{
			if (C[c] == NULL)
			{
				C[c] = new node;
			}
			return C[c];		
		}
		void update(int x1, int x2, int x, int y, int val)
		{
			if (x<x1 || x>x2)
				return;
			if (x1 == x2)
			{
				st.update(y, val);
				return;
			}
			int mid = (x1 + x2) / 2;
			getc(0)->update(x1, mid, x, y, val);
			getc(1)->update(mid + 1, x2, x, y, val);
			int ans = maximum(getc(0)->st.query(y, y), getc(1)->st.query(y, y));
			st.update(y, ans);
		}
		int query(int x1, int x2, int qx1, int qx2, int qy1, int qy2)
		{
			if (x2<qx1 || x1>qx2)
			{
				return 0;
			}
			if (x1 >= qx1 && x2 <= qx2)
			{
				return st.query(qy1, qy2);
			}
			int mid = (x1 +x2) / 2;
			int a = getc(0)->query(x1, mid, qx1, qx2, qy1, qy2);
			int b = getc(1)->query(mid + 1, x2, qx1, qx2, qy1, qy2);
			return maximum(a, b);
		}
	};
	node* top;
public:void build()
{
	top = new node;
}
public:void update(int x, int y, int val)
{
	top->update(0, 2 * inf, x, y, val);
}
public:int query(int x1, int y1, int x2, int y2)
{
	return top->query(0, 2 * inf, x1, x2, y1, y2);
}
};
//string
class trie
{
	static const int ALPHABET_SIZE = 26;
	struct TrieNode
	{
		struct TrieNode* children[ALPHABET_SIZE];
		bool isEndOfWord;
	};
	struct TrieNode* getNode(void)
	{
		struct TrieNode* pNode = new TrieNode;
		pNode->isEndOfWord = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;

		return pNode;
	}
public:TrieNode* root;
public:void insert(struct TrieNode* root, string& key)
{
	struct TrieNode* pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}
public:bool search(struct TrieNode* root, string& key)
{
	struct TrieNode* pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}
public:void build(vector<string>& a)
{
	root = getNode();
	trav(x, a)
		insert(root, x);
}
public:void build()
{
	root = getNode();
}
};

class segtreebeats// needs to be modified
{
		struct item
		{
			ll val, max;
		};
		item single(ll i)
		{
			return { i,-1 };
		}
		vector<item> tree;
		vector<item>A;
		int height;
		item neutral = { 0,-1 };
		void push(int i, int tl, int tr)
		{
			if (tree[i].max != -1)
			{
				if (tl == tr)
				{
					tree[i].val = max(tree[i].val, tree[i].max);
				}
				else
				{
					tree[2 * i + 1].max = max(tree[2 * i + 1].max, tree[i].max);
					tree[2 * i + 2].max = max(tree[2 * i + 2].max, tree[i].max);
				}
				tree[i].max = -1;
			}
		}
	public:void build(vll& B)
	{
		int	n = B.size();
		height = log2(n - 1) + 1;
		A.rsz(n);
		tree.rsz((1 << height + 1) - 1);
		F0R(i, n)A[i] = single(B[i]);
		A.rsz(1 << height, neutral);
		build(A, 0, 0, (1 << height) - 1);
	}
		   void build(vector<item>& A, int v, int tl, int tr)
		   {
			   if (tl == tr)
				   tree[v] = A[tl];
			   else
			   {
				   int mid = (tl + tr) / 2;
				   build(A, 2 * v + 1, tl, mid);
				   build(A, 2 * v + 2, mid + 1, tr);
				   tree[v].max = -1;
			   }
		   }
	public:ll query(int l)
	{
		return query(0, 0, (1 << height) - 1, l).val;
	}
		   item query(int v, int tl, int tr, int i)
		   {
			   push(v, tl, tr);
			   if (tl == tr)
			   {
				   return tree[v];
			   }
			   int mid = (tl + tr) / 2;
			   if (mid >= i)return query(2 * v + 1, tl, mid, i);
			   else return query(2 * v + 2, mid + 1, tr, i);
		   }
	public:void update(int r, int val)
	{
		update(0, 0, (1 << height) - 1, r, single(val));
	}
		   void update(int v, int tl, int tr, int i, item val)
		   {
			   push(v, tl, tr);
			   if (tl == tr)
			   {
				   tree[v] = val;
				   return;
			   }
			   int mid = (tl + tr) / 2;
			   if (mid >= i)return update(2 * v + 1, tl, mid, i, val);
			   else return update(2 * v + 2, mid + 1, tr, i, val);
		   }
	public:void update1(int l, int r, int val)
	{
		update1(0, 0, (1 << height) - 1, l, r, val);
	}
		   void update1(int v, int tl, int tr, int l, int r, int val)
		   {
			   push(v, tl, tr);
			   if (tl > r || tr < l)return;
			   if (tl >= l && tr <= r)
			   {
				   tree[v].max = val;
				   push(v, tl, tr);
				   //tree[v].sum += ((ll)tr - tl + 1) * val;
			   }
			   else
			   {
				   int mid = (tl + tr) / 2;
				   update1(2 * v + 1, tl, mid, l, r, val);
				   update1(2 * v + 2, mid + 1, tr, l, r, val);
			   }
		   }
};

// Offline version. merge must be associative: https://en.wikipedia.org/wiki/Associative_property
struct divide_conquer
{
	int n, q;
	int mode = 0;
	struct item
	{
		int x;
	};
	item single(int i)
	{
		return { i };
	}
	item merge(item& x, item& y)
	{
		return { min(x.x,y.x) };
	}
	vector<item>a;
	vi ans;
	void init(int n, int q, vi& a)
	{
		mode = 1;
		this->n = n;
		this->q = q;
		this->a.rsz(n);
		F0R(i, n)this->a[i] = single(a[i]);
	}
	void solve(int i, int j, vector<pair<pii, int>>& queries)
	{
		if (sz(queries) == 0)return;
		if (i == j)
		{
			trav(x, queries)
			{
				assert(x.f.f == i && x.f.s == i);
				ans[x.s] = a[i].x;
			}
			return;
		}
		int m = (i + j) / 2;
		vector<item>l(m - i + 1), r(j - m);// l is [i,m], r is [m+1,j]
		l[0] = a[m];
		ROF(k, i, m)
		{
			l[m - k] = merge(a[k], l[m - k - 1]);
		}
		r[0] = a[m + 1];
		FOR(k, m + 2, j + 1)
		{
			r[k - m - 1] = merge(r[k - m - 2], a[k]);
		}
		vector<pair<pii, int>>lq, rq;
		trav(x, queries)
		{
			if (x.f.f <= m && x.f.s > m)
			{
				ans[x.s] = merge(l[m - x.f.f], r[x.f.s - m - 1]).x;
			}
			else if (x.f.f <= m)
			{
				lq.push_back(x);
			}
			else
			{
				rq.push_back(x);
			}
		}
		solve(i, m, lq);
		solve(m + 1, j, rq);
	}
	void solve(vector<pair<pii, int>>& queries)
	{
		assert(mode);
		ans.rsz(q);
		solve(0, n - 1, queries);
	}
	vi get()
	{
		assert(sz(ans) == q);
		return ans;
	}
};

int main()
{


}