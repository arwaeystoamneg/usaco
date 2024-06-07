// EXPLOSION!
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
//#define ednl '\n'
#define test int testc;cin>>testc;while(testc--)
#define pr(a, b) trav(x,a)cerr << x << b; cerr << endl;
#define message cout << "Hello World" << endl;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353    

void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, sz(a)) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, sz(a)) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//#ifdef arwaeystoamneg
	if (sz(s))
	{
		freopen((s + ".in").c_str(), "r", stdin);
		if (s != "test1")
			freopen((s + ".out").c_str(), "w", stdout);
	}
	//#endif
}
const int MAX = 100005;
int n;
vpi adj[MAX];
int visited[MAX], sizes[MAX], parent[MAX], dist[MAX], rest[MAX];
map<int, int>temp[2];
ll ans = 0;
void dfs(int i, int p)
{
	// visit i
	sizes[i] = 1;
	for (auto x : adj[i])
	{
		if (x.f == p || visited[i] == 1)
			continue;
		dfs(x.f, i);
		sizes[i] += sizes[x.f];
	}
}
int dfs_centroid(int i, int p, int n)
{
	// visit i, find the centroid c
	// recurrent if i has a subtree larger than n/2;
	for (auto x : adj[i])
	{
		if (x.f == p)
			continue;
		if (sizes[x.f] > n / 2)
			return dfs_centroid(x.f, i, n);
	}
	return i;
}
int cur[2 * MAX];
void dfs1(int i, int p, int r = 0)
{
	if (!rest[i])
	{
		if (dist[i] == 0 || cur[MAX + dist[i]])rest[i] = 1;
	}
	cur[MAX + dist[i]]++;
	if (dist[i] == 0 && r)ans++;
	temp[rest[i]][dist[i]]++;
	trav(x, adj[i])
	{
		if (visited[x.f] || x.f == p)continue;
		dist[x.f] = dist[i] + x.s;
		rest[x.f] = 0;
		dfs1(x.f, i, r | (dist[i] == 0));
	}
	cur[MAX + dist[i]]--;
}
void merge(map<int, int>& a, map<int, int>& b, map<int, int>& c, map<int, int>& d)
{
	if (sz(a) < sz(c))swap(a, c), swap(b, d);
	trav(x, c)
	{
		if (b.find(-x.f) != b.end())
			ans += (ll)b[-x.f] * x.s;
	}
	trav(x, d)
	{
		if (a.find(-x.f) != a.end())
			ans += (ll)a[-x.f] * x.s;
		if (b.find(-x.f) != b.end())
			ans += (ll)b[-x.f] * x.s;
	}
	trav(x, c)a[x.f] += x.s;
	trav(x, d)b[x.f] += x.s;
}
void build(int i, int p)
{
	// first dfs to generate size of subtree starting from node i
	// 2nd dfs to find the centroid
	dfs(i, p);
	int centroid = dfs_centroid(i, p, sizes[i]);
	visited[centroid] = 1;
	parent[centroid] = p;
	map<int, int>a, b;
	trav(x, adj[centroid])
	{
		if (!visited[x.f] && x.f != p)
		{
			rest[x.f] = 0;
			dist[x.f] = x.s;
			dfs1(x.f, centroid);
			merge(a, b, temp[0], temp[1]);
			temp[0].clear();
			temp[1].clear();
		}
	}

	//cout << centroid << endl;
	// remove the edge from centroid to all its child, build from its child
	for (auto x : adj[centroid])
	{
		if (x.f == parent[centroid])
			continue;
		//cout << "working on subtree of " << x << endl;
		if (visited[x.f])
			continue;
		build(x.f, centroid);
	}
}
void init()
{
	build(0, -1);
}
int main()
{
	setIO("yinyang");
	cin >> n;
	F0R(i, n - 1)
	{
		int x, y, z;
		cin >> x >> y >> z;
		z = (z == 0 ? -1 : 1);
		adj[--x].pb({ --y,z });
		adj[y].pb({ x,z });
	}
	init();
	cout << ans << endl;
}