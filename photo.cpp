// EXPLOSION!
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
//#define ednl '\n'
#define test int testc;cin>>testc;while(testc--)
#define pr(a, b) trav(x,a)cerr << x << b; cerr << endl;
#define message cout << "Hello World" << endl;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353    

void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, sz(a)) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, sz(a)) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//#ifdef arwaeystoamneg
	if (sz(s))
	{
		freopen((s + ".in").c_str(), "r", stdin);
		if (s != "test1")
			freopen((s + ".out").c_str(), "w", stdout);
	}
	//#endif
}
template<class T>class segment_tree
{
	struct item
	{
		T sum;
	};
	item single(T i)
	{
		return { i };
	}
	item merge(item x, item y)
	{
		item ans;
		ans.sum = max(x.sum, y.sum);
		return ans;
	}
	vector<item> tree;
	vector<item>A;
	int height;
	item neutral = { -inf };
public:void build(vector<T>& B)
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
public:T query(int l, int r)
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
public:void update(int pos, T val)
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
public:int get(int k)
{
	return get(0, 0, (1 << height) - 1, k);
}
	  int get(int v, int tl, int tr, int k)
	  {
		  if (tl == tr)return tl;
		  int mid = (tl + tr) / 2;
		  if (k > tree[2 * v + 1].sum)
			  return get(2 * v + 2, mid + 1, tr, k - tree[2 * v + 1].sum);
		  return get(2 * v + 1, tl, mid, k);
	  }
};


const int MAX = 100006;
int n, m, l[2 * MAX], r[2 * MAX], dp[2 * MAX];
pii a[MAX];
int main()
{
	setIO("photo");
	cin >> n >> m;
	F0R(i, m)cin >> a[i].f >> a[i].s, a[i].f--, a[i].s--;


	// do l
	sort(a, a + m);
	int p = 0, best = -inf;
	F0R(i, n)
	{
		while (p < m && a[p].f <= i)best = max(best, a[p].s), p++;
		l[i] = max(best, i) + 1;
	}
	assert(p == m);
	best = n;
	p = m - 1;


	// do r
	R0F(i, n)
	{
		while (p >= 0 && a[p].f > i)best = min(best, a[p].s), p--;
		r[i] = best;
	}


	p = inf;
	F0R(i, m)p = min(p, a[i].s);
	vi t(n + 1);
	t[n] = 0;
	dp[n] = 0;
	F0R(i, n)t[i] = dp[i] = -inf;
	segment_tree<int>st;
	st.build(t);
	R0F(i, n)
	{
		dp[i] = 1 + st.query(l[i], r[i]);
		st.update(i, dp[i]);
	}
	int ans = st.query(0, p);
	cout << (ans < 0 ? -1 : ans) << endl;
}



