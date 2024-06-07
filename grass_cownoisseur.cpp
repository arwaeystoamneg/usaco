// can't find the original code :(

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
#define pr(a, b) trav(x,a)cerr << x << b; cerr << endl;
#define message cout << "Hello World" << endl;
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
template<int MAX>struct scc
{
	int mode = 0;
	vector < vector<int> > g, gr;
	bitset<MAX>used;
	vector<int> order, component;

	void dfs1(int v) {
		used[v] = true;
		for (size_t i = 0; i < g[v].size(); ++i)
			if (!used[g[v][i]])
				dfs1(g[v][i]);
		order.push_back(v);
	}

	void dfs2(int v) {
		used[v] = true;
		component.push_back(v);
		for (size_t i = 0; i < gr[v].size(); ++i)
			if (!used[gr[v][i]])
				dfs2(gr[v][i]);
	}
	void init(vector<vi>& adj)
	{
		mode = 1;
		int n = sz(adj);
		g = adj;
		gr.rsz(n);
		F0R(i, n)
		{
			trav(x, adj[i])
			{
				gr[x].push_back(i);
			}
		}
	}
	vi get_component()
	{
		assert(mode);
		int n = sz(g);
		vi ans(n);
		F0R(i, n)if (!used[i])dfs1(i);
		F0R(i, MAX)used[i] = 0;
		int count = 0;
		F0R(i, n)
		{
			int v = order[n - 1 - i];
			if (!used[v])
			{
				dfs2(v);
				trav(x, component)ans[x] = count;
				count++;
				component.clear();
			}
		}
		return ans;
	}
	vi get_2sat()
	{
		int n = sz(g) / 2;
		vi comp = get_component();
		//pv(comp);
		F0R(i, n)
		{
			if (comp[2 * i] == comp[2 * i + 1])
			{
				return {};
			}
		}
		//F0R(i, 2 * n)cout << i << " " << comp[i] << endl;
		int k = *max_element(all(comp)) + 1;
		vector<vi>Adj(k);
		vi sizes(k);
		vi todo;
		F0R(i, 2 * n)
		{
			trav(x, g[i])
			{
				if (comp[i] != comp[x])
				{
					Adj[comp[i]].pb(comp[x]);
				}
			}
		}
		vi ans;
		ans.rsz(2 * n, -1);
		F0R(i, n)
		{
			if (comp[2 * i] < comp[2 * i + 1])
				ans[2 * i] = false, ans[2 * i + 1] = 1;
			else
				ans[2 * i] = true, ans[2 * i + 1] = 0;
		}
		return ans;
	}
};
int n, m;
vector<vi>adj;
int main()
{
	setIO("grass");
	cin >> n >> m;
	adj.rsz(n);
	F0R(i, m)
	{
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
	}
	int k;
	scc<100005>graph;
	graph.init(adj);
	vi comp = graph.get_component();
	k = *max_element(all(comp)) + 1;
	vector<set<int>>t(k);
	F0R(i, n)
	{
		trav(x, adj[i])t[comp[i]].insert(comp[x]);
	}
	adj.clear();
	adj.rsz(k);
	vector<vi>back(k);
	vi sizes(k);
	F0R(i, n)sizes[comp[i]]++;
	F0R(i, k)
	{
		trav(x, t[i])
			if (x != i)
				adj[i].pb(x), back[x].pb(i);
	}
	// already top sorted
	vi dp(k, -inf);
	dp[comp[0]] = sizes[comp[0]];
	R0F(i, comp[0])
	{
		trav(x, adj[i])dp[i] = max(dp[i], dp[x] + sizes[i]);
	}
	int ans = sizes[comp[0]];
	vi best(k, -inf);
	best[comp[0]] = 0;
	FOR(i, comp[0], k)
	{
		trav(x, adj[i])best[x] = max(best[x], best[i] + sizes[x]);
	}
	FOR(i, comp[0], k)
	{
		int cost = -inf;
		trav(x, back[i])
		{
			cost = max(cost, dp[x]);
		}
		cost += best[i];
		ans = max(ans, cost);
	}
	cout << ans << endl;
}