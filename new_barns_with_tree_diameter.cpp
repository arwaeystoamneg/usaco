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
int SZ = 18;
struct tree
{
	map<int, int>index;
	int n;
	vi depth;
	int d1, d2;
	vector<vi>jump;
	vi parent;
	int dia;
	void init(int x)
	{
		n = 1;
		depth.rsz(n);
		d1 = 0, d2 = 0;
		jump.rsz(1, vi(SZ));
		fill(all(jump[0]), -1);
		index.insert({ x, sz(index) });
		parent.rsz(1, -1);
	}
	int get(int a, int b)
	{
		F0R(j, SZ)
		{
			if (b & (1 << j))
			{
				a = jump[a][j];
			}
		}
		return a;
	}
	int LCA(int a, int b)
	{
		if (depth[a] < depth[b])swap(a, b);
		a = get(a, depth[a] - depth[b]);
		if (a == b)return a;
		int j = SZ;
		while (j)
		{
			j--;
			int ta = jump[a][j], tb = jump[b][j];
			if (ta != tb)a = ta, b = tb;
		}
		return parent[a];
	}
	int dist(int a, int b)
	{
		return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
	}
	void add(int x, int p)
	{
		index.insert({ x,sz(index) });
		x = sz(index) - 1;
		p = index[p];
		n++;
		depth.push_back(0);
		depth[x] = depth[p] + 1;
		parent.push_back(0);
		parent[x] = p;
		jump.pb(vi(SZ));
		jump[x][0] = p;
		F0R(i, SZ - 1)
		{
			jump[x][i + 1] = (jump[x][i] == -1 ? -1 : jump[jump[x][i]][i]);
		}
		int dist1 = dist(x, d1), dist2 = dist(x, d2);
		if (dist1 > dia)
		{
			dia = dist1;
			d2 = x;
		}
		if (dist2 > dia)
		{
			dia = dist2;
			d1 = x;
		}
	}
	int get(int x)
	{
		x = index[x];
		return max(dist(x, d1), dist(x, d2));
	}
};
int main()
{
	setIO("newbarn");
	vector<tree>a;
	map<int, int>index;
	int cur = 0, curi = 0;
	test
	{
		char type;
	cin >> type;
	if (type == 'B')
	{
		int x;
		cin >> x;
		if (x == -1)
		{
			index.insert({ cur++,curi++ });
			a.rsz(curi);
			a[curi - 1].init(cur - 1);
		}
		else
		{
			x--;
			index.insert({ cur++,index[x] });
			a[index[x]].add(cur - 1, x);
		}
	}
	else
	{
		int x;
		cin >> x;
		cout << a[index[x - 1]].get(x - 1) << endl;
	}
	}
}