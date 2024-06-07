/*
ID: awesome35
LANG: C++14
TASK: buylow
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<chrono>

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
#define pq priority_queue
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const int inf = 1000000007;//998244353
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
void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, a.size()) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, a.size()) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
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
int find(int a)
{
	return links[a] == a ? a : links[a] = find(links[a]);
}
void unite(int a, int b)
{
	links[find(a)] = find(b);
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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
struct custom_hash_fast {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};//O(r)
ll choose(ll n, ll r)
{
	ll p = 1, k = 1;
	if (n - r < r)
		r = n - r;
	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			long long m = gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else
		p = 1;
	return p;
}
class segment_tree_lazy
{
	struct item
	{
		int prefix, suffix, val, lazy, h;
	};
	item single(int i)
	{
		if (i)return { 1,1,1,-1 };
		return { 0,0,0,-1 };
	}
	item merge(item x, item y)
	{
		item ans; ans.h = x.h + 1;
		ans.val = max({ x.val,y.val,x.suffix + y.prefix });
		ans.prefix = x.prefix;
		ans.suffix = y.suffix;
		if (x.prefix == (1 << x.h))
		{
			ans.prefix = x.prefix + y.prefix;
		}
		if (y.suffix == (1 << y.h))
		{
			ans.suffix = y.suffix + x.suffix;
		}
		ans.lazy = -1;
		return ans;
	}
	vector<item> tree;
	int height;
	item neutral = { 0,0,0,-1 };
public:void build(vi& B)
{
	int	n = B.size();
	height = log2(n - 1) + 1;
	tree.rsz((1 << height + 1) - 1);
	vector<item>A(n);
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
public:int query()
{
	push(0, 0, (1 << height) - 1);
	return tree[0].val;
}
public:void update0(int l, int r)
{
	update0(0, 0, (1 << height) - 1, l, r);
}
public:void update1(int l, int r)
{
	update1(0, 0, (1 << height) - 1, l, r);
}
	   void push(int i, int tl, int tr)
	   {
		   if (tree[i].lazy != -1)
		   {
			   if (tree[i].lazy)
			   {
				   tree[i].suffix = tr - tl + 1;
				   tree[i].prefix = tree[i].suffix;
				   tree[i].val = tree[i].suffix;
				   if (tl != tr)
				   {
					   tree[2 * i + 1].lazy = 1;
					   tree[2 * i + 2].lazy = 1;
				   }
				   tree[i].lazy = -1;
			   }
			   else
			   {
				   tree[i].suffix = 0;
				   tree[i].prefix = 0;
				   tree[i].val = 0;
				   if (tl != tr)
				   {
					   tree[2 * i + 1].lazy = 0;
					   tree[2 * i + 2].lazy = 0;
				   }
				   tree[i].lazy = -1;
			   }
		   }
	   }
	   void update0(int v, int tl, int tr, int l, int r)
	   {
		   push(v, tl, tr);
		   if (tl > r || tr < l)return;
		   if (tl >= l && tr <= r)
		   {
			   tree[v].lazy = 0;
			   push(v, tl, tr);
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   update0(2 * v + 1, tl, mid, l, r);
			   update0(2 * v + 2, mid + 1, tr, l, r);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
	   void update1(int v, int tl, int tr, int l, int r)
	   {
		   push(v, tl, tr);
		   if (tl > r || tr < l)return;
		   if (tl >= l && tr <= r)
		   {
			   tree[v].lazy = 1;
			   push(v, tl, tr);
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   update1(2 * v + 1, tl, mid, l, r);
			   update1(2 * v + 2, mid + 1, tr, l, r);
			   tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		   }
	   }
public:void add(int k)
{
	int index = get(0, 0, (1 << height) - 1, k);
	update0(index, index + k - 1);
}
	   int get(int i, int tl, int tr, int k)
	   {
		   push(i, tl, tr);
		   if (tl == tr)
		   {
			   return i - (1 << height) + 1;
		   }
		   int mid = (tl + tr) / 2;
		   push(2 * i + 1, tl, mid);
		   if (tree[2 * i + 1].val >= k)return get(2 * i + 1, tl, mid, k);
		   push(2 * i + 2, mid + 1, tr);
		   if (tree[2 * i + 1].suffix && tree[2 * i + 1].suffix + tree[2 * i + 2].prefix >= k)return mid - tree[2 * i + 1].suffix + 1;
		   return get(2 * i + 2, mid + 1, tr, k);
	   }
};
//end of preprogrammed methods
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int n, m;
int main()
{
	setIO("seating");
	cin >> n >> m;
	vi a(n, 1);
	segment_tree_lazy seats; seats.build(a);
	int ans = 0;
	F0R(i, m)
	{
		char b; cin >> b;
		if (b == 'A')
		{
			int c; cin >> c;
			int val = seats.query();
			if (val < c) { ans++; }
			else
			{
				seats.add(c);
			}
		}
		else
		{
			int c, d; cin >> c >> d; c--; d--;
			seats.update1(c, d);
		}
	}
	cout << ans << endl;
}