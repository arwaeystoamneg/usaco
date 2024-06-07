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
int SZ = 17;
void exp(vector<vll>& a, int count)
{
	int n = sz(a);
	vector<vll>t(n, vll(n)); F0R(i, n)t[i][i] = 1;
	F0R(i, SZ)
	{
		if (count & (1 << i))
		{
			t = matrix_mult(t, a);
		}
		a = matrix_mult(a, a);
	}
	a = t;
}
string input;
vector<string>b;
void split()
{
	b.rsz(0);
	b.push_back("");
	F0R(i, sz(input))
	{
		if (input[i] == ' ' || input[i] == ')' || input[i] == '(' || input[i] == '+')
		{
			if (sz(b.back()))
				b.pb("");
		}
		else
		{
			b.back().push_back(input[i]);
		}
	}
	while (b.back() == "")b.pop_back();
}
int parse(string a)
{
	int ans = 0;
	F0R(i, sz(a))
		ans *= 10, ans += a[i] - '0';
	return ans;
}
int n;
vector<vector<string>>a;
vector<vll> val;
vll init;
int cur = 0;
unordered_map<string, int>key;
struct loop
{
	int count;
	vector<vll>t;
};
vector<loop>loops;
int main()
{
	setIO("cowbasic");
	while (getline(cin, input))
	{
		split();
		a.push_back(b);
		if (sz(b) >= 2 && b[1] == "=")
			n++;
		if (sz(b) == 2)break;
	}
	init.rsz(n);
	// val[n] is constant
	vector<vll>identity(n + 1, vll(n + 1)); F0R(i, n + 1)identity[i][i] = 1;
	val = identity;
	F0R(i, sz(a))
	{
		vector<string> x = a[i];
		if (sz(x) == 2)
		{
			//pv(val);
			cout << val[n][key[x[1]]] << endl;
			return 0;
		}
		else if (sz(x) == 1)
		{
			vector<vll>t = loops.back().t;
			exp(t, loops.back().count);
			loops.pop_back();
			if (sz(loops))
				loops.back().t = matrix_mult(loops.back().t, t);
			else
				val = matrix_mult(val, t);
		}
		// everything else if greater than size 2
		else if (x[1] == "=")
		{
			if (!key.count(x[0]))
			{
				key.insert({ x[0],cur++ });
			}
			if (sz(loops))
			{
				vector<vll>t = loops.back().t;
				int index = key[x[0]];
				F0R(i, n + 1)t[i][index] = 0;
				FOR(j, 2, sz(x))
				{
					if (x[j][0] >= '0' && x[j][0] <= '9')
					{
						t[n][index] += parse(x[j]);
						t[n][index] %= inf;
					}
					else
					{
						int tmp = key[x[j]];
						F0R(k, n + 1)t[k][index] += loops.back().t[k][tmp], t[k][index] %= inf;
					}
				}
				loops.back().t = t;
			}
			else
			{
				vector<vll>t = val;
				int index = key[x[0]];
				F0R(i, n + 1)t[i][index] = 0;
				FOR(j, 2, sz(x))
				{
					if (x[j][0] >= '0' && x[j][0] <= '9')
					{
						t[n][index] += parse(x[j]);
						t[n][index] %= inf;
					}
					else
					{
						int tmp = key[x[j]];
						F0R(k, n + 1)t[k][index] += val[k][tmp], t[k][index] %= inf;
					}
				}
				val = t;
			}
		}
		else if (x[1] == "MOO")
		{
			loops.push_back({ parse(x[0]),identity });
		}
	}
}