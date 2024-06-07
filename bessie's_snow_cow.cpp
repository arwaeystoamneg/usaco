/*
ID: awesome35
LANG: C++14
TASK: vans
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<chrono>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
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
#define test int testc;cin>>testc;while(testc--)
#define pq priority_queue
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353
const ld pi = 3.1415926535;

void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, sz(a)) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, sz(a)) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
void build_primes(vi& primes, int size)
{
	vi visited;
	visited.rsz(size, 0);
	FOR(i, 2, size)
	{
		if (visited[i] == 0)
		{
			primes.pb(i);
			int a = i;
			while (a < size)
			{
				visited[a] = 1;
				a += i;
			}
		}
	}
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
struct point
{
	ld x, y;
	bool operator<(const point& rhs)const
	{
		if (x == rhs.x)return y < rhs.y;
		return x < rhs.x;
	}
};
struct pt
{
	ll x, y;
	bool operator<(const point& rhs)const
	{
		if (x == rhs.x)return y < rhs.y;
		return x < rhs.x;
	}
};
// remember that you need to take abs
long double area(point x, point y, point z)
{
	return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y - z.x * x.y) / 2.0;
}
bool clockwise(point x, point y, point z)
{
	return area(x, y, z) > 0;
}
// remember that you need to take abs
long double area(pt x, pt y, pt z)
{
	return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y - z.x * x.y) / 2.0;
}
bool clockwise(pt x, pt y, pt z)
{
	return area(x, y, z) > 0;
}
ll gcd(ll a, ll b)
{
	if (a > b)swap(a, b);
	if (a == 0)return b;
	return gcd(a, b % a);
}
int popcount(ll a)
{
	int count = 0;
	while (a)
	{
		count += (a & 1);
		a >>= 1;
	}
	return count;
}
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
vll prefix_hash(string& a, vll& powers)
{
	int n = sz(a);
	vll prefix(n + 1);
	F0R(i, n)prefix[i + 1] = (prefix[i] + powers[i] * (a[i] - 'a' + 1)) % inf;
	return prefix;
}
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	//the return type was size_t. But isnt that problematic?
	uint64_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
struct custom_hash_fast {
	//the return type was size_t. But isnt that problematic?
	uint64_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};
//end of preprogrammed methods
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
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
public:void update(int l, int r, int val)
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
};
int n, q;
vector<vi>adj;
vi tin, tout, sizes, order, indexs;
int timenow;
void dfs(int i, int p)
{
	order.pb(i);
	sizes[i] = 1;
	tin[i] = timenow++;
	trav(x, adj[i])
	{
		if (x != p)
		{
			dfs(x, i);
			sizes[i] += sizes[x];
		}
	}
	tout[i] = timenow++;
}
struct node
{
	int tin, tout, index;
	bool operator<(const node& x)const
	{
		return tin < x.tin;
	}
};
const int MAXN = 100000;
vector<set<node>>active;
segment_tree_lazy sum;
void add(int i, int c)
{
	//working on active[c]
	node t = { tin[i],tout[i],i };
	active[c].insert(t);
	auto it = active[c].lower_bound(t);
	if (it != active[c].begin())
	{
		auto it1 = it;
		it1--;
		if ((*it).tout < (*it1).tout)
		{
			active[c].erase(it);
			return;
		}
	}
	sum.add(indexs[i], indexs[i] + sizes[i] - 1, 1);
	while (1)
	{
		auto it1 = it;
		it1++;
		if (it1 == active[c].end())break;
		if ((*it1).tout < (*it).tout)
		{
			sum.add(indexs[(*it1).index], indexs[(*it1).index] + sizes[(*it1).index] - 1, -1);
			active[c].erase(it1);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	setIO("snowcow");
	cin >> n >> q;
	adj.rsz(n);
	F0R(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	tin.rsz(n);
	tout.rsz(n);
	sizes.rsz(n);
	dfs(0, -1);
	indexs.rsz(n);
	F0R(i, n)indexs[order[i]] = i;
	active.rsz(MAXN);
	vll t(n);
	sum.build(t);
	F0R(i, q)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			add(a, b);
		}
		else
		{
			int a;
			cin >> a;
			a--;
			cout << sum.query(indexs[a], indexs[a] + sizes[a] - 1) << endl;
		}
	}
}