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
vll prefix_hash(string& a, vll& powers, ll mod)
{
	int n = sz(a);
	vll prefix(n + 1);
	F0R(i, n)prefix[i + 1] = (prefix[i] + powers[i] * (a[i] - 'a' + 1)) % mod;
	return prefix;
}
const int MAX = 1e5, base = 31, base1 = 37;
int k;
string t;
unordered_set<int> b, b1, todo;
vll power, inverse, power1, inverse1;
int main()
{
	setIO("censor");
	cin >> t;
	power.rsz(MAX);
	power[0] = 1;
	F0R(i, MAX - 1)power[i + 1] = (power[i] * base) % inf;
	power1.rsz(MAX);
	power1[0] = 1;
	F0R(i, MAX - 1)power1[i + 1] = (power1[i] * base1) % inf;
	inverse.rsz(MAX);
	inverse[0] = 1;
	inverse[1] = modInverse(base, inf);
	inverse1.rsz(MAX);
	inverse1[0] = 1;
	inverse1[1] = modInverse(base1, inf);
	FOR(i, 1, MAX - 1)inverse[i + 1] = (inverse[i] * inverse[1]) % inf;
	FOR(i, 1, MAX - 1)inverse1[i + 1] = (inverse1[i] * inverse1[1]) % inf;
	cin >> k;
	F0R(i, k)
	{
		string x;
		cin >> x;
		todo.insert(sz(x));
		vll t = prefix_hash(x, power, inf);
		b.insert(t.back());
		t = prefix_hash(x, power1, inf);
		b1.insert(t.back());
	}
	string a = "";
	vll prefix(sz(t) + 1);
	vll prefix1(sz(t) + 1);
	trav(x, t)
	{
		a.pb(x);
		prefix[sz(a)] = (prefix[sz(a) - 1] + power[sz(a) - 1] * (x - 'a' + 1)) % inf;
		prefix1[sz(a)] = (prefix1[sz(a) - 1] + power1[sz(a) - 1] * (x - 'a' + 1)) % inf;
		int flag = 0;
		do
		{
			flag = 0;
			trav(len, todo)
			{
				if (len <= sz(a))
				{
					ll hash = prefix[sz(a)] - prefix[sz(a) - len];
					hash *= inverse[sz(a) - len];
					hash %= inf;
					if (hash < 0)hash += inf;
					if (b.count(hash))
					{
						hash = prefix1[sz(a)] - prefix1[sz(a) - len];
						hash *= inverse1[sz(a) - len];
						hash %= inf;
						if (hash < 0)hash += inf;
						if (b1.count(hash))
						{
							F0R(i, len)a.pop_back();
							flag = 1;
							break;
						}
					}
				}
			}
		} while (flag);
	}
	cout << a << endl;
}