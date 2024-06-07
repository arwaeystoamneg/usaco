/*
ID: awesome35
LANG: C++14
TASK: ditch
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
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
#define test int t;cin>>t;while(t--)
#define pq priority_queue
const ll linf = 4000000000000000000LL;
const int inf = 1000000007;//998244353
const ld pi = 3.1415926535;


ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
ll minimum(ll x, ll y)
{
	if (x < y)
		return x;
	return y;
}
void pv(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<ld>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void pv(vector<pair<ll, ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void pv(vector<vector<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<vi>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void pv(vector<vector<vector<ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
		cout << endl;
	}
	cout << endl;
}
void ps(set<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void ps(set<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << i->f << " " << i->s << endl;
	cout << endl;
}
void pv(vector<set<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		ps(*i);
		cout << endl;
	}
	cout << endl;
}
void ps(set<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pm(map<int, vector<int>> m)
{
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void pm(map<char, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t' << i->second << endl;
	}
}
void pm(map<pii, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first.f << " " << i->first.s << " " << i->second << endl;
	}
}
bool comp(pii x, pii y)
{
	if (x.s == y.s)return x.f < y.f;
	return x.s < y.s;
}
/*
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is indexs while .f is weight
		pii temp = todo.top();
		int indexs = temp.second;
		todo.pop();
		if (finalized[indexs])continue;
		finalized[indexs] = 1;
		trav(x, adjacency[indexs])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[indexs])
			{
				dist[x.first] = x.second + dist[indexs];
				parents[x.f] = indexs;
				todo.push(mp(-dist[x.first], x.f));
			}
		}
	}
}
void build_primes()
{
	primes.reserve(50000);
	vi visited;
	visited.rsz(200000, 0);
	FOR(i, 2, 200000)
	{
		if (visited[i] == 0)
		{
			primes.pb(i);
			a = i;
			while (a < 200000)
			{
				visited[a] = 1;
				a += i;
			}
		}
	}
}
//Prim's Algorithm
// need vector<vpi>adjacency
ll prim()
{
	ll a = 0;
	vi visited;
	visited.rsz(n, 0);
	visited[0] = 1;
	pq<pii>todo;
	trav(x, adjacency[0])
		todo.push({ -x.s,x.f });
	F0R(i, n - 1)
	{
		pii temp = todo.top();
		todo.pop();
		int indexs = temp.s;
		if (visited[indexs])cont;
		a -= temp.f;
		visited[indexs] = 1;
		trav(x, adjacency[indexs])
			if (visited[x.f] == 0)
			{
				todo.push({ -x.s,x.f });
			}
	}
	return a;
}
vector<vector<ll>> matrix_mult(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
	int n = a.size();
	vector<vector<ll>> answer;
	answer.resize(n);
	for (int i = 0; i < n; i++) answer[i].resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) // calculate answer[i][j]
		{
			for (int k = 0; k < n; k++)
				answer[i][j] = (answer[i][j] + a[i][k] * b[k][j]) % inf;
		}
	}
	return answer;
}
vector<vector<ll>> matrix_exp(vector<vector<ll>>& a, ll n)
{
	vector<vector<ll>> result;
	result.resize(a.size());

	for (int i = 0; i < a.size(); i++)
	{
		result[i].resize(a[0].size(), 0);
		result[i][i] = 1;
	}
	while (n != 0)
	{
		if (n & 1)
			result = matrix_mult(result, a);
		a = matrix_mult(a, a);
		n = n >> 1;
	}
	return result;
}
// Union-Find
int find(int a) // return the root for node a
{
	if (a == links[a])
		return a;
	return links[a] = find(links[a]);
}
bool same(int a, int b) // check if node a and b has the same root
{
	return find(a) == find(b);
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (sizes[a] < sizes[b]) swap(a, b);
	sizes[a] += sizes[b]; //a always bigger than b, move subtree b under a
	links[b] = a;
}
*/
int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient 
		int q = a / m;
		int t = m;

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t;
		t = y;

		// Update y and x 
		y = x - q * y;
		x = t;
	}

	// Make x positive 
	if (x < 0)
		x += m0;

	return x;
}
ll power(ll x, ll y)
{
	ll k = 1 << 30;
	ll z = 1;
	while (k != 0)
	{
		z *= z;
		z %= inf;
		if (y >= k)
		{
			z *= x;
			z %= inf;
			y -= k;
		}
		k >>= 1;
	}
	return z;
}
// remember that you need to take abs
long double area(pii x, pii y, pii z)
{
	return ((ll)x.s * y.f + (ll)y.s * z.f + (ll)z.s * x.f - (ll)x.f * y.s - (ll)y.f * z.s - (ll)z.f * x.s) / 2.0;
}
bool clockwise(pii x, pii y, pii z)
{
	return area(x, y, z) > 0;
}
struct point
{
	ld x, y;
};
long double area(point x, point y, point z)
{
	return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y - z.x * x.y) / 2.0;
}
bool clockwise(point x, point y, point z)
{
	return area(x, y, z) > 0;
}
int gcd(int a, int b)
{
	if (a > b)swap(a, b);
	if (a == 0)return b;
	return gcd(a, b % a);
}
int popcount(int a)
{
	int count = 0;
	while (a != 0)
	{
		count += (a % 2);
		a >>= 1;
	}
	return count;
}
class segment_tree
{/*
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
	vector<item>A;*/
	vector<int>tree;
	vector<int>A;
	int height;
	//item neutral = { 0 };
	int neutral = 0;
public:void build(int n)
{
	height = log2(n - 1) + 1;
	A.rsz(1 << height, neutral);
	tree.rsz((1 << height + 1) - 1);
}
public:void build(vi& B)
{
	int	n = B.size();
	height = log2(n - 1) + 1;
	A.rsz(n);
	tree.rsz((1 << height + 1) - 1);
	F0R(i, n)A[i] = B[i];
	A.rsz(1 << height, neutral);
	build(A, 0, 0, (1 << height) - 1);
}
	   void build(vector<int>& A, int v, int tl, int tr)
	   {
		   if (tl == tr)
			   tree[v] = A[tl];
		   else
		   {
			   int mid = (tl + tr) / 2;
			   build(A, 2 * v + 1, tl, mid);
			   build(A, 2 * v + 2, mid + 1, tr);
			   tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
		   }
	   }
public:int query(int l, int r)
{
	return query(0, 0, (1 << height) - 1, l, r);
}
	   int query(int v, int tl, int tr, int l, int r)
	   {
		   if (r<tl || l>tr)return neutral;
		   if (l <= tl && r >= tr)
		   {
			   return tree[v];
		   }
		   int mid = (tl + tr) / 2;
		   return query(2 * v + 1, tl, mid, l, r) + query(2 * v + 2, mid + 1, tr, l, r);
	   }
public:void update(int pos, int val)
{
	update(0, 0, (1 << height) - 1, pos, val);
}
	   void update(int v, int tl, int tr, int pos, int val)
	   {
		   if (tl == tr)
		   {
			   tree[v] = val + tree[v];
		   }
		   else
		   {
			   int mid = (tl + tr) / 2;
			   if (pos <= mid)
				   update(2 * v + 1, tl, mid, pos, val);
			   else
				   update(2 * v + 2, mid + 1, tr, pos, val);
			   tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
		   }
	   }
public:int get(int val)
{
	return get(0, /*0, (1 << height) - 1,*/ val) - (1 << height) + 1;
}
	   int get(int i,/* int tl, int tr,*/ int val)
	   {
		   if (/*tl == tr*/(i << 1) + 1 >= tree.size())
		   {
			   //if (tree[i].sum >= val)return -1;
			   return i;
		   }
		   //int mid = (tl + tr) / 2;
		   if (tree[(i << 1) + 1] > val)
		   {
			   return get((i << 1) + 1,/* tl, mid,*/ val);
		   }
		   return get((i << 1) + 2, /*mid + 1, tr,*/ val - tree[(i << 1) + 1]);
	   }
};
//end of preprogrammed methods
ll a, b, c;
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int n;
vpi A;
vector<vi>B;
void init()
{
	setIO("balancing");
	cin >> n;
	A.rsz(n);
	F0R(i, n)cin >> A[i].f >> A[i].s;
	//clock_t x = clock();
	sort(all(A));
	//set<int>temp;
	//trav(x, A)temp.insert(x.s);
	vi temp;
	trav(x, A)temp.pb(x.s);
	sort(all(temp));
	a = 1;
	unordered_map<int, int>index;
	trav(x, temp)index.insert({ x,a++ });
	trav(x, A)x.s = index[x.s];
	//clock_t y = clock();
	temp.rsz(0);
	trav(x, A)temp.pb(x.f);
	sort(all(temp));
	a = 1;
	index.clear();
	trav(x, temp)index.insert({ x,a++ });
	trav(x, A)x.f = index[x.f];
	B.reserve(n);
	F0R(i, n)
	{
		int j = i;
		vi t;
		for (; j < n; j++)
		{
			if (A[i].f != A[j].f)
			{
				i = j - 1;
				break;
			}
			t.pb(A[j].s);
		}
		if (j == n)
		{
			B.pb(t);
			break;
		}
		B.pb(t);
	}
	//clock_t z = clock();
	//cout << z - y << endl << y - x << endl;
}
segment_tree lefts, rights;
bool ok(int m)
{
	int index = min(lefts.get(m), rights.get(m));
	int val1 = lefts.query(index, n);
	int val2 = rights.query(index, n);
	if (val1 <= m && val2 <= m)return 1;
	return 0;
}
int main()
{
	init();

	vi t(n + 1);
	trav(x, B)trav(y, x)t[y]++;
	rights.build(t);
	lefts.build(n);
	int ans = inf;
	trav(x, B)
	{
		trav(y, x) { lefts.update(y, 1); }
		trav(y, x) { rights.update(y, -1); }
		int low = 0, high = n;
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (ok(mid))
				high = mid;
			else
				low = mid + 1;
		}
		ans = min(ans, high);
	}
	cout << ans << endl;
}