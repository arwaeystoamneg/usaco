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
#define pq priority_queue
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353
const ld pi = 3.1415926535;
struct point
{
	int x, y;
};
long double area(point x, point y, point z)
{
	return ((ll)x.y * y.x + (ll)y.y * z.x + (ll)z.y * x.x - (ll)x.x * y.y - (ll)y.x * z.y - (ll)z.x * x.y) / 2.0;
}
bool clockwise(point x, point y, point z)
{
	return area(x, y, z) > 0;
}
int n;
vector<point>points;
vector<point> hull;
point p;
bool __convex_sort(point x,point y)
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
struct Line {
	mutable ll k, m, p; // slope, y-intercept, last optimal x
	ll eval(ll x) { return k * x + m; }
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : deque<Line> { // linear time w/ additional assumptions
	// for doubles, use inf = 1/.0, div(a,b) = a/b
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // floored division
	ll bet(const Line& x, const Line& y) { // last x such that first line is better
		if (x.k == y.k) return x.m >= y.m ? inf : -inf;
		return div(y.m - x.m, x.k - y.k);
	}

	void addBack(Line L) { // assume nonempty
		while (1) {
			auto a = back(); pop_back(); a.p = bet(a, L);
			if (size() && back().p >= a.p) continue;
			pb(a); break;
		}
		L.p = inf; pb(L);
	}
	void addFront(Line L) {
		while (1) {
			if (!size()) { L.p = inf; break; }
			if ((L.p = bet(L, front())) >= front().p) pop_front();
			else break;
		}
		push_front(L);
	}
	void add(ll k, ll m) { // assume line goes to one end of deque
		if (!size() || k <= front().k) addFront({ k,m,0 });
		else assert(k >= back().k), addBack({ k,m,0 });
	}

	int ord = 0; // 1 = increasing, -1 = decreasing
	ll query(ll x) {
		assert(ord);
		if (ord == 1) {
			while (front().p < x) pop_front();
			return front().eval(x);
		}
		else {
			while (size() > 1 && prev(prev(end()))->p >= x) pop_back();
			return back().eval(x);
		}
	}
};
class CHT_dynamic
{
	struct Line {
		mutable ll k, m, p;
		bool operator<(const Line& o) const { return k < o.k; }
		bool operator<(ll x) const { return p < x; }
	};

	struct LineContainer : multiset<Line, less<>> {
		// (for doubles, use inf = 1/.0, div(a,b) = a/b)
		static const ll inf = LLONG_MAX;
		ll div(ll a, ll b) { // floored division
			return a / b - ((a ^ b) < 0 && a % b);
		}
		bool isect(iterator x, iterator y) {
			if (y == end()) return x->p = inf, 0;
			if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
			else x->p = div(y->m - x->m, x->k - y->k);
			return x->p >= y->p;
		}
		void add(ll k, ll m) {
			auto z = insert({ k, m, 0 }), y = z++, x = y;
			while (isect(y, z)) z = erase(z);
			if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
			while ((y = x) != begin() && (--x)->p >= y->p)
				isect(x, erase(y));
		}
		ll query(ll x) {
			assert(!empty());
			auto l = *lower_bound(x);
			return l.k * x + l.m;
		}
	};
};
class CHT1
{
	static const int mxN = 1e6;
	int n, ptr, last;
	ll a[mxN + 1], b[mxN + 1];
	int check(ll ai, ll bi)
	{
		return (b[last - 1] - b[last - 2]) / (a[last - 2] - a[last - 1]) >= (bi - b[last - 1]) / (a[last - 1] - ai);
	}
	void al(ll ai, ll bi) {
		while (last - ptr >= 2 && check(ai, bi))
			--last;
		a[last] = ai, b[last] = bi;
		++last;
	}
	ll intersect(ll xi, ll ptr)
	{
		return a[ptr] * xi + b[ptr];
	}
	ll query(ll xi) {
		while (last - ptr >= 2 && intersect(xi, ptr) <= intersect(xi, ptr + 1))
			++ptr;
		return a[ptr] * xi + b[ptr];
	}
	//use this when the query positions are in random order
	ll query(ll xi)//https://codeforces.com/contest/631/submission/95296474
	{
		int low = 0, high = last - 2;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (intersect(xi, mid) > intersect(xi, mid + 1))
				high = mid - 1;
			else
				low = mid + 1;
		}
		return a[low] * xi + b[low];
	}
	/*
	// Query Min

	int n;
	cin >> n;
	vll a(n), b(n);
	F0R(i, n)cin >> a[i];
	a[0]--;
	F0R(i, n)cin >> b[i];
	vll dp(n, linf);
	F0R(i, n)
	{
		dp[i] = -query(a[i]);
		al(-b[i], -dp[i]);
	}
	cout << dp[n - 1] << endl;
	*/
};
class CHT//https://codeforces.com/blog/entry/63823
{
	struct line {
		long long m, c;
		long long eval(long long x) { return m * x + c; }
		long double intersectX(line l) { return (long double)(c - l.c) / (l.m - m); }
	};
public:void a()
{
	struct pt
	{
		int x, y;
	};
	vector<pt>a;
	deque<line> dq;
	dq.push_front({ 0, 0 });
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		while (dq.size() >= 2 && dq.back().eval(a[i].x) <= dq[dq.size() - 2].eval(a[i].x))
			dq.pop_back();



		long long f = dq.back().eval(rects[i].q) + rects[i].p * 1LL * rects[i].q - rects[i].a;
		ans = max(ans, f);
		line cur = { -rects[i].p, f };



		while (dq.size() >= 2 && cur.intersectX(dq[0]) >= dq[0].intersectX(dq[1]))
			dq.pop_front();
		dq.push_front(cur);
	}
}
};
int main()
{
	cin >> n;
	points.rsz(n);
	int a, b;
	F0R(i, n)
	{
		cin >> a >> b;
		points[i].x = a;
		points[i].y = b;
	}
	convex_hull();
	trav(X, hull)cout << X.x << " " << X.y << endl;
	int c;
	while (1)
	{
		cin >> a >> b >> c;
		point norm = { a,b };
		int maxPos = find_polyMax(hull, norm);
		int minPos = find_polyMax(hull, { -norm.x, -norm.y });
		cout << endl;
		cout << minPos << " " << maxPos << endl;
		if (above_line(hull[maxPos], norm, c) * above_line(hull[minPos], norm, c) <= 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}