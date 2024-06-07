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
		if (s != "test3")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
const int MAX = 1e5 + 10;//1e5+5
// remember that this is 1-indexed. D:. Requires knowledge of updates beforehand. REMEMBER THAT YOU MUST PUT THE UPDATES FIRST THEN INIT().
template<class T, int SZ> struct OffBIT2D {// IF THIS IS NOT ALLOWED PLEASE LET ME KNOW. 
										   //SOURCE : https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/2D%20Range%20Queries%20(15.2)/BIT2DOff%20(15.2).h
										   // THANK YOU BENQ
	bool mode = 0; // mode = 1 -> initialized
	vpi todo; // locations of updates to process
	int cnt[SZ], st[SZ];
	vi val; vector<T> bit; // store all BITs in single vector
	void init() {
		assert(!mode); mode = 1;
		int lst[SZ]; F0R(i, SZ) lst[i] = cnt[i] = 0;
		sort(all(todo), [](const pii& a, const pii& b) {
			return a.s < b.s; });
		trav(t, todo) for (int x = t.f; x < SZ; x += x & -x)
			if (lst[x] != t.s) lst[x] = t.s, cnt[x] ++;
		int sum = 0; F0R(i, SZ) lst[i] = 0, st[i] = (sum += cnt[i]);
		val.rsz(sum); bit.rsz(sum); reverse(all(todo));
		trav(t, todo) for (int x = t.f; x < SZ; x += x & -x)
			if (lst[x] != t.s) lst[x] = t.s, val[--st[x]] = t.s;
	}
	int rank(int y, int l, int r) {
		return upper_bound(begin(val) + l, begin(val) + r, y) - begin(val) - l;
	}
	void UPD(int x, int y, T t) {
		for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)
			bit[st[x] + y - 1] += t;
	}
	void upd(int x, int y, T t) {
		if (!mode) todo.pb({ x,y });
		else for (; x < SZ; x += x & -x) UPD(x, y, t);
	}
	int QUERY(int x, int y) {
		T res = 0;
		for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y) res += bit[st[x] + y - 1];
		return res;
	}
	T query(int x, int y) {
		assert(mode);
		T res = 0; for (; x; x -= x & -x) res += QUERY(x, y);
		return res;
	}
	T query(int xl, int xr, int yl, int yr) {
		return query(xr, yr) - query(xl - 1, yr)
			- query(xr, yl - 1) + query(xl - 1, yl - 1);
	}
};
int n, T;
struct update// vertical
{
	int x, l, r, t;
};
struct query// horizontal
{
	int y, l, r, t;
};
vpi c;
int main()
{
	setIO("mowing");
	cin >> n >> T;
	vector<update>a;
	vector<query>b;
	c.rsz(n);
	trav(x, c)cin >> x.f >> x.s, x.s += 3;
	//coord compress vertical
	vi t;
	trav(x, c)t.push_back(x.f);
	sort(all(t));
	trav(x, c)x.f = lower_bound(all(t), x.f) - t.begin() + 3;
	F0R(i, n - 1)
	{
		if (c[i].f == c[i + 1].f)
		{
			a.push_back({ c[i].f,min(c[i].s,c[i + 1].s),max(c[i].s,c[i + 1].s),i });
		}
		else
		{
			b.push_back({ c[i].s,min(c[i].f,c[i + 1].f),max(c[i].f,c[i + 1].f),i });
		}
	}
	OffBIT2D<int, MAX>sum;
	trav(x, a)sum.upd(x.x, x.l + 1, 1), sum.upd(x.x, x.r, 1);
	sum.init();
	F0R(i, sz(a))sum.upd(a[i].x, a[i].l + 1, 1), sum.upd(a[i].x, a[i].r, -1);
	int j = 0, k = 0;
	ll ans = 0;
	F0R(i, sz(b))
	{
		while (j < sz(a) && b[i].t - a[j].t >= T)
		{
			sum.upd(a[j].x, a[j].l + 1, 1);
			sum.upd(a[j].x, a[j].r, -1);
			j++;
		}
		while (k < sz(a) && a[k].t - b[i].t < T)
		{
			sum.upd(a[k].x, a[k].l + 1, -1);
			sum.upd(a[k].x, a[k].r, 1);
			k++;
		}
		ans += sum.query(b[i].l + 1, b[i].r - 1, 1, b[i].y);
	}
	cout << ans << endl;
}