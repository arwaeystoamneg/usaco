#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
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
#define endl '\n'
#define ednl '\n'
#define test int t;cin>>t;while(t--)
#define vin(v,n) vi (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vlln(v,n) vector<ll> (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vvin(v,n,m) vector<vi>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define vvlln(v,n,m) vector<vector<ll>>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pq priority_queue
const ll linf = 4000000000000000000LL;
const int inf = 1000000007;
const ld pi = 3.1415926535;

int n;
vector<vector<pii>>adj;

// code for find lca
const int K = 20;
vector<int> h;
vector<int> tin;
vector<int> tout;
vector<vector<int>> go;
int timer = 0;
void dfs_lca(int u, int d, int p) {
	tin[u] = timer++;
	go[0][u] = p;
	h[u] = d;
	for (int k = 1; k < K; ++k) {
		go[k][u] = go[k - 1][go[k - 1][u]];
	}
	for (auto v : adj[u]) {
		if (v.first != p) dfs_lca(v.first, d + 1, u);
	}
	tout[u] = timer++;
}

// code for ancestor
bool anc(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

// code for lca
int lca(int a, int b) {
	if (anc(a, b)) return a;
	if (anc(b, a)) return b;
	for (int k = K - 1; k >= 0; --k) {
		//loop until a is not b's ancestor
		if (!anc(go[k][a], b)) {
			a = go[k][a];
		}
	}
	return go[0][a];
}

class max_tree {

	vi tree;   // array of segment tree
	int counts = 0;
	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:max_tree() {
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	   // build the tree using the original array A
public:void build_max_tree(vi& A, int n) {
	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}

	   // p: ID of current node
	   // low: left end of the range of node x (inclusive)
	   // high: right end of the range of node x (inclusive)
	   // A: original array
public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	int mid = (low + high) / 2;
	//cout << low << " " << high << endl;
	tree[p] = max(buildSegTreeRec(low, mid, leftChild(p), A), buildSegTreeRec(mid + 1, high, rightChild(p), A));

	return tree[p];
}


	   // find the partial sum between A[x...y], inclusive (0-based)
public:int get_max(int x, int y) {

	if (x < 0 || ENDINDEX < y)
		return -INT_MAX;

	return get_max1(STARTINDEX, ENDINDEX, x, y, 0);
}

	   // p: ID of current node in the segment tree
	   // [low, high]: range of current node
	   // [x, y]: query range
public:int get_max1(int low, int high, int x, int y, int p) {

	if (x <= low && high <= y)  // [x, y] contains [low, high]
		return tree[p];

	if (y < low || high < x)   // [x, y] doesn't overlap [low, high]
		return 0;

	int mid = (low + high) / 2;

	return max(get_max1(low, mid, x, y, leftChild(p)), get_max1(mid + 1, high, x, y, rightChild(p)));;
}

	   // this function sets haybale at pos to val
public:void set_to(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, val, 0);
}

	   // p: ID of current node in the segment tree
	   // [low, high]: range of current node
	   // pos: position to be modified
	   // val: the change to the specified position
public:void addValueRec(int low, int high, int pos, int val, int p) {
	if (low <= pos && pos <= high) {
		if (low != high) {
			int mid = (low + high) / 2;
			addValueRec(low, mid, pos, val, leftChild(p));
			addValueRec(mid + 1, high, pos, val, rightChild(p));
		}
		if (low != high)
			tree[p] = max(tree[leftChild(p)], tree[rightChild(p)]);
		if (low == high)
			tree[p] = val;
	}
}
};
template<int SZ>struct lca
{
	int n;
	vector<vi>adj;
	vector<vi>jump;
	vi parent, depth;
	void dfs(int i, int p)
	{
		parent[i] = p;
		trav(x, adj[i])
		{
			if (x == p)continue;
			depth[x] = depth[i] + 1;
			dfs(x, i);
		}
	}
	void init(vector<vi>& x)
	{
		adj = x;
		n = sz(adj);
		parent.rsz(n);
		depth.rsz(n);
		dfs(0, -1);
		jump.rsz(n, vi(SZ));
		F0R(i, n)jump[i][0] = parent[i];
		F0R(i, SZ - 1)
		{
			F0R(j, n)jump[j][i + 1] = (jump[j][i] == -1 ? -1 : jump[jump[j][i]][i]);
		}
	}
	int get(int a, int b)
	{
		F0R(j, SZ)
		{
			if (b & (1 << j))
			{
				a = jump[a][j];
			}
		}
		return a;
	}
	int LCA(int a, int b)
	{
		if (depth[a] < depth[b])swap(a, b);
		a = get(a, depth[a] - depth[b]);
		if (a == b)return a;
		int j = SZ;
		while (j)
		{
			j--;
			int ta = jump[a][j], tb = jump[b][j];
			if (ta != tb)a = ta, b = tb;
		}
		return parent[a];
	}
	int dist(int a, int b)
	{
		return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
	}
};
class lca_
{
	int n, a;
	struct node
	{
		int depth, tin, tout, parent;
		vi val;
	};
	vector<node>tree;
	bool is_ancestor(int anc, int node)
	{
		return tree[anc].tin <= tree[node].tin && tree[anc].tout >= tree[node].tout;
	}
	int LCA(int x, int y)//LCA with Sparse Table
	{
		if (tree[x].depth > tree[y].depth)swap(x, y);
		if (is_ancestor(x, y))return x;
		int j = 17;
		int next;
		while (!is_ancestor(tree[x].parent, y))
		{
			next = jump[x][j];
			if (next == -1 || is_ancestor(next, y))
			{
				j--;
			}
			else
			{
				x = next;
			}
		}
		return tree[x].parent;
	}
	vi tin, tout, depth, parents;// size n, parent[0]=-1, depth[0] = 0
	bool is_ancestor(int anc, int node)
	{
		return tin[anc] <= tin[node] && tout[anc] >= tout[node];
	}
	//building the sparse table for LCA
	int SZ;
	vector<vi>jump;/*
	void init(int i, int p)
	{
		tin[i] = a++;
		parents[i] = p;
		trav(x, adj[i])
		{
			if (x != p)
			{
				depth[x] = depth[i] + 1;
				init(x, i);
			}
		}
		tout[i] = a++;
	}
	*///init(0,-1);
	void build_table()
	{
		assert(SZ);
		// just take the code from here
		jump.rsz(n);
		F0R(i, n)jump[i].rsz(SZ + 1);
		F0R(i, n)jump[i][0] = parents[i];
		FOR(i, 1, SZ + 1)F0R(j, n)
		{
			int a = jump[j][i - 1];
			if (a != -1)jump[j][i] = jump[a][i - 1];
			else jump[j][i] = -1;
		}
		// to here
	}
	// take this entire piece from here
	int LCA(int x, int y)//LCA with Sparse Table
	{
		if (depth[x] > depth[y])swap(x, y);
		if (is_ancestor(x, y))return x;
		int j = SZ - 1;
		int next;
		while (!is_ancestor(parents[x], y))
		{
			next = jump[x][j];
			if (next == -1 || is_ancestor(next, y))
			{
				j--;
			}
			else
			{
				x = next;
			}
		}
		return parents[x];
	}
	// to here
	int get(int i, int dist)
	{
		int total = 1 << 30;
		while (total != 0)
		{
			if (dist & total)
			{
				i = jump[i][log2(total)];
			}
			total >>= 1;
		}
		return i;
	}
};

class centroid
{

	int n, a, b;
	vector<vi>adj;
	vi visited;//rsz(n)
	vi sizes;//rsz(n)
	void dfs(int i, int p)
	{
		// visit i
		sizes[i] = 1;
		for (auto x : adj[i])
		{
			if (x == p || visited[i] == 1)
				continue;
			dfs(x, i);
			sizes[i] += sizes[x];
		}
	}

	int dfs_centroid(int i, int p, int n)
	{
		// visit i, find the centroid c
		// recurrent if i has a subtree larger than n/2;
		for (auto x : adj[i])
		{
			if (x == p)
				continue;
			if (sizes[x] > n / 2)
				return dfs_centroid(x, i, n);
		}
		return i;
	}
	vi parent;//rsz(n)
	//build(0,-1)
	void build(int i, int p)
	{
		// first dfs to generate size of subtree starting from node i
		// 2nd dfs to find the centroid
		dfs(i, p);
		int centroid = dfs_centroid(i, p, sizes[i]);
		visited[centroid] = 1;
		parent[centroid] = p;
		//cout << centroid << endl;
		// remove the edge from centroid to all its child, build from its child
		for (auto x : adj[centroid])
		{
			if (x == parent[centroid])
				continue;
			//cout << "working on subtree of " << x << endl;
			if (visited[x])
				continue;
			build(x, centroid);
		}
	}
};
//HLD

vi w;
vi sizes;
vi parents;
vi special_child;
vi head;
vi pos;
vi index;
vi A;
void dfs(int i, int p)
{
	//visiting i
	sizes[i] = 1;
	parents[i] = p;
	// go through i's children, find the special child (the child with biggest subtree size)
	int max_subtree_size = 0;
	trav(x, adj[i])
	{
		//skip the parent
		if (x.first != p)
		{
			dfs(x.first, i);
			sizes[i] += sizes[x.first];
			if (sizes[x.first] > max_subtree_size)
			{
				special_child[i] = x.first;
				max_subtree_size = sizes[x.first];
			}
		}
	}
}

int counter = 0;
vector<int> arr;
vector<int> stIndex; //edge lable is the child map edge label to location in segtree 
// put the elements under the same chain together, so that we can create data structure for fast update/queries
void dfs_chain(int u, int p)
{
	// process node u
	// process u's child
	//cout << " visiting " << u << endl;
	for (auto v : adj[u])
	{
		if (v.first == p)
			continue;
		// go down heavy chain until the end of the chain before any other chains
		if (special_child[u] == v.first)
		{
			// this is a heavy edge, need to be stored in the data array to create a segment tree
			// adj[u][v].second
			arr[counter] = v.second;
			stIndex[v.first] = counter;
			counter++;

			dfs_chain(v.first, u);
		}
	}
	for (auto v : adj[u])
	{
		if (v.first == p)
			continue;
		// go down heavy chain until the end of the chain before any other chains
		if (special_child[u] != v.first)
		{
			arr[counter] = v.second;
			stIndex[v.first] = counter;
			counter++;

			dfs_chain(v.first, u);
		}
	}
}

void heavy_light_decompose(int u, int h, int cur_pos)
{
	if (special_child[u] != -1)
		heavy_light_decompose(special_child[u], h, cur_pos + 1);
	// process node u
	head[u] = h; pos[u] = cur_pos;
	//process child of u
	for (auto v : adj[u])
	{
		if (v.first == parents[u])
			continue;
		// process special child, continue the same chain
		if (v.first == special_child[u])
		{
			continue;
		}
		// process other child, start a new chain
		heavy_light_decompose(v.first, v.first, 0);
	}
}
max_tree sum;

// query the path from a to a's ancestor
int queryUp(int a, int lca)
{
	int ans = 0;
	// keeps going up until a meets with lca
	while (a != lca)
	{
		// edge from a is a light edge
		if (a != special_child[parents[a]])
		{
			ans = max(ans, arr[stIndex[a]]);
			a = parents[a];
			continue;
		}
		// determin how much (end at b) to to go in the current heavy chain
		int b = -1;
		if (head[a] == head[lca]) // just stop at lca
			b = lca;
		else // stop at head[a]
			b = head[a];
		//query from a to b (from segtree) and move the start of next path to b
		ans = max(ans, sum.get_max(stIndex[special_child[b]], stIndex[a]));
		a = b;
	}
	return ans;
}

// to query a path from a to b just need to query from a to lca and b to lca
int queryPath(int a, int b)
{
	int tlca = lca(a, b);
	return max(queryUp(a, tlca), queryUp(b, tlca));

}

int main()
{
	int a, b, c;
	cin >> n;
	w.rsz(n);
	F0R(i, n)cin >> w[i];
	adj.rsz(n);
	F0R(i, n - 1)
	{
		cin >> a >> b >> c;
		adj[--a].pb({ --b, c });
		adj[b].pb({ a, c });
	}

	//first dfs to calculate size of subtree and mark the special child
	sizes.rsz(n, 1);
	parents.rsz(n);
	special_child.resize(n, -1);
	dfs(0, - 1);

	// heavy light decomp, goal is to generate the chains according to certain rules
	// output which chain a node belongs to, and pos in the chain
	// input node, wchich chain first node belongs to, currrent postion in the chain
	
	head.resize(n);
	pos.resize(n);
	index.rsz(n);
	heavy_light_decompose(0, 0, 0);

	//put all elements under each chain together this way we can construct segment tree/sparse table to speed up queries

	arr.resize(n);
	stIndex.resize(n, -1);
	dfs_chain(0, -1);

	//trav(x, A)cout << x << ednl;
	sum.build_max_tree(arr, n);

	// preparation for lca
	tin.resize(n);
	tout.resize(n);
	h.resize(n);
	go.resize(K);
	for (int i = 0; i < K; i++)
		go[i].resize(n);

	dfs_lca(0, 0, 0);
	//cout << lca(13, 17) << endl;

	//cout << queryPath(2, 4) << endl;
	//cout << queryPath(8, 13) << endl;
	cout << queryPath(10, 22) << endl;
	return 0;
}