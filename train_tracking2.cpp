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
int n, k;
vi a;
ll ans = 1;
void solve(int n, int val)
{
	if (n == 0)return;
	val = 1e9 - val;
	vll dp(n + 2);// dp[i] is the number of ways to place val at the i th place.
	dp[0] = 1;
	vll powers(min(k + 1, n + 2));
	powers[0] = 1;
	F0R(i, min(k, n + 1))powers[i + 1] = (powers[i] * val) % inf;
	dp[1] = 1;
	FOR(i, 2, min(k + 1, n + 2))
	{
		dp[i] = ((val + 1) * dp[i - 1]) % inf;
	}
	FOR(i, k + 1, n + 2)
	{
		dp[i] = (val + 1) * dp[i - 1] - powers[k] * dp[i - k - 1];
		dp[i] %= inf;
		if (dp[i] < 0)dp[i] += inf;
	}
	ans *= dp[n + 1];
	ans %= inf;
}
int main()
{
	setIO("tracking2");
	cin >> n >> k;
	a.rsz(n - k + 1);
	trav(x, a)cin >> x;
	multiset<int, greater<int>>t;
	vi least(n);// a lower bound on the value in the index
	F0R(i, n)
	{
		if (i < sz(a))
			t.insert(a[i]);
		least[i] = *t.begin();
		if (i >= k - 1)
			t.erase(t.find(a[i - k + 1]));
	}
	//pv(least);
	vi b(n, -1);
	F0R(i, sz(a) - 1)
	{
		if (a[i] < a[i + 1])
		{
			b[i] = a[i];
		}
		if (a[i + 1] < a[i])
		{
			b[i + k] = a[i + 1];
		}
	}
	int i = 0, j;
	for (; i < n && b[i] == -1; i++);
	solve(i, least[0]);
	j = i + 1;
	for (; j < n && b[j] == -1; j++);
	while (j < n)
	{
		solve(j - i - 1, least[i + 1]);
		i = j++;
		for (; j < n && b[j] == -1; j++);
	}
	solve(n - i - 1, least[n - 1]);
	cout << ans << endl;
}