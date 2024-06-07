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
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353
const ld pi = 3.1415926535;

void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, sz(a)) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, sz(a)) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (sz(s))
	{
		freopen((s + ".in").c_str(), "r", stdin);
		if (s != "test1")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
int n, m;
vector<vi>adj;
vpi edge;
vi depth, tin, tout, parents;
int TIME;
void init(int i, int p)
{
	tin[i] = TIME++;
	parents[i] = p;
	trav(x, adj[i])
	{
		if (x != p)
		{
			depth[x] = depth[i] + 1;
			init(x, i);
		}
	}
	tout[i] = TIME++;
}
bool is_ancestor(int anc, int node)
{
	return tin[anc] <= tin[node] && tout[anc] >= tout[node];
}
int SZ = 20;
vector<vi>jump;
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
vll prefix;
void dfs(int i, int p)
{
	trav(x, adj[i])
	{
		if (x != p)
		{
			prefix[x] += prefix[i];
			dfs(x, i);
		}
	}
}
int get(int i, int dist)
{
	if (dist == -1)return -1;
	int total = SZ - 1;
	while (total + 1)
	{
		if (dist & (1 << total))
		{
			i = jump[i][total];
		}
		total--;
	}
	return i;
}
int main()
{
	setIO("exercise");
	cin >> n >> m;
	adj.rsz(n);
	F0R(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	F0R(i, m - n + 1)
	{
		int a, b;
		cin >> a >> b;
		edge.push_back({ --a,--b });
	}
	depth.rsz(n);
	parents.rsz(n);
	tin.rsz(n);
	tout.rsz(n);
	init(0, -1);
	jump.rsz(n, vi(SZ));
	F0R(i, n)jump[i][0] = parents[i];
	F0R(j, SZ - 1)
	{
		F0R(i, n)
		{
			int a = jump[i][j];
			if (a == -1)jump[i][j + 1] = -1;
			else jump[i][j + 1] = jump[a][j];
		}
	}
	map<pii, int>count;
	prefix.rsz(n);
	ll ans = 0;
	vi lc(sz(edge));
	F0R(i, sz(edge))
	{
		int lca = LCA(edge[i].f, edge[i].s);
		int a = get(edge[i].f, depth[edge[i].f] - depth[lca] - 1), b = get(edge[i].s, depth[edge[i].s] - depth[lca] - 1);
		if (a != -1)
		{
			//count[{a, lca}]++;
			//count[{b, lca}]++;
			ans -= prefix[a] + 1;
			prefix[a]++;
		}
		if (b != -1)
		{
			ans -= prefix[b] + 1;
			prefix[b]++;
		}
		if (a != -1 && b != -1)
		{
			if (a > b)swap(a, b);
			ans -= count[{a, b}];
			count[{a, b}]++;
		}
		lc[i] = lca;
	}/*
	trav(x, count)ans -= ((ll)x.s - 1) * x.s/2;
	F0R(i, n)
	{
		ans -= ((ll)prefix[i] + 1) * prefix[i] / 2;
	}*/
	dfs(0, -1);
	F0R(i, sz(edge))
	{
		int lca = lc[i];
		ans += prefix[edge[i].f] - prefix[lca];
		ans += prefix[edge[i].s] - prefix[lca];
	}
	cout << ans << endl;
}