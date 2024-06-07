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


ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
int minimum(int x, int y)
{
	if (x < y)
		return x;
	return y;
}
int floodArea(int N, int M, bool** pos, bool** visited, int i, int j)
{
	if (pos[i][j] == 0)
		return 0;
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < M; j++)
	//		visited[i][j] = 0;
	list<int> a;
	int maxar = -INT_MAX;
	visited[i][j] = 1;
	a.push_back((N + M) * i + j);
	int counts = 1;
	while (!a.empty())
	{
		int index = a.back();
		a.pop_back();
		int row = index / (M + N);
		int col = index % (M + N);
		if ((row + 1 < N) && visited[row + 1][col] == 0 && pos[row + 1][col] == pos[i][j])
		{
			visited[row + 1][col] = 1;
			a.push_back((M + N) * (row + 1) + col);
			//cout << "    adding to flood " << row + 1 << " " << col << endl;
			counts++;
		}
		if ((col + 1 < M) && visited[row][col + 1] == 0 && pos[row][col + 1] == pos[i][j])
		{
			visited[row][col + 1] = 1;
			a.push_back((M + N) * row + (col + 1));
			//cout << "    adding to flood " << row  << " " << col+1  << endl;
			counts++;
		}
		if ((row - 1 >= 0) && visited[row - 1][col] == 0 && pos[row - 1][col] == pos[i][j])
		{
			visited[row - 1][col] = 1;
			a.push_back((M + N) * (row - 1) + col);
			//cout << "    adding to flood " << row-1 << " " << col << endl;
			counts++;
		}
		if ((col - 1 >= 0) && visited[row][col - 1] == 0 && pos[row][col - 1] == pos[i][j])
		{
			visited[row][col - 1] = 1;
			a.push_back((M + N) * row + (col - 1));
			//cout << "    adding to flood " << row  << " " << col-1 << endl;
			counts++;
		}
	}
	//cout << i<<" "<<j<< " "<<counts << endl;
	if (counts > maxar)
	{
		maxar = counts;
	}
	return maxar;
}
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<char>amount)
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
void print_vector(vector<int>amount, int N)
{
	for (auto i = amount.begin(); i != amount.begin() + N; i++)
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
void print_vector(vector<pair<string, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s << endl;
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
void print_vector(vector<tuple<int, int, int, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << " " << get<3>(*i) << endl;
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
void print_map_vector(map<string, vector<bool>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<int, bool> m)
{
	for (map<int, bool>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
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
void make_adjacency()
{
	F0R(i, NN)
	{
		a = i / N;
		b = i % N;
		if (a > 0)
		{
			if (pastures[a][b] == pastures[a - 1][b])
			{
				adjacency[i].pb(mp(i - N, A));
			}
			else
			{
				adjacency[i].pb(mp(i - N, B));
			}
		}
		if (a < N - 1)
		{
			if (pastures[a][b] == pastures[a + 1][b])
			{
				adjacency[i].pb(mp(i + N, A));
			}
			else
			{
				adjacency[i].pb(mp(i + N, B));
			}
		}
		if (b > 0)
		{
			if (pastures[a][b] == pastures[a][b - 1])
			{
				adjacency[i].pb(mp(i - 1, A));
			}
			else
			{
				adjacency[i].pb(mp(i - 1, B));
			}
		}
		if (b < N - 1)
		{
			if (pastures[a][b] == pastures[a][b + 1])
			{
				adjacency[i].pb(mp(i + 1, A));
			}
			else
			{
				adjacency[i].pb(mp(i + 1, B));
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
ll power(ll number, int power, int mod)
{
	ll ans = 1;
	while (number)
	{
		if (((number - 1) & 1) == 0)
		{
			ans *= power;
			ans %= mod;
			ans *= ans;
			ans %= mod;
			number--;
			number >>= 1;
		}
		else
		{
			ans *= ans;
			ans %= mod;
			number >>= 1;
		}
	}
	return ans;
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
//end of preprogrammed methods
ll a, b, c;
class min_tree_lazy {

	vll tree;   // array of segment tree
	vll lazy;

	ll height;   // height of the segment tree
	ll maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	ll STARTINDEX = 0;   // the left most range of any query
	ll ENDINDEX;         // the right most range of any query

public:min_tree_lazy(int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	lazy.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}
public:ll leftChild(int k) { return 2 * k + 1; }
public:ll rightChild(int k) { return 2 * k + 2; }
public:void buildSegTree(vll& A) {
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}
public:ll buildSegTreeRec(ll low, ll high, ll p, vll& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	ll mid = (low + high) / 2;
	tree[p] = min(buildSegTreeRec(low, mid, leftChild(p), A)
		, buildSegTreeRec(mid + 1, high, rightChild(p), A));
	return tree[p];
}
public:ll get_min(ll x, ll y) {
	if (x < 0 || ENDINDEX < y)
		return LLONG_MAX;
	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}
public:ll getSumRec(ll low, ll high, ll l, ll r, ll node) {
	if (r < low || high < l)   // [x, y] doesn't overlap [low, high]
		return LLONG_MAX;
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
	ll mid = (low + high) / 2;
	return min(getSumRec(low, mid, l, r, leftChild(node))
		, getSumRec(mid + 1, high, l, r, rightChild(node)));
}

	   // add "val" at position "pos": A[pos] += val
public:void addValue(ll l, ll r, ll val) {
	addValueRec(STARTINDEX, ENDINDEX, l, r, val, 0);
}
public:void addValueRec(ll low, ll high, ll l, ll r, ll val, ll node) {
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
	ll mid = low + (high - low) / 2;
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


class segment_tree_lazy {

	vll tree;   // array of segment tree
	vll lazy;

	ll height;   // height of the segment tree
	ll maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	ll STARTINDEX = 0;   // the left most range of any query
	ll ENDINDEX;         // the right most range of any query

public:segment_tree_lazy(ll n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	lazy.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}
public:int leftChild(int k) { return 2 * k + 1; }
public:int rightChild(int k) { return 2 * k + 2; }
public:void buildSegTree(vll& A) {
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}
public:ll buildSegTreeRec(ll low, ll high, ll p, vll& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	ll mid = (low + high) / 2;
	tree[p] = buildSegTreeRec(low, mid, leftChild(p), A)
		+ buildSegTreeRec(mid + 1, high, rightChild(p), A);
	return tree[p];
}
public:ll getSum(ll x, ll y) {
	if (x < 0 || ENDINDEX < y)
		return -LLONG_MAX;
	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}
public:ll getSumRec(ll low, ll high, ll l, ll r, ll node) {
	if (r < low || high < l)   // [x, y] doesn't overlap [low, high]
		return 0;
	if (lazy[node] != 0)
	{
		tree[node] += (lazy[node] * (high - low + 1));
		if (low != high)
		{
			lazy[leftChild(node)] += lazy[node];
			lazy[rightChild(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (l <= low && high <= r)  // [x, y] contains [low, high]
		return tree[node];
	ll mid = (low + high) / 2;
	return getSumRec(low, mid, l, r, leftChild(node))
		+ getSumRec(mid + 1, high, l, r, rightChild(node));
}

	   // add "val" at position "pos": A[pos] += val
public:void addValue(int l, int r, int val) {
	addValueRec(STARTINDEX, ENDINDEX, l, r, val, 0);
}
public:void addValueRec(ll low, ll high, ll l, ll r, ll val, ll node) {
	if (lazy[node] != 0)
	{
		tree[node] += (lazy[node] * (high - low + 1));
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
		tree[node] += (high - low + 1) * val;
		if (low != high)
		{
			lazy[leftChild(node)] += val;
			lazy[rightChild(node)] += val;
		}
		return;
	}
	ll mid = low + (high - low) / 2;
	addValueRec(low, mid, l, r, val, leftChild(node));
	addValueRec(mid + 1, high, l, r, val, rightChild(node));
	tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
}
public:void print()
{
	print_vector(tree);
	print_vector(lazy);
	cout << ednl;
}
};
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);
}
void init()
{
	setIO("haybales");
}
int main()
{
	init();

	int n, q;
	cin >> n >> q;
	vlln(haybales, n);
	segment_tree_lazy sum(n);
	sum.buildSegTree(haybales);
	min_tree_lazy min(n);
	min.buildSegTree(haybales);
	char d;
	F0R(i, q)
	{
		cin >> d;
		if (d == 'M')
		{
			cin >> a >> b;
			a--; b--;
			cout << min.get_min(a, b) << ednl;
		}
		else if (d == 'S')
		{
			cin >> a >> b;
			a--; b--;
			cout << sum.getSum(a, b) << ednl;
		}
		else
		{
			cin >> a >> b >> c;
			a--; b--;
			min.addValue(a, b, c);
			sum.addValue(a, b, c);
		}
	}
}