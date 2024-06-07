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
		if (s != "test1")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
vll prefix_hash(string& a, vll& powers, ll mod)
{
	int n = sz(a);
	vll prefix(n + 1);
	F0R(i, n)prefix[i + 1] = (prefix[i] + powers[i] * (a[i] - 'a' + 1)) % mod;
	return prefix;
}
int n, m;
string a, b;
vector<vi>longest;
int base = 31;
vll powers, prefix;
int main()
{
	setIO("necklace");
	cin >> a >> b;
	n = sz(a);
	m = sz(b);
	powers.rsz(m + 10);
	powers[0] = 1;
	F0R(i, sz(powers) - 1)powers[i + 1] = (powers[i] * base) % inf;
	prefix = prefix_hash(b, powers, inf);
	longest.rsz(m, vi(26));
	F0R(i, m)
	{
		F0R(j, 26)
		{
			F0R(k, i + 1)
			{
				ll hash1 = prefix[i] - prefix[i - k];
				hash1 += (j + 1) * powers[i];
				hash1 %= inf;
				if (hash1 < 0)hash1 += inf;
				ll hash2 = prefix[k + 1];
				hash2 *= powers[i - k];
				hash2 %= inf;
				if (hash2 < 0)hash2 += inf;
				if (hash1 == hash2)longest[i][j] = k + 1;
			}
		}
	}
	vector<vi>dp(n + 1, vi(m + 1, inf));
	F0R(i, m)dp[n][i] = 0;
	R0F(i, n)
	{
		F0R(j, m)
		{
			dp[i][j] = min(dp[i + 1][j] + 1, dp[i + 1][longest[j][a[i] - 'a']]);
		}
	}
	cout << dp[0][0] << endl;
}