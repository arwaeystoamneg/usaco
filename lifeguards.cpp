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
struct guard
{
	int a, b;
	bool operator<(const guard& x)const
	{
		return a < x.a;
	}
};
int n, k;
vector<guard>a;
void clear()
{
	vi remove(n);
	int m = 0;
	F0R(i, n)
	{
		if (m >= a[i].b)remove[i] = 1;
		m = max(m, a[i].b);
	}
	vector<guard>t;
	F0R(i, n)if (remove[i] == 0)t.push_back(a[i]); else k--;
	a = t;
}
int main()
{
	setIO("lifeguards");
	cin >> n >> k;
	a.rsz(n);
	trav(x, a)cin >> x.a >> x.b;
	sort(all(a));
	clear();
	n = sz(a);
	if (k <= 0)
	{
		int ans = 0;
		int m = 0;
		F0R(i, n)
		{
			ans += a[i].b - max(m, a[i].a);
			assert(m < a[i].b);
			m = a[i].b;
		}
		return 0;
	}
	vi l(n);
	int i = 0, j = 0;
	for (; i < n; i++)
	{
		while (j<n && a[i].b>a[j].a)
		{
			j++;
		}
		l[i] = j - 1;
	}
	vector<vi>dp(n + 1, vi(k + 1, -inf));
	dp[n][0] = 0;
	vector<vi>ans(n + 1, vi(k + 1, -inf));
	ans[n][0] = 0;
	R0F(i, n)
	{
		F0R(j, k + 1)
		{
			if (i + j < n)
			{
				if (l[i] != i)
					dp[i][j] = dp[l[i]][max(0, j - (l[i] - i - 1))] + a[l[i]].a - a[i].a;
				else
					dp[i][j] = dp[i + 1][j] + a[i].b - a[i].a;
				dp[i][j] = max(dp[i][j], ans[l[i] + 1][max(0, j - (l[i] - i))] + a[i].b - a[i].a);
			}
			if (i + j <= n)
			{
				ans[i][j] = dp[i][j];
				ans[i][j] = max(ans[i][j], ans[i + 1][max(0, j - 1)]);
			}
		}
	}
	cout << ans[0][k] << endl;
}