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
// warning: ld is rougly 2x slower than double. Proof: ld: https://oj.uz/submission/319677 double: https://oj.uz/submission/319678
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
#define endl '\n'
#define test int testc;cin>>testc;while(testc--)
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
	ll k = 1LL << 60;
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
	bool operator<(const pt& rhs)const
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
vll prefix_hash(string& a, vll& powers, ll mod)
{
	int n = sz(a);
	vll prefix(n + 1);
	F0R(i, n)prefix[i + 1] = (prefix[i] + powers[i] * (a[i] - '1' + 1)) % mod;
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
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (sz(s))
	{
		freopen((s + ".in").c_str(), "r", stdin);
		if (s != "test3")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
int r, c, n;
vector<string>a;
vector<vi>b;
bool check(int i, int j)
{
	return i >= 0 && j >= 0 && i < r && j < c;
}
void dfs(int i, int j)
{
	b[i][j] = n;
	F0R(k, 4)
	{
		if (check(dx[k] + i, dy[k] + j) && b[dx[k] + i][dy[k] + j] == -1 && a[dx[k] + i][dy[k] + j] == 'X')dfs(dx[k] + i, dy[k] + j);
	}
}
vector<vi>get(int t)
{
	vector<vi>dist(r, vi(c, inf));
	deque<pii> todo;
	F0R(i, r)F0R(j, c)if (b[i][j] == t)todo.pb({ i,j }), dist[i][j] = 0;
	while (sz(todo))
	{
		int i = todo.front().f;
		int j = todo.front().s;
		todo.pop_front();
		F0R(k, 4)
		{
			if (check(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] != '.' && dist[i + dx[k]][j + dy[k]] > dist[i][j] + (a[i][j] == 'S'))
				dist[i + dx[k]][j + dy[k]] = dist[i][j] + (a[i][j] == 'S'), todo.pb({ i + dx[k],j + dy[k] });
		}
	}
	return dist;
}
vector<vector<vi>>dist;
vector<vi>adj;
vector<vi>dp;
void solve(int i, int mask)
{
	F0R(j, n)
	{
		if (!(mask & (1 << j)))
			dp[j][(1 << j) ^ mask] = min(dp[i][mask] + adj[i][j], dp[j][(1 << j) ^ mask]);
	}
}
int main()
{
	setIO("island");
	cin >> r >> c;
	a.rsz(r);
	F0R(i, r)cin >> a[i];
	b.rsz(r, vi(c, -1));
	F0R(i, r)
	{
		F0R(j, c)
		{
			if (b[i][j] == -1 && a[i][j] == 'X')
				dfs(i, j), n++;
		}
	}
	F0R(i, n)dist.pb(get(i));
	/*
	F0R(i, n)
	{
		cout << i << endl;
		pv(dist[i]);
		cout << endl;
	}*/
	adj.rsz(n, vi(n, inf));
	F0R(i, n)
	{
		F0R(j, r)
		{
			F0R(k, c)
			{
				if (a[j][k] == 'X')
					adj[i][b[j][k]] = min(adj[i][b[j][k]], dist[i][j][k]);
			}
		}
	}
	//pv(adj);
	int total = 1 << n;
	dp.rsz(n, vi(total, inf));
	F0R(i, n)dp[i][1 << i] = 0;
	F0R(i, total)
	{
		F0R(j, n)
		{
			solve(j, i);
		}
	}
	int ans = inf;
	F0R(i, n)ans = min(ans, dp[i][total - 1]);
	cout << ans << endl;
}