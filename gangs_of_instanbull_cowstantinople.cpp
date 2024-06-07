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
		if (s != "test1")
			freopen((s + ".out").c_str(), "w", stdout);
	}
}
int n, m;
vi a;
int type, num;
int type_, num_;
int solve(vi t)
{
	type_ = type, num_ = num;
	priority_queue<int>todo;
	if (type == 0)
	{
		FOR(i, 1, m)if (t[i])todo.push(t[i]);
		while (sz(todo) && num)
		{
			int i = todo.top();
			todo.pop();
			i--;
			num--;
			if (i)todo.push(i);
		}
	}
	else
	{
		num += t[type]; t[type] = 0;
		FOR(i, 1, m)if (t[i])todo.push(t[i]);
		while (sz(todo) && num)
		{
			int i = todo.top();
			todo.pop();
			i--;
			num--;
			if (i)todo.push(i);
		}
	}
	while (sz(todo) >= 2)
	{
		int i = todo.top();
		todo.pop();
		int j = todo.top();
		todo.pop();
		i--; j--;
		if (i)todo.push(i);
		if (j)todo.push(j);
	}
	if (sz(todo))return t[0] - todo.top() + num;
	return t[0] + num;
}
void next(int i)
{
	if (type == i)
	{
		num++;
	}
	else if (num == 0)
	{
		type = i;
		num = 1;
	}
	else
	{
		num--;
	}
}
int main()
{
	setIO("gangs");
	cin >> n >> m;
	a.rsz(m); trav(x, a)cin >> x;
	int ans = solve(a);
	if (ans <= 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl << ans << endl;
	vi order;
	F0R(i, n)
	{
		int j = 0;
		for (; j < m; j++)
		{
			if (!a[j])continue;
			a[j]--;
			int prevtype = type, prevnum = num;
			next(j);
			if (solve(a) == ans)
			{
				order.push_back(j);
				num = num_, type = type_;
				break;
			}
			a[j]++;
			type = prevtype, num = prevnum;
		}
		assert(j != m);
	}
	trav(x, order)cout << x + 1 << endl;
}