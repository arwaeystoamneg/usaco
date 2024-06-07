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
template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) {
		v = int((-MOD < _v&& _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mint& a, const mint& b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b);
	}
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v;
	}

	mint& operator+=(const mint& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this;
	}
	mint& operator-=(const mint& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this;
	}
	mint& operator*=(const mint& m) {
		v = int((ll)v * m.v % MOD); return *this;
	}
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint power(mint a, ll p) {// MAKE SURE YOU ARE USING THE CORRECT VERSION OF POW!!!!!!!!
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) {
		assert(a.v != 0);
		return power(a, MOD - 2);
	}

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<inf, 5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;
void pv(vmi a) { trav(x, a)cout << (int)x << " "; cout << endl; }
void pv(vector<vmi> a) { trav(x, a)pv(x); cout << endl; }




int n;
vector<string>a;
const int MAX = 155;
int prefix[MAX][MAX];
mi dp[MAX][2][2][MAX][MAX];// dp[i][l][r][f1][f2]. currently at the ith position. The previous was from l to r. 
// if f1, you can not extend to the left. if f2, you can no extend to the right

// checks if you can do the segment from j to k on the ith row
int check(int i, int j, int k)
{
	return prefix[i][k + 1] - prefix[i][j] == k + 1 - j;
}
mi sum[2][2][MAX][MAX];
mi get(int i, int k, int j, int l, int f1, int f2)
{
	return sum[f1][f2][k + 1][l + 1] - sum[f1][f2][i][l + 1] - sum[f1][f2][k + 1][j] + sum[f1][f2][i][j];
}
int main()
{
	setIO("");
	cin >> n;
	a.rsz(n);
	trav(x, a)cin >> x;
	F0R(i, n)
	{
		F0R(j, n)prefix[i][j + 1] = prefix[i][j] + (a[i][j] == 'G');
	}
	F0R(k, n)
	{
		F0R(i, n)FOR(j, i, n)
		{
			if (check(k, i, j))dp[k][0][0][i][j] = 1;
		}
	}
	F0R(f1, 2)
	{
		F0R(f2, 2)
		{
			F0R(j, n)
			{
				F0R(k, n)
				{
					sum[f1][f2][j + 1][k + 1] = sum[f1][f2][j + 1][k] + sum[f1][f2][j][k + 1] - sum[f1][f2][j][k] + dp[0][f1][f2][j][k];
				}
			}
		}
	}
	FOR(i, 1, n)
	{
		F0R(l, n)
		{
			FOR(r, l, n)
			{
				if (!check(i, l, r))continue;
				//[0, 0] -> [0, 0]
				dp[i][0][0][l][r] += get(l, r, l, r, 0, 0);

				//[0, 0] -> [0, 1]
				dp[i][0][1][l][r] += get(l, r, r + 1, n - 1, 0, 0);

				//[0, 0] -> [1, 0]
				dp[i][1][0][l][r] += get(0, l - 1, l, r, 0, 0);

				//[0, 0] -> [1, 1]
				dp[i][1][1][l][r] += get(0, l - 1, r + 1, n - 1, 0, 0);

				//[0, 1] -> [0, 1]
				dp[i][0][1][l][r] += get(l, r, r, n - 1, 0, 1);

				//[0, 1] -> [1, 1]
				dp[i][1][1][l][r] += get(0, l - 1, r, n - 1, 0, 1);

				//[1, 0] -> [1, 0]
				dp[i][1][0][l][r] += get(0, l, l, r, 1, 0);

				//[1, 0] -> [1, 1]
				dp[i][1][1][l][r] += get(0, l, r + 1, n - 1, 1, 0);

				//[1, 1] -> [1, 1]
				dp[i][1][1][l][r] += get(0, l, r, n - 1, 1, 1);

				/*
				F0R(f1, 2)
				{
					F0R(f2, 2)
					{

						F0R(prevj, n)
						{
							FOR(prevk, prevj, n)
							{
								// prevj and prevk refer to the previous rows pointers
								// f1 and f2 refer to the previous rows flags
								if (j > prevk || prevj > k)continue;
								if (f1 && prevj > j)continue;
								if (f2 && prevk < k)continue;
								dp[i][f1 || j > prevj][f2 || k < prevk][j][k] += dp[i - 1][f1][f2][prevj][prevk];

							}
						}
					}
				}
				*/
			}
		}
		F0R(f1, 2)
		{
			F0R(f2, 2)
			{
				F0R(j, n)
				{
					F0R(k, n)
					{
						sum[f1][f2][j + 1][k + 1] = sum[f1][f2][j + 1][k] + sum[f1][f2][j][k + 1] - sum[f1][f2][j][k] + dp[i][f1][f2][j][k];
					}
				}
			}
		}
	}
	mi ans = 0;
	F0R(index, n)
	{
		F0R(j, n)
		{
			FOR(k, j, n)
			{
				F0R(f1, 2)F0R(f2, 2)ans += dp[index][f1][f2][j][k];
			}
		}
	}
	cout << (int)ans << endl;
}