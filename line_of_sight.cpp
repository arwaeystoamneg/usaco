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
class segment_tree
{
	struct item
	{
		int sum;
	};
	item single(int i)
	{
		return { i };
	}
	item merge(item x, item y)
	{
		item ans;
		ans.sum = x.sum + y.sum;
		return ans;
	}
	vector<item> tree;
	int height;
	item neutral = { 0 };
public:void build(vi& B)
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
public:int query(int l, int r)
{
	return query(0, 0, (1 << height) - 1, l, r).sum;
}
	  item query(int v, int tl, int tr, int l, int r)
	  {
		  if (r<tl || l>tr)return neutral;
		  if (l <= tl && r >= tr)
		  {
			  return tree[v];
		  }
		  int mid = (tl + tr) / 2;
		  return merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid + 1, tr, l, r));
	  }
	  //assign
public:void update(int pos, int val)
{
	update(0, 0, (1 << height) - 1, pos, single(val));
}
	  void update(int v, int tl, int tr, int pos, item val)
	  {
		  if (tl == tr)
		  {
			  tree[v] = merge(tree[v], val);
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
int n, r;
vpi a;
vector<pair<db, db>>range;
db pi = acos(-1);
db get(int x, int y)
{
	if (x > 0)
	{
		if (y > 0)
		{
			return atan(y / (db)x);
		}
		else
		{
			return 2 * pi - atan(-y / (db)x);
		}
	}
	else
	{
		if (y > 0)
		{
			return pi - atan(y / (db)-x);
		}
		else
		{
			return pi + atan(-y / (db)-x);
		}
	}
}
int main()
{
	setIO("sight");
	db eps = 1e-7;
	cin >> n >> r;
	a.rsz(n);
	F0R(i, n)cin >> a[i].f >> a[i].s;
	ll count = 0;
	F0R(i, n)// point -> tangents. If the point crosses 0, split into two sections.
	{
		if (a[i].f >= r)
		{
			count++;
			db theta = acos((db)r / sqrt((ll)a[i].f * a[i].f + (ll)a[i].s * a[i].s));
			db alpha = get(a[i].f, a[i].s);
			if (a[i].s > 0)
			{
				range.push_back({ 0 - eps,alpha + theta });
				range.push_back({ 2 * pi + alpha - theta,2 * pi + eps });
			}
			else
			{
				range.push_back({ 0 - eps,alpha + theta - 2 * pi });
				range.push_back({ alpha - theta,2 * pi + eps });
			}
		}
		else
		{
			db theta = acos((db)r / sqrt((ll)a[i].f * a[i].f + (ll)a[i].s * a[i].s));
			db alpha = get(a[i].f, a[i].s);
			range.push_back({ alpha - theta,alpha + theta });
		}
	}
	// coordinate compress so that I can use segment tree
	vector<db> order;
	trav(x, range)order.push_back(x.f), order.pb(x.s);
	sort(all(order));
	vpi ranges;// this is ints;
	trav(x, range)ranges.push_back({ lower_bound(all(order),x.f) - order.begin(),lower_bound(all(order),x.s) - order.begin() });
	sort(all(ranges));
	// sweep from left to right. update .s with 1. query < .s
	// the segments intersect iff a[i].s > a[j].f
	int index = lower_bound(all(order), 2 * pi + eps) - order.begin(), index1 = lower_bound(all(order), -eps) - order.begin();
	ll ans = 0;
	int MAX = 2e5 + 5;
	segment_tree sum, sum1;
	vi t(MAX);
	sum.build(t); sum1.build(t);
	trav(x, ranges)
	{
		if (x.s == index)
		{
			ans += sum1.query(x.f, MAX);
			sum.update(x.s, 1);
		}
		else
		{
			if (x.f == index1)
			{
				ans += sum1.query(x.f, MAX);
				sum.update(x.s, 1);
			}
			else
			{
				ans += sum.query(x.f, MAX);
				sum.update(x.s, 1);
				sum1.update(x.s, 1);
			}
		}
	}
	cout << ans + (count - 1) * count / 2 << endl;
}