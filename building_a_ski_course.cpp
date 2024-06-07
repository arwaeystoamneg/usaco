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
// warning: ld is about 2x slower than double. Proof: ld: https://oj.uz/submission/319677 double: https://oj.uz/submission/319678
typedef long double ld;
typedef double db;
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
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (sz(s))
	{
		freopen((s + ".in").c_str(), "r", stdin);
		if (s != "test3")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
int n, m, r;
vector<string>c;
vector<vi>visited;
vector<vi>a, b, prefixa, prefixb;
pii solve()
{
	F0R(i, n)F0R(j, m)prefixa[i + 1][j + 1] = prefixa[i + 1][j] + prefixa[i][j + 1] - prefixa[i][j] + a[i][j];
	F0R(i, n)F0R(j, m)prefixb[i + 1][j + 1] = prefixb[i + 1][j] + prefixb[i][j + 1] - prefixb[i][j] + b[i][j];
	F0R(i, n + 1 - r)
	{
		F0R(j, m + 1 - r)
		{
			if (visited[i][j])continue;
			if (prefixa[i + r][j + r] - prefixa[i][j + r] - prefixa[i + r][j] + prefixa[i][j] == r * r)
			{
				return { i,j };
			}
			if (prefixb[i + r][j + r] - prefixb[i][j + r] - prefixb[i + r][j] + prefixb[i][j] == r * r)
			{
				return { i,j };
			}
		}
	}
	return { -1,-1 };
}
int main()
{
	setIO("skicourse");
	cin >> n >> m;
	c.rsz(n);
	trav(x, c)cin >> x;
	a.rsz(n, vi(m));
	b.rsz(n, vi(m));
	F0R(i, n)F0R(j, m)if (c[i][j] == 'R')a[i][j] = 1; else b[i][j] = 1;
	prefixa.rsz(n + 1, vi(m + 1));
	prefixb.rsz(n + 1, vi(m + 1));
	visited.rsz(n, vi(m));
	r = min(n, m);
	int count = 0;
	F0R(i, n * m + n)
	{
		pii t = solve();
		if (t.f == -1) { r--; continue; }
		visited[t.f][t.s] = 1;
		F0R(j, r)
		{
			F0R(k, r)
			{
				if (!a[j + t.f][k + t.s])count++;
				if (!b[j + t.f][k + t.s])count++;
				a[j + t.f][k + t.s] = 1;
				b[j + t.f][k + t.s] = 1;
			}
		}
		if (count == n * m)break;
	}
	cout << r << endl;
}