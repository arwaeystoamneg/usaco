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
struct point
{
	int x, sz;
	bool operator<(const point& a)const
	{
		return sz > a.sz;
	}
};
int n;
vector<point>a;
unordered_map<int, int>sz;
bool check(int i, int j)
{
	return sz[i] >= j - i && sz[j] >= j - i;
}
int main()
{
	setIO("trapped");
	cin >> n;
	a.rsz(n);
	trav(x, a)cin >> x.sz >> x.x;
	sort(all(a));
	trav(x, a)sz.insert({ x.x, x.sz });
	set<int>hay;
	unordered_map<int, int>c;// is the region to the right blocked?
	int ans = 0;
	trav(x, a)
	{
		hay.insert(x.x);
		auto it = hay.lower_bound(x.x);
		auto next = it; next++;
		if (it != hay.begin() && next != hay.end())
		{
			auto back = it;
			back--;
			if (!c[*back])
			{
				if (check(*back, *it))ans += *it - *back, c[*back] = 1;
				else c[*back] = 0;
				if (check(*it, *next))ans += *next - *it, c[*it] = 1;
				else c[*it] = 0;
			}
			else c[*it] = 1;
		}
		if (it == hay.begin() && next != hay.end())
			if (check(*it, *next))ans += *next - *it, c[*it] = 1;
		if (it != hay.begin() && next == hay.end())
		{
			auto back = it;
			back--;
			if (check(*back, *it))ans += *it - *back, c[*back] = 1;
		}
	}
	cout << ans << endl;
}