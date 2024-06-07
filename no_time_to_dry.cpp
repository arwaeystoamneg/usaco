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
#define pr(a, b) trav(x,a)cerr << x << b; cerr << endl;
#define message cout << "Hello World" << endl;
//const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
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
class segment_tree
{
	struct item
	{
		vi sum;
	};
	item single(int i)
	{
		return { {i} };
	}
	item merge(item x, item y)
	{
		item ans;
		int i = 0, j = 0;
		while (i < sz(x.sum) || j < sz(y.sum))
		{
			if (j == sz(y.sum))ans.sum.pb(x.sum[i++]);
			else if (i == sz(x.sum))ans.sum.pb(y.sum[j++]);
			else
			{
				if (x.sum[i] < y.sum[j])
				{
					ans.sum.pb(x.sum[i++]);
				}
				else
				{
					ans.sum.pb(y.sum[j++]);
				}
			}
		}
		return ans;
	}
	vector<item> tree;
	vector<item>A;
	int height;
	item neutral = { };
public:void build(vi& B)
{
	int	n = B.size();
	height = log2(n + 1) + 1;
	A.rsz(n);
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
public:int query(int l, int r, int x)
{
	return query(0, 0, (1 << height) - 1, l, r, x);
}
	  int query(int v, int tl, int tr, int l, int r, int x)
	  {
		  if (r<tl || l>tr)return 0;
		  if (l <= tl && r >= tr)
		  {
			  return lower_bound(all(tree[v].sum), x) - tree[v].sum.begin();
		  }
		  int mid = (tl + tr) / 2;
		  return query(2 * v + 1, tl, mid, l, r, x) + query(2 * v + 2, mid + 1, tr, l, r, x);
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
int n, q;
vi a;
int main()
{
	setIO("");
	cin >> n >> q;
	a.rsz(n);
	trav(x, a)cin >> x, x--;
	vi last(n), t(n, -1);
	F0R(i, n)
	{
		last[i] = t[a[i]];
		t[a[i]] = i;
	}
	//pv(last);
	vi lastl(n);// last less than
	deque<pii>todo;
	F0R(i, n)
	{
		while (sz(todo) && todo.back().f >= a[i])todo.pop_back();
		if (sz(todo))lastl[i] = todo.back().s;
		else lastl[i] = -1;
		todo.pb({ a[i],i });
	}
	//pv(lastl);
	fill(all(t), inf);
	vi prefix(n + 1), add(n);// when last<lastl. always add as long as [l,r] contains i
	F0R(i, n)
	{
		if (last[i] < lastl[i])
		{
			add[i] = 1;
		}
		else
		{
			t[i] = last[i];
		}
	}
	F0R(i, n)prefix[i + 1] = prefix[i] + add[i];
	segment_tree x;
	x.build(t);
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = prefix[r + 1] - prefix[l];
		ans += x.query(l, r, l);//count the number of values in the range from l to r that are strictly less than l
		cout << ans << endl;
	}
}