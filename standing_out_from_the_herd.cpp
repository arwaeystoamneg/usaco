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
int n;
vector<string>a;
int base = 31;
vll power, prefix;
vll prefix_hash(string& a, vll& powers, ll mod)
{
	int n = sz(a);
	vll prefix(n + 1);
	F0R(i, n)prefix[i + 1] = (prefix[i] + powers[i] * (a[i] - '1' + 1)) % mod;
	return prefix;
}
string total;
int lcp(int i, int j)
{
	// binary search over the length of the LCP
	int l = 0, r = sz(total) - 1;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		ll hash1 = prefix[i + m] - prefix[i], hash2 = prefix[j + m] - prefix[j];
		hash1 *= power[j], hash2 *= power[i];
		hash1 %= inf;
		hash2 %= inf;
		if (hash1 < 0)hash1 += inf;
		if (hash2 < 0)hash2 += inf;
		if (hash1 == hash2)
			l = m;
		else
			r = m - 1;
	}
	return l;
}
int main()
{
	setIO("standingout");
	cin >> n;
	a.rsz(n);
	F0R(i, n)cin >> a[i];
	total = "";
	F0R(i, n)
	{
		total += a[i];
		total += '`';
	}
	int m = sz(total);
	total += '`';
	total += total;
	power.rsz(2 * m + 10);
	power[0] = 1;
	F0R(i, sz(power) - 1)
	{
		power[i + 1] = (power[i] * base) % inf;
	}
	prefix = prefix_hash(total, power, inf);
	vi suffix_array(m); iota(all(suffix_array), 0);
	sort(all(suffix_array), [](int i, int j) {
		int l = lcp(i, j);
		return total[i + l] < total[j + l];
		});
	vll ans(n);
	int i = 0, len = 0;
	vpi index(m);
	F0R(j, m)
	{
		if (total[j] == '`')i++, len = 0, index[j] = { -inf,-inf };
		else
		{
			index[j] = { i,len++ };
		}
	}
	vi l(m), r(m);
	len = 1;
	l[0] = -1, len++;
	FOR(i, 1, m)
	{
		if (index[suffix_array[i]].f == index[suffix_array[i - 1]].f)
		{
			len++;
		}
		else len = 1;
		l[i] = i - len;
	}
	len = 1;
	r[m - 1] = m;
	R0F(i, m - 1)
	{
		if (index[suffix_array[i]].f == index[suffix_array[i + 1]].f)
			len++;
		else len = 1;
		r[i] = i + len;
	}
	F0R(i, sz(suffix_array))
	{
		if (total[suffix_array[i]] == '`')continue;
		int LCP = -inf;
		if (l[i] >= 0)
		{
			LCP = lcp(suffix_array[l[i]], suffix_array[i]);
		}
		if (r[i] < m)
		{
			LCP = max(LCP, lcp(suffix_array[r[i]], suffix_array[i]));
		}
		assert(LCP + inf);
		int next = suffix_array[i] + LCP;
		if (next >= sz(index) || index[next].f != index[suffix_array[i]].f);
		//ans[index[suffix_array[i]].f] += sz(a[index[suffix_array[i]].f]) - index[suffix_array[i]].s - LCP;
		else
		{
			ans[index[suffix_array[i]].f] += sz(a[index[suffix_array[i]].f]) - index[suffix_array[i]].s - LCP;
		}
		if (i && index[suffix_array[i - 1]].f == index[suffix_array[i]].f)
		{
			int t = lcp(suffix_array[i - 1], suffix_array[i]);
			if (t > LCP)
				ans[index[suffix_array[i]].f] -= t - LCP;
		}
	}
	trav(x, ans)cout << x << endl;
}