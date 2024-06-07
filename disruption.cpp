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
void pv(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<double>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<bool>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void pv(vector<pair<ll, ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void pv(vector<pair<pii, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s << endl;
	cout << endl;
}
void pv(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void pv(vector<vector<string>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<pair<ll, ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
	}
	cout << endl;
}
void pv(vector<vector<vi>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<vector<ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<bool>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void ps(set<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void ps(set<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << i->f << " " << i->s << endl;
	cout << endl;
}
void pv(vector<set<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		ps(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
	}
}
void ps(set<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pm(map<int, vector<int>> m)
{
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<string, vector<string>> m)
{
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<string, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s << endl;
	}
}
void pm(map<string, vector<bool>> m)
{
	for (map<string, vector<bool>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		ps(i->second);
	}
}
void pm(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void pm(map<char, vector<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t';
		pv(i->second);
	}
}
void pm(map<char, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t' << i->second << endl;
	}
}
void pm(map<pii, int> m)
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
/*
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is indexs while .f is weight
		pii temp = todo.top();
		int indexs = temp.second;
		todo.pop();
		if (finalized[indexs])continue;
		finalized[indexs] = 1;
		trav(x, adjacency[indexs])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[indexs])
			{
				dist[x.first] = x.second + dist[indexs];
				parents[x.f] = indexs;
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
		int indexs = temp.s;
		if (visited[indexs])cont;
		a -= temp.f;
		visited[indexs] = 1;
		trav(x, adjacency[indexs])
			if (visited[x.f] == 0)
			{
				todo.push({ -x.s,x.f });
			}
	}
	return a;
}
vector<vector<ll>> matrix_mult(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
	int n = a.size();
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
vector<vector<ll>> matrix_exp(vector<vector<ll>>& a, ll n)
{
	vector<vector<ll>> result;
	result.resize(a.size());

	for (int i = 0; i < a.size(); i++)
	{
		result[i].resize(a[0].size(), 0);
		result[i][i] = 1;
	}
	while (n != 0)
	{
		if (n & 1)
			result = matrix_mult(result, a);
		a = matrix_mult(a, a);
		n = n >> 1;
	}
	return result;
}
// Union-Find
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
struct point
{
	ld x, y;
};
long double area(point x, point y, point z)
{
	return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y - z.x * x.y) / 2.0;
}
bool clockwise(point x, point y, point z)
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

class min_tree_lazy {

	vi tree;   // array of segment tree
	vi lazy;

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:min_tree_lazy() {

}
public:int leftChild(int k) { return 2 * k + 1; }
public:int rightChild(int k) { return 2 * k + 2; }
public:void buildSegTree(vi& A) {
	int n = A.size();
	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize, inf);
	lazy.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
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
		tree[node] = minimum(lazy[node], tree[node]);
		if (low != high)
		{
			lazy[leftChild(node)] = minimum(lazy[leftChild(node)], lazy[node]);
			if (lazy[leftChild(node)] == 0)lazy[leftChild(node)] = lazy[node];
			lazy[rightChild(node)] = minimum(lazy[rightChild(node)], lazy[node]);
			if (lazy[rightChild(node)] == 0)lazy[rightChild(node)] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (l <= low && high <= r)  // [x, y] contains [low, high]
		return tree[node];
	int mid = (low + high) / 2;
	return min(getSumRec(low, mid, l, r, leftChild(node))
		, getSumRec(mid + 1, high, l, r, rightChild(node)));
}
public:void set_to(int l, int r, int val)
{
	set_to(STARTINDEX, ENDINDEX, l, r, val, 0);
}
public:void set_to(int low, int high, int l, int r, int val, int node)
{
	if (lazy[node] != 0)
	{
		tree[node] = minimum(tree[node], lazy[node]);
		if (low != high)
		{
			lazy[leftChild(node)] = minimum(lazy[leftChild(node)], lazy[node]);
			if (!lazy[leftChild(node)])lazy[leftChild(node)] = lazy[node];
			lazy[rightChild(node)] = minimum(lazy[rightChild(node)], lazy[node]);
			if (!lazy[rightChild(node)])lazy[rightChild(node)] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (low > r || high < l)return;
	if (low >= l && high <= r)
	{
		tree[node] = minimum(val, tree[node]);
		if (low != high)
		{
			lazy[leftChild(node)] = minimum(lazy[leftChild(node)], val);
			if (!lazy[leftChild(node)])lazy[leftChild(node)] = val;
			lazy[rightChild(node)] = minimum(lazy[rightChild(node)], val);
			if (!lazy[rightChild(node)])lazy[rightChild(node)] = val;
		}
		return;
	}
	int mid = low + (high - low) / 2;
	set_to(low, mid, l, r, val, leftChild(node));
	set_to(mid + 1, high, l, r, val, rightChild(node));
	tree[node] = min(tree[leftChild(node)], tree[rightChild(node)]);
}
public:void print()
{
	pv(tree);
	pv(lazy);
}
};
vi tin, tout, parents, depth;
bool is_ancestor(int anc, int node)
{
	return tin[anc] <= tin[node] && tout[anc] >= tout[node];
}
int logh;
vector<vi>jump;
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
int n, m;
struct edge
{
	int f, index, s;
};
vector<vector<edge>>adj;
void preorder(int i, int p)
{
	tin[i] = a;
	a++;
	parents[i] = p;
	trav(x, adj[i])
	{
		if (tin[x.f] == -1)
		{
			depth[x.f] = 1 + depth[i];
			preorder(x.f, i);
		}
	}
	tout[i] = a;
	a++;
}
void init_graph()
{
	a = 0;
	tin.rsz(n, -1);
	tout.rsz(n);
	parents.rsz(n);
	depth.rsz(n);
	preorder(0, -1);
	//pv(tin);
	//pv(tout);
	//pv(parents);
	//pv(depth);
	int h = *max_element(all(depth));
	logh = log2(h - 1) + 1;
	jump.rsz(n);
	F0R(i, n)jump[i].rsz(logh + 1);
	F0R(i, n)jump[i][0] = parents[i];
	FOR(i, 1, logh + 1)F0R(j, n)
	{
		a = jump[j][i - 1];
		if (a != -1)jump[j][i] = jump[a][i - 1];
		else jump[j][i] = -1;
	}
}
vi sizes, special_child, head, pos;
void dfs(int i, int p)
{
	//visiting i
	sizes[i] = 1;
	// go through i's children, find the special child (the child with biggest subtree size)
	int max_subtree_size = 0;
	trav(x, adj[i])
	{
		//skip the parent
		if (x.f != p)
		{
			dfs(x.f, i);
			sizes[i] += sizes[x.f];
			if (sizes[x.f] > max_subtree_size)
			{
				special_child[i] = x.f;
				max_subtree_size = sizes[x.f];
			}
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
		if (v.f == parents[u])
			continue;
		// process special child, continue the same chain
		if (v.f == special_child[u])
		{
			continue;
		}
		// process other child, start a new chain
		heavy_light_decompose(v.f, v.f, 0);
	}
}
vi stIndex;
int counter = 0;
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
			stIndex[v.first] = counter;
			counter++;
			dfs_chain(v.first, u);
		}
	}
}
min_tree_lazy mins;
int queryUp(int a, int lca)
{
	int ans = inf;
	// keeps going up until a meets with lca
	while (a != lca)
	{
		// edge from a is a light edge
		if (a != special_child[parents[a]])
		{
			ans = min(ans, mins.get_min(stIndex[a], stIndex[a]));
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
		ans = min(ans, mins.get_min(stIndex[special_child[b]], stIndex[a]));
		a = b;
	}
	return ans;
}
// to query a path from a to b just need to query from a to lca and b to lca
int queryPath(int a, int b)
{
	int tlca = LCA(a, b);
	return min(queryUp(a, tlca), queryUp(b, tlca));
}
void update(int a, int lca, int val)
{
	while (a != lca)
	{
		if (a != special_child[parents[a]])
		{
			mins.set_to(stIndex[a], stIndex[a], val);
			a = parents[a];
			cont;
		}
		int b = -1;
		if (head[a] == head[lca])
			b = lca;
		else
			b = head[a];
		mins.set_to(stIndex[special_child[b]], stIndex[a], val);
		a = b;
	}
}
void updatePath(int a, int b, int val)
{
	int lca = LCA(a, b);
	update(a, lca, val);
	update(b, lca, val);
}
void init_hld()
{
	sizes.rsz(n, 1);
	special_child.rsz(n, -1);
	dfs(0, -1);
	head.rsz(n);
	pos.rsz(n);
	heavy_light_decompose(0, 0, 0);
	stIndex.resize(n, -1);
	dfs_chain(0, -1);
	vi t;
	t.rsz(n, inf);
	mins.buildSegTree(t);
}
vpi query;
void init()
{
	setIO("disrupt");
	cin >> n >> m;
	query.rsz(n - 1);
	adj.rsz(n);
	F0R(i, n - 1)
	{
		cin >> a >> b;
		adj[--a].pb({ (int)--b,i });
		adj[b].pb({ (int)a,i });
		query[i] = { a,b };
	}
}
int main()
{
	init();

	init_graph();

	init_hld();
	/*
	while (cin >> a)
	{
		if (a == 1)
		{
			int d;
			cin >> b >> c >> d;
			updatePath(b, c, d);
			mins.print();
		}
		else
		{
			cin >> b >> c;
			cout << queryPath(b, c) << endl;
		}
	}
	*/
	F0R(i, m)
	{
		cin >> a >> b >> c;
		a--; b--;
		updatePath(a, b, c);
	}
	F0R(i, n - 1)
	{
		a = queryPath(query[i].f, query[i].s);
		if (a == inf)cout << -1 << endl;
		else cout << a << ednl;
	}
}