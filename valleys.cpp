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
//#define endl '\n'
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
int n;
vector<vi>a;
struct pt
{
	int x, y, h;
	bool operator<(const pt& a)const
	{
		return h < a.h;
	}
};
bool check(int i, int j)
{
	return i >= 0 && j >= 0 && i < n&& j < n;
}
vi link;
int find(int i)
{
	return link[i] == i ? i : link[i] = find(link[i]);
}
int main()
{
	setIO("valleys");
	cin >> n;
	a.rsz(n, vi(n));
	F0R(i, n)F0R(j, n)cin >> a[i][j];
	vector<pt>t;
	F0R(i, n)F0R(j, n)t.push_back({ i,j,a[i][j] });
	sort(all(t));
	reverse(all(t));
	int cur = 1;
	vi count = { cur };
	link.rsz(n * n + 1); iota(all(link), 0);
	vi size(n * n + 1, 1);
	trav(x, t)
	{
		cur++;
		FOR(i, -1, 2)
		{
			FOR(j, -1, 2)
			{
				if (i || j)
				{
					if (!check(x.x + i, x.y + j))
					{
						if (find(n * x.x + x.y) != n * n)cur--, link[find(n * x.x + x.y)] = n * n;
					}
					else if (x.h < a[x.x + i][x.y + j])
					{
						int b = find(n * x.x + x.y), c = find(n * (x.x + i) + x.y + j);
						if (b == c)continue;
						if (b > c)swap(b, c);
						cur--;
						size[c] += size[b];
						link[b] = c;
					}
				}
			}
		}
		count.push_back(cur);
	}
	reverse(all(t)); reverse(all(count));
	iota(all(link), 0);
	fill(all(size), 1);
	vi hole(n * n);
	ll ans = 0;
	F0R(i, sz(t))
	{
		pt x = t[i];
		F0R(k, 4)
		{
			int i = x.x + dx[k], j = x.y + dy[k];
			if (check(i, j))
			{
				if (a[i][j] > x.h)continue;
				int b = find(n * x.x + x.y), c = find(n * i + j);
				if (b == c)continue;
				if (size[b] > size[c])swap(b, c);
				link[b] = c;
				size[c] += size[b];
				hole[c] += hole[b];
			}
		}
		hole[find(n * x.x + x.y)] += count[i + 1] - count[i];
		if (hole[find(n * x.x + x.y)] == 0)ans += size[find(n * x.x + x.y)];
	}
	cout << ans << endl;
}