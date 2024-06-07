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
#define vin(v,n) vi (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vlln(v,n) vector<ll> (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vvin(v,n,m) vector<vi>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define vvlln(v,n,m) vector<vector<ll>>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pq priority_queue
const ll linf = 4000000000000000000LL;
const int inf = 1000000007;
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
void pv(vector<double>amount)
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
void pv(vector<bool>amount)
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
void pv(vector<pair<pii, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s << endl;
	cout << endl;
}
void pv(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void pv(vector<vector<string>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		pv(*i);
		cout << endl;
	}
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
void pv(vector<vector<pair<ll, ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
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
void pv(vector<vector<bool>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
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
void pv(vector<vector<pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		pv(*i);
	}
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
void pm(map<string, vector<string>> m)
{
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<string, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s << endl;
	}
}
void pm(map<string, vector<bool>> m)
{
	for (map<string, vector<bool>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		pv(i->second);
	}
}
void pm(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		ps(i->second);
	}
}
void pm(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void pm(map<char, vector<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t';
		pv(i->second);
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
//end of preprogrammed methods
ll a, b, c;
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);
}
int n, q;
vector<point>points;
vector<point> hull;
point p;
bool __convex_sort(point x, point y)
{
	long double a = area(p, x, y);
	if (abs(a) <= 1e-8)
	{
		if (x.x == y.x)return x.y < y.y;
		return x.x < y.x;
	}
	return a < 0;
}
void convex_hull()
{
	int index = 0;
	p = points[0];
	FOR(i, 1, n)
	{
		if ((p.y == points[i].y && p.x > points[i].x) || p.y > points[i].y)
		{
			p = points[i];
			index = i;
		}
	}
	//cout << __convex_sort(points[2], points[3]) << endl;
	points.erase(index + points.begin());
	sort(all(points), __convex_sort);
	//trav(x, points)cout << x.x << " " << x.y << endl;
	hull.pb(p);
	hull.pb(points[0]);
	hull.pb(points[1]);
	FOR(i, 2, n - 1)
	{
		while (clockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
		{
			hull.pop_back();
		}
		hull.pb(points[i]);
	}
	points.pb(p);
}
int sqrt_q;
void init()
{
	setIO("fencing");
	cin >> n >> q;
	points.rsz(n);
	F0R(i, n)
	{
		cin >> a >> b;
		points[i].x = a;
		points[i].y = b;
	}
	sqrt_q = 35 * sqrt(q);
}
vector<point> todo;
void update()
{
	n += todo.size();
	trav(x, todo)points.pb(x);
	todo.rsz(0);
	hull.rsz(0);
	convex_hull();
}
long long dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

long long cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

int above_line(point p, point norm, long long c)
{
	if ((dot(norm, p) - c) > 0)
		return 1;
	else if ((dot(norm, p) - c) == 0)
		return 0;
	else
		return -1;
}

bool isUp(point norm, point a, point b)
{
	return dot(norm, { b.x - a.x, b.y - a.y }) > 0;
}

bool isDown(point norm, point a, point b)
{
	return dot(norm, { b.x - a.x, b.y - a.y }) < 0;
}


int find_polyMax(vector<point>& poly, point norm)
{
	int np = poly.size();
	int lo = 0;
	int hi = np - 1;

	//bruteforce to find extreme point
	long long minDot = inf, maxDot = -inf;
	int minPos = 0, maxPos = 0;


	//check if lo is local max
	if (!isUp(norm, poly[0], poly[1]) && !isUp(norm, poly[0], poly[np - 1]))
		return 0;

	//binary search to find the min and max position
	while (lo < hi - 1)
	{
		int mid = (lo + hi) / 2;
		// A, B, C refers to lo, hi, and mid
		bool isUpA = isUp(norm, poly[lo], poly[lo + 1]);
		bool isUpC = isUp(norm, poly[mid], poly[mid + 1]);
		bool isUpAC = isUp(norm, poly[lo], poly[mid]);
		bool isDownA = isDown(norm, poly[lo], poly[lo + 1]);
		bool isDownC = isDown(norm, poly[mid], poly[mid + 1]);
		bool isDownAC = isDown(norm, poly[lo], poly[mid]);

		if (!isUpC && !isUp(norm, poly[mid], poly[mid - 1]))
			return mid;

		// reference http://geomalgorithms.com/a14-_extreme_pts.html
		// pick segment [lo, mid] in 3 cases for maxPos
		// 1. lo - up, mid - down; 2. lo - up, mid - up, mid below lo; 3. lo down, mid - down, mid above lo
		if ((isUpA && (isDownC || (isUpC && isDownAC))) || (isDownA && isDownC && isUpAC))
			hi = mid;
		else
			lo = mid;
	}
	if (isUp(norm, poly[lo], poly[hi]))
		maxPos = hi;
	else
		maxPos = lo;

	//fout << "method 2 " << minPos << " " << maxPos << endl;
	return maxPos;
}
bool intersect()
{
	point norm = { a,b };
	int maxPos = find_polyMax(hull, norm);
	int minPos = find_polyMax(hull, { -norm.x,-norm.y });
	if (above_line(hull[maxPos], norm, c) * above_line(hull[minPos], norm, c) <= 0)
		return 1;
	return 0;
}
int main()
{
	init();

	update();
	F0R(i, q)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> a >> b;
			point k;
			k.x = a;
			k.y = b;
			todo.pb(k);
		}
		else
		{
			cin >> a >> b >> c;
			if (intersect())
				cout << "NO" << endl;
			else
			{
				int flag = 0;

				trav(k, todo)
				{
					if (above_line(k, { a,b }, c) * above_line(hull[0], { a,b }, c) <= 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag)cout << "NO" << endl;
				else cout << "YES" << endl;
			}
		}
		if ((i + 1) % sqrt_q == 0)
			update();
	}
}