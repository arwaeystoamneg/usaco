#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

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
const double pi = 3.1415926535;


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
vector<vector<ll>> matrix_mult(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
	vector<vector<ll>> answer;
	answer.resize(n);
	for (int i = 0; i < n; i++) answer[i].resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) // calculate answer[i][j]
		{
			for (int k = 0; k < n; k++)
				answer[i][j] = (answer[i][j] + a[i][k] * b[k][j]) % inf;
		}
	}
	return answer;
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
int popcount(int a)
{
	int count = 0;
	while (a != 0)
	{
		count += (a % 2);
		a >>= 1;
	}
	return count;
}
//end of preprogrammed methods
ll a, b, c;
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);
}
class segment_tree {

	vi tree;   // array of segment tree

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:segment_tree() {
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	   // build the tree using the original array A
public:void buildSegTree(vi& A, int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
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
int n;
vi values;
vi parents;
vector<vi>adj;
vi sizes;
void init()
{
	setIO("promote");
	cin >> n;
	values.rsz(n);
	F0R(i, n)cin >> values[i];
	set<int>t;
	trav(x, values)t.insert(x);
	map<int, int>in;
	a = 0;
	trav(x, t)
	{
		in.insert({ x,a });
		a++;
	}
	F0R(i, n)values[i] = in[values[i]];
	adj.rsz(n);
	parents.rsz(n);
	F0R(i, n - 1)
	{
		cin >> a;
		parents[i + 1] = a - 1;
		adj[a - 1].pb(i + 1);
	}
	parents[0] = -1;
}
vi order;
void preorder(int i)
{
	order.pb(i);
	trav(x, adj[i])
	{
		preorder(x);
		sizes[i] += sizes[x];
	}
}
struct query
{
	int l, r, value, ans, idx;
};
int sqrt_n;
bool co(query x, query y)
{
	if (x.l / sqrt_n == y.l / sqrt_n)return x.r < y.r;
	return x.l < y.l;
}
bool com(query x, query y)
{
	return x.idx < y.idx;
}
vi counts;
segment_tree sum;
void add(int i)
{
	sum.addValue(values[order[i]], 1);
}
void sub(int i)
{
	sum.addValue(values[order[i]], -1);
}
int main()
{
	init();

	sqrt_n = sqrt(n - 1) + 1;
	sizes.rsz(n, 1);
	preorder(0);
	//print_vector(parents);
	//print_vector(adj);
	//print_vector(order);
	//print_vector(sizes);
	//print_vector(values);
	trav(x, sizes)x--;
	vector<query>q;
	q.rsz(n);
	F0R(i, n)
	{
		q[order[i]].l = i;
		q[order[i]].r = i + sizes[order[i]];
		q[order[i]].value = values[order[i]];
		q[order[i]].idx = order[i];
	}
	sort(all(q), co);
	//trav(x, q)cout << x.l << " " << x.r << " " << x.value << " " << x.idx << endl;
	counts.rsz(n + 1);
	int l = 0, r = 0;
	counts[values[order[0]]] = 1;
	sum.buildSegTree(counts, n);
	F0R(i, n)
	{
		while (l < q[i].l)
		{
			sub(l);
			l++;
		}
		while (l > q[i].l)
		{
			l--;
			add(l);
		}
		while (r > q[i].r)
		{
			sub(r);
			r--;
		}
		while (r < q[i].r)
		{
			r++;
			add(r);
		}
		q[i].ans = sum.getSum(q[i].value + 1, n);
	}
	sort(all(q), com);
	F0R(i, n)cout << q[i].ans << endl;
}