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
const int MAX = 1500;
int n, m, q;
string a[MAX];
pii A, B;
vi adj[2250000];
vector<vpi>t;
struct bcc
{
	vpi cur;
	int n;
	vi low, disc, parent;
	vpi todo;// stack
	int TIME = -1;
	void init(int x)
	{
		n = x;
		low.rsz(n, -1);
		disc.rsz(n, -1);
		parent.rsz(n, -1);
		TIME = 0;
	}
	void dfs(int i)
	{
		low[i] = ++TIME;
		disc[i] = TIME;
		int child = 0;
		trav(x, adj[i])
		{
			if (disc[x] == -1)
			{
				child++;
				todo.pb({ i,x });
				parent[x] = i;
				dfs(x);
				low[i] = min(low[i], low[x]);
				if ((disc[i] == 1 && child > 1) || (disc[i] > 1 && low[x] >= disc[i]))
				{
					while (todo.back() != mp(i, x))
					{
						//cout << todo.back().f << " " << todo.back().s << endl;
						cur.push_back({ todo.back().f,todo.back().s });
						todo.pop_back();
					}
					//cout << todo.back().f << " " << todo.back().s << endl;
					cur.push_back({ todo.back().f,todo.back().s });
					t.pb(cur);
					cur.clear();
					todo.pop_back();
				}
			}
			else if (parent[i] != x && disc[x] < low[i])
			{
				low[i] = disc[x];
				todo.push_back({ i,x });
			}
		}
	}
	void biconnected_components()
	{
		assert(TIME != -1);
		t.clear();
		F0R(i, n)
		{
			if (disc[i] == -1)
			{
				dfs(i);
				while (sz(todo))
				{
					//cout << todo.back().f << " " << todo.back().s << endl;
					cur.push_back({ todo.back().f,todo.back().s });
					todo.pop_back();
				}
				if (sz(cur))
				{
					t.push_back(cur);
					cur.clear();
				}
			}
		}
	}
};
bool check(int i, int j)
{
	return i >= 0 && j >= 0 && i < n&& j < m&& a[i][j] != '#';
}
vector<set<int>>comp;
bool intersect(int i, int j)
{
	trav(x, comp[i])
	{
		if (comp[j].count(x))return 1;
	}
	return 0;
}
bitset<MAX> visited[MAX];
void init(int i, int j)
{
	visited[i][j] = 1;
	F0R(k, 4)
	{
		int x = i + dx[k], y = j + dy[k];
		if (check(x, y) && visited[x][y] == 0 && a[x][y] != 'B')
		{
			init(x, y);
		}
	}
}
const int SZ = 9000000;// 4*MAX*MAX
bitset<SZ> ans;
void dfs(int i, int j, int d)
{
	ans[d * n * m + m * i + j] = 1;
	// push box
	if (check(i + dx[d], j + dy[d]) && !ans[d * n * m + m * (i + dx[d]) + (j + dy[d])])
	{
		dfs(i + dx[d], j + dy[d], d);
	}
	F0R(k, 4)
	{
		if (k == d)continue;
		int x = i + dx[(d + 2) % 4], y = j + dy[(d + 2) % 4];
		int x1 = i + dx[(k + 2) % 4], y1 = j + dy[(k + 2) % 4];
		if (check(x, y) && check(x1, y1) && !ans[k * n * m + m * i + j])
		{
			if (intersect(m * x + y, m * x1 + y1))
			{
				//ans[k * n * m + m * x1 + y1] = 1;
				dfs(i, j, k);
			}
		}
	}
}
int main()
{
	setIO("pushabox");
	cin >> n >> m >> q;
	//a.rsz(n);
	F0R(i, n)cin >> a[i];
	F0R(i, n)
	{
		F0R(j, m)
		{
			if (a[i][j] == 'A')A = { i,j };
			if (a[i][j] == 'B')B = { i,j };
		}
	}
	//adj.rsz(n* m);
	F0R(i, n)
	{
		F0R(j, m)
		{
			if (!check(i, j))continue;
			F0R(k, 4)
			{
				int x = i + dx[k], y = j + dy[k];
				if (check(x, y))
				{
					adj[m * i + j].push_back(m * x + y);
				}
			}
		}
	}
	bcc graph;
	graph.init(n * m);
	graph.biconnected_components();
	comp.rsz(n * m);
	F0R(i, sz(t))
	{
		trav(y, t[i])
		{
			comp[y.f].insert(i);
			comp[y.s].insert(i);
		}
	}
	init(A.f, A.s);
	// O( 4 * 4 * 4 * n * m )
	//ans.rsz(4 * n * m);
	F0R(k, 4)
	{
		int x = B.f + dx[k], y = B.s + dy[k];
		if (check(x, y) && visited[x][y])
			dfs(B.f, B.s, (k + 2) % 4);
	}
	// O(q) optimized
	F0R(i, q)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		bool t = 0;
		F0R(k, 4)
		{
			int x = a + dx[(k + 2) % 4], y = b + dy[(k + 2) % 4];
			if (check(x, y) && ans[k * m * n + m * a + b])
				t = 1;
		}
		cout << (t || B == mp(a, b) ? "YES" : "NO") << endl;
	}
}