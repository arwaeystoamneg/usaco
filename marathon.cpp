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
#define linf 1000000000000000000LL


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
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<double>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<bool>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<ll, ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<pii, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s << endl;
	cout << endl;
}
void print_vector(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void print_vector(vector<vector<string>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pair<ll, ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
	cout << endl;
}
void print_vector(vector<vector<vi>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<vector<ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<bool>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_set(set<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_set(set<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << i->f << " " << i->s << endl;
	cout << endl;
}
void print_vector(vector<set<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_set(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
}
void print_set(set<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_map(map<int, vector<int>> m)
{
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, vector<string>> m)
{
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s << endl;
	}
}
void print_map(map<string, vector<bool>> m)
{
	for (map<string, vector<bool>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_set(i->second);
	}
}
void print_map(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void print_map(map<char, vector<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t';
		print_vector(i->second);
	}
}
void print_map(map<char, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t' << i->second << endl;
	}
}
void print_map(map<pii, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first.f << " " << i->first.s << " " << i->second << endl;
	}
}
bool comp(pii x, pii y)
{
	if (x.s == y.s)return x.f < y.f;
	return x.s < y.s;
}
struct Graph
{
	int V, E;
	vector<pair<int, pii>> edges; // node a, b, weight

	//constructor
	Graph(int a, int b)
	{
		V = a;
		E = b;
	}

	void addEdge(int a, int b, int w)
	{
		edges.push_back({ w,{a,b} });
	}

	// add function generate adj based on vertices and edges.

	vector<int> links, sizes;

	int find(int a) // return the root for node a
	{
		if (a == links[a])
			return a;
		return links[a] = find(links[a]);
	}

	bool same(int a, int b) // check if node a and b has the same root
	{
		return find(a) == find(b);
	}

	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b]; //a always bigger than b, move subtree b under a
		links[b] = a;
	}

	void sort_edges()
	{
		sort(edges.begin(), edges.end());
	}

	ll kruskalMST()
	{
		sort_edges();
		//initialize for MST
		links.resize(V);
		sizes.resize(V);

		for (int i = 0; i < V; i++)
		{
			links[i] = i;
			sizes[i] = 1;
		}
		ll sum = 0;
		int count = 0;
		F0R(i, E)
		{
			int start = edges[i].s.f;
			int end = edges[i].s.s;
			if (!same(start, end))
			{
				unite(start, end);
				sum += edges[i].f;
				count++;
			}
		}
		if (count != V - 1)return -inf;
		return sum;
	}
};

/*
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is index while .f is weight
		pii temp = todo.top();
		int index = temp.second;
		todo.pop();
		if (finalized[index])continue;
		finalized[index] = 1;
		trav(x, adjacency[index])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[index])
			{
				dist[x.first] = x.second + dist[index];
				parents[x.f] = index;
				todo.push(mp(-dist[x.first], x.f));
			}
		}
	}
}
void build_primes()
{
	primes.reserve(50000);
	vi visited;
	visited.rsz(200000, 0);
	FOR(i, 2, 200000)
	{
		if (visited[i] == 0)
		{
			primes.pb(i);
			a = i;
			while (a < 200000)
			{
				visited[a] = 1;
				a += i;
			}
		}
	}
}
//Prim's Algorithm
// need vector<vpi>adjacency
ll prim()
{
	ll a = 0;
	vi visited;
	visited.rsz(n, 0);
	visited[0] = 1;
	pq<pii>todo;
	trav(x, adjacency[0])
		todo.push({ -x.s,x.f });
	F0R(i, n - 1)
	{
		pii temp = todo.top();
		todo.pop();
		int index = temp.s;
		if (visited[index])cont;
		a -= temp.f;
		visited[index] = 1;
		trav(x, adjacency[index])
			if (visited[x.f] == 0)
			{
				todo.push({ -x.s,x.f });
			}
	}
	return a;
}
bool is_ancestor(int anc,int node)
{
	return tin[anc]<=tin[node]&&tout[anc]>=tout[node];
}
int LCA(int node1, int node2)//using SQRT decomposition
{
	if (depth[node1] > depth[node2])swap(node1, node2);
	if (is_ancestor(node1, node2))return node1;
	int next = jump_parents[node1];
	while (next != -1 && !is_ancestor(next, node2))
	{
		node1 = next;
		next = jump_parents[node1];
	}
	next = parents[node1];
	while (next != -1 && !is_ancestor(next, node2))
	{
		node1 = next;
		next = parents[node1];
	}
	node1 = parents[node1];
	return node1;
}

//building the sparse table for LCA

int h = *max_element(all(depth));
logh = log2(h - 1) + 1;
jump.rsz(n);
F0R(i, n)jump[i].rsz(logh + 1);
F0R(i, n)jump[i][0] = parents[i];
FOR(i, 1, logh + 1)F0R(j, n)
{
	a=jump[j][i - 1];
	if (a != -1)jump[j][i] = jump[a][i - 1];
	else jump[j][i] = -1;
}

int LCA(int x, int y)//LCA with Sparse Table
{
	if (depth[x] > depth[y])swap(x, y);
	if (is_ancestor(x, y))return x;
	int j = logh - 1;
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
*/
int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient 
		int q = a / m;
		int t = m;

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t;
		t = y;

		// Update y and x 
		y = x - q * y;
		x = t;
	}

	// Make x positive 
	if (x < 0)
		x += m0;

	return x;
}
ll power(ll x, ll y)
{
	ll k = 1 << 30;
	ll z = 1;
	while (k != 0)
	{
		z *= z;
		z %= inf;
		if (y >= k)
		{
			z *= x;
			z %= inf;
			y -= k;
		}
		k >>= 1;
	}
	return z;
}
// remember that you need to take abs
long double area(pii x, pii y, pii z)
{
	return ((ll)x.s * y.f + (ll)y.s * z.f + (ll)z.s * x.f - (ll)x.f * y.s - (ll)y.f * z.s - (ll)z.f * x.s) / 2.0;
}
bool clockwise(pii x, pii y, pii z)
{
	return area(x, y, z) > 0;
}
int gcd(int a, int b)
{
	if (a > b)swap(a, b);
	if (a == 0)return b;
	return gcd(a, b % a);
}
//end of preprogrammed methods
class segment_tree {

	vi tree;   // array of segment tree

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:segment_tree(int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	   // build the tree using the original array A
public:void buildSegTree(vi& A) {
	A.rsz(1 << height, 0);
	//print_vector(A);
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

	tree[p] = buildSegTreeRec(low, mid, leftChild(p), A)
		+ buildSegTreeRec(mid + 1, high, rightChild(p), A);

	return tree[p];
}
	   //only works for ordered set implementation
//public:void remove_index(int index)
//{


//}
	   // find the partial sum between A[x...y], inclusive (0-based)
public:int getSum(int x, int y) {

	if (x < 0 || ENDINDEX < y)
		return 0;

	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}

	   // p: ID of current node in the segment tree
	   // [low, high]: range of current node
	   // [x, y]: query range
public:int getSumRec(int low, int high, int x, int y, int p) {

	if (x <= low && high <= y)  // [x, y] contains [low, high]
		return tree[p];

	if (y < low || high < x)   // [x, y] doesn't overlap [low, high]
		return 0;

	int mid = (low + high) / 2;

	return getSumRec(low, mid, x, y, leftChild(p))
		+ getSumRec(mid + 1, high, x, y, rightChild(p));
}

	   // add "val" at position "pos": A[pos] += val
public:void addValue(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, val, 0);
}
	   //not sure if this works
public:void set_remove(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, max(val, tree[pos + (maxSize + 1) / 2]), 0);
}
public:void remove_index(int index) {
	remove_index_rec(0, index + 1);
}
public:void remove_index_rec(int index, int sum) {
	if (leftChild(index) >= maxSize)
	{
		addValue(index - (maxSize + 1) / 2 + 1, -1);
		return;
	}
	if (tree[leftChild(index)] < sum)
		remove_index_rec(rightChild(index), sum - tree[leftChild(index)]);
	else
		remove_index_rec(leftChild(index), sum);
}
	   // p: ID of current node in the segment tree
	   // [low, high]: range of current node
	   // pos: position to be modified
	   // val: the change to the specified position
public:void addValueRec(int low, int high, int pos, int val, int p) {
	if (low <= pos && pos <= high) {
		tree[p] = tree[p] + val;

		if (low != high) {
			int mid = (low + high) / 2;
			addValueRec(low, mid, pos, val, leftChild(p));
			addValueRec(mid + 1, high, pos, val, rightChild(p));
		}
	}
}
public:void print()
{
	print_vector(tree);
}
public:void print_set()
{
	int a = 0;
	F0R(i, tree.size())
		if (i >= maxSize / 2 && tree[i] != 0)
		{
			F0R(j, tree[i])
			{
				a = 1;
				cout << i - maxSize / 2 << " ";
			}
		}
	if (a == 1)
		cout << endl;
	else
		cout << 0 << endl;
}
public:void print_any()
{
	int a = 0;
	F0R(i, tree.size())
		if (i >= maxSize / 2 && tree[i] != 0)
		{
			F0R(j, tree[i])
			{
				cout << i - maxSize / 2 << " ";
				return;
			}
		}
	cout << 0 << endl;
}
public:void clear()
{
	fill(all(tree), 0);
}
};

class max_tree {

	vi tree;   // array of segment tree
	int counts = 0;
	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:max_tree(int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	   // build the tree using the original array A
public:void build_max_tree(vi& A) {
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
public:void print()
{
	print_vector(tree);
}
};
ll a, b, c;
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);
}
int n, q;
vi A, B;
vi dist;
vi save;
void init()
{
	setIO("marathon");
	cin >> n >> q;
	A.rsz(n);
	B.rsz(n);
	F0R(i, n)cin >> A[i] >> B[i];
	dist.rsz(n - 1);
	F0R(i, n - 1)dist[i] = abs(A[i] - A[i + 1]) + abs(B[i] - B[i + 1]);
	save.rsz(n - 2);
	F0R(i, n - 2)save[i] = -abs(A[i] - A[i + 2]) - abs(B[i] - B[i + 2]) + dist[i] + dist[i + 1];
}
int main()
{
	init();

	segment_tree sums(n - 1);
	sums.buildSegTree(dist);
	max_tree max(n - 2);
	max.build_max_tree(save);
	char d;
	F0R(l, q)
	{
		cin >> d;
		if (d == 'Q')
		{
			int i, j;
			cin >> i >> j;
			i--; j--;
			a = sums.getSum(i, j - 1);
			if (j - i >= 2)
			{
				a -= max.get_max(i, j - 2);
			}
			cout << a << endl;
		}
		else
		{
			int i, x, y;
			cin >> i >> x >> y;
			i--;
			A[i] = x;
			B[i] = y;
			if (i > 0)
			{
				a = dist[i - 1];
				dist[i - 1] = abs(x - A[i - 1]) + abs(y - B[i - 1]);
				sums.addValue(i - 1, dist[i - 1] - a);
			}
			if (i < n - 1)
			{
				a = dist[i];
				dist[i] = abs(x - A[i + 1]) + abs(y - B[i + 1]);
				sums.addValue(i, dist[i] - a);
			}
			if (i > 0 && i < n - 1)
			{
				save[i - 1] = abs(x - A[i - 1]) + abs(y - B[i - 1]) + abs(x - A[i + 1]) + abs(y - B[i + 1]) - abs(A[i - 1] - A[i + 1]) - abs(B[i - 1] - B[i + 1]);
				max.set_to(i - 1, save[i - 1]);
			}
			if (i > 1)
			{
				save[i - 2] = abs(A[i - 2] - A[i - 1]) + abs(B[i - 2] - B[i - 1]) + abs(A[i - 1] - A[i]) + abs(B[i - 1] - B[i]) - abs(A[i - 2] - A[i]) - abs(B[i - 2] - B[i]);
				max.set_to(i - 2, save[i - 2]);
			}
			if (i < n - 2)
			{
				save[i] = abs(A[i] - A[i + 1]) + abs(B[i] - B[i + 1]) + abs(A[i + 1] - A[i + 2]) + abs(B[i + 1] - B[i + 2]) - abs(A[i] - A[i + 2]) - abs(B[i] - B[i + 2]);
				max.set_to(i, save[i]);
			}
		}
	}


}