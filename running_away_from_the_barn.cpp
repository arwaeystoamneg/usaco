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
		if (s != "test2")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
class segment_tree
{
	struct item
	{
		vll a;
	};
	item single(ll i)
	{
		return { {i} };
	}
	item merge(item& x, item& y)
	{
		item ans;
		int i = 0, j = 0;
		while (i < sz(x.a) || j < sz(y.a))
		{
			if (i == sz(x.a))
			{
				ans.a.push_back(y.a[j++]);
			}
			else if (j == sz(y.a))
			{
				ans.a.push_back(x.a[i++]);
			}
			else
			{
				if (x.a[i] < y.a[j])ans.a.pb(x.a[i++]);
				else ans.a.pb(y.a[j++]);
			}
		}
		return ans;
	}
	vector<item> tree;
	int height;
	item neutral = { {} };
public:void build(vll& B)
{
	int	n = B.size();
	height = log2(n + 1) + 1;
	vector<item>A(n);
	tree.rsz((1 << height + 1) - 1);
	F0R(i, n)A[i] = single(B[i]);
	A.rsz(1 << height, neutral);
	build(A, 0, 0, (1 << height) - 1);
}
	  void build(vector<item>& A, int v, int tl, int tr)
	  {
		  if (tl == tr)
			  tree[v] = A[tl];
		  else
		  {
			  int mid = (tl + tr) / 2;
			  build(A, 2 * v + 1, tl, mid);
			  build(A, 2 * v + 2, mid + 1, tr);
			  tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		  }
	  }
public:ll query(int l, int r, ll val)
{
	return query(0, 0, (1 << height) - 1, l, r, val);
}
	  ll query(int v, int tl, int tr, int l, int r, ll val)
	  {
		  if (r<tl || l>tr)return 0;
		  if (l <= tl && r >= tr)
		  {
			  return upper_bound(all(tree[v].a), val) - tree[v].a.begin();
		  }
		  int mid = (tl + tr) / 2;
		  return query(2 * v + 1, tl, mid, l, r, val) + query(2 * v + 2, mid + 1, tr, l, r, val);
	  }
	  //assign
public:void update(int pos, ll val)
{
	update(0, 0, (1 << height) - 1, pos, single(val));
}
	  void update(int v, int tl, int tr, int pos, item val)
	  {
		  if (tl == tr)
		  {
			  tree[v] = val;
		  }
		  else
		  {
			  int mid = (tl + tr) / 2;
			  if (pos <= mid)
				  update(2 * v + 1, tl, mid, pos, val);
			  else
				  update(2 * v + 2, mid + 1, tr, pos, val);
			  tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		  }
	  }
};
int n;
ll l;
vector<vpll>adj;
vll depth;
vi order, sizes;
void dfs(int i, int p)
{
	order.push_back(i);
	sizes[i] = 1;
	trav(x, adj[i])
	{
		if (x.f != p)
		{
			depth[x.f] = depth[i] + x.s;
			dfs(x.f, i);
			sizes[i] += sizes[x.f];
		}
	}
}
int main()
{
	setIO("runaway");
	cin >> n >> l;
	adj.rsz(n);
	F0R(i, n - 1)
	{
		int x; ll y;
		cin >> x >> y;
		adj[i + 1].push_back({ x - 1,y });
		adj[x - 1].push_back({ i + 1,y });
	}
	depth.rsz(n);
	sizes.rsz(n);
	dfs(0, -1);
	vi index_(n);
	F0R(i, n)index_[order[i]] = i;
	segment_tree ans;
	vll t(n);
	F0R(i, n)t[index_[i]] = depth[i];
	ans.build(t);
	F0R(i, n)
	{
		cout << ans.query(index_[i], sizes[i] + index_[i] - 1, l + depth[i]) << endl;
	}
}