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
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<double>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<bool>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<ll, ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<pii, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s << endl;
	cout << endl;
}
void print_vector(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void print_vector(vector<vector<string>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pair<ll, ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
	cout << endl;
}
void print_vector(vector<vector<vi>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<vector<ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<bool>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_set(set<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_set(set<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << i->f << " " << i->s << endl;
	cout << endl;
}
void print_vector(vector<set<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_set(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
}
void print_set(set<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_map(map<int, vector<int>> m)
{
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, vector<string>> m)
{
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s << endl;
	}
}
void print_map(map<string, vector<bool>> m)
{
	for (map<string, vector<bool>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_set(i->second);
	}
}
void print_map(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void print_map(map<char, vector<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t';
		print_vector(i->second);
	}
}
void print_map(map<char, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t' << i->second << endl;
	}
}
void print_map(map<pii, int> m)
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
	//freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);
}
struct query
{
	int type, index;
};
int q;
vector<query>A;
vector<vi>adj;
int n;
void init()
{
	setIO("newbarn");
	cin >> q;
	A.rsz(q);
	F0R(i, q)
	{
		char d;
		cin >> d >> b;
		b--;
		A[i].type = d;
		A[i].index = b;
		if (d == 'B')n++;
	}
	adj.rsz(n);
	c = 0;
	F0R(i, q)
	{
		if (A[i].type == 'B')
		{
			if (A[i].index != -2)
			{
				adj[A[i].index].pb(c);
				adj[c].pb(A[i].index);
			}
			c++;
		}
	}
	//print_vector(adj);
}
vi tin, tout, depth, parents, sizes;// size n, parent[0]=-1, depth[0] = 0
void preorder(int i)
{
	tin[i] = a;
	a++;
	trav(x, adj[i])
	{
		if (tin[x] == -1)
		{
			depth[x] = depth[i] + 1;
			parents[x] = i;
			preorder(x);
		}
	}
	tout[i] = a;
	a++;
}
vi visited;
void dfs1(int i, int p)
{
	// visit i
	sizes[i] = 1;
	for (auto x : adj[i])
	{
		if (x == p || visited[i] == 1)
			continue;
		dfs1(x, i);
		sizes[i] += sizes[x];
	}
}
int dfs_centroid(int i, int p, int n)
{
	// visit i, find the centroid c
	// recurrent if i has a subtree larger than n/2;
	for (auto x : adj[i])
	{
		if (x == p)
			continue;
		if (sizes[x] > n / 2)
			return dfs_centroid(x, i, n);
	}
	return i;
}
vi parent;
vector<vi>adj1;
void build(int i, int p)
{
	// first dfs to generate size of subtree starting from node i
	// 2nd dfs to find the centroid
	dfs1(i, p);
	int centroid = dfs_centroid(i, p, sizes[i]);
	visited[centroid] = 1;
	parent[centroid] = p;
	if (p != -1)
		adj1[p].pb(centroid);
	//cout << centroid << endl;
	// remove the edge from centroid to all its child, build from its child
	for (auto x : adj[centroid])
	{
		if (x == parent[centroid])
			continue;
		//cout << "working on subtree of " << x << endl;
		if (visited[x])
			continue;
		build(x, centroid);
	}
}
bool is_ancestor(int anc, int node)
{
	return tin[anc] <= tin[node] && tout[anc] >= tout[node];
}
int logh;
vector<vi>jump;
int LCA(int x, int y)//LCA with Sparse Table
{
	if (depth[x] > depth[y])swap(x, y);
	if (is_ancestor(x, y))return x;
	int j = logh - 1;
	int next;
	while (!is_ancestor(parents[x], y))
	{
		next = jump[x][j];
		if (next == -1 || is_ancestor(next, y))
		{
			j--;
		}
		else
		{
			x = next;
		}
	}
	return parents[x];
}
vi active;
// centroid prep
struct dist
{
	int best, best_index, second, second_index;
};
vi tin1, tout1;
bool is_ancestor1(int anc, int node)
{
	return tin1[anc] <= tin1[node] && tout1[anc] >= tout1[node];
}
void depth_fs(int i, int p)
{
	tin1[i] = a;
	a++;
	trav(x, adj1[i])
	{
		if (x != p)
		{
			depth_fs(x, i);
		}
	}
	tout1[i] = a;
	a++;
}
int main()
{//I/O -> adj
	init();

	sizes.rsz(n, -1);
	vi roots;
	parent.rsz(n);
	visited.rsz(n);
	adj1.rsz(n);
	F0R(i, n)
	{
		if (sizes[i] != -1)cont;
		// centroid prep
		dfs1(i, -1);
		build(i, -1);
		//roots.pb(i);
	}
	F0R(i, n)if (parent[i] == -1)roots.pb(i);
	//print_vector(parent);
	//print_vector(roots);
	a = 0;
	tin.rsz(n, -1);
	tout.rsz(n);
	depth.rsz(n);
	parents.rsz(n);
	trav(x, roots)
	{
		preorder(x);
		parents[x] = -1;
	}
	//print_vector(tin);
	//print_vector(tout);
	//print_vector(depth);
	//print_vector(parents);
	//print_vector(sizes);

	// lca prep
	jump.rsz(n);
	int h = *max_element(all(depth));
	logh = log2(h) + 1;
	jump.rsz(n);
	F0R(i, n)jump[i].rsz(logh + 1);
	F0R(i, n)jump[i][0] = parents[i];
	FOR(i, 1, logh + 1)F0R(j, n)
	{
		a = jump[j][i - 1];
		if (a != -1)jump[j][i] = jump[a][i - 1];
		else jump[j][i] = -1;
	}
	//while (cin >> a >> b)
	//	cout << LCA(a, b) << endl;
	// end of lca prep

	// prep for queries
	tin1.rsz(n);
	tout1.rsz(n);
	trav(x, roots)depth_fs(x, -1);
	vector<dist>d;
	d.rsz(n);
	F0R(i, n)
	{
		d[i].best = 0;
		d[i].best_index = -1;
		d[i].second = 0;
		d[i].second_index = -1;
	}
	// solving queries
	active.rsz(n);

	c = 0;
	F0R(i, q)
	{
		if (A[i].type == 'B')
		{
			int x = A[i].index;
			x = c;
			c++;
			active[x] = 1;
			int y = x;
			int z = x;
			while (parent[y] != -1)
			{
				z = y;
				y = parent[y];
				//if (active[y] == 0)cont;
				int lca = LCA(x, y);
				int distance = depth[x] + depth[y] - 2 * depth[lca];
				if (d[y].best_index == -1)
				{
					d[y].best = distance;
					d[y].best_index = z;
				}
				else if (d[y].best_index != z)
				{
					if (d[y].best < distance)
					{
						d[y].second = d[y].best;
						d[y].second_index = d[y].best_index;
						d[y].best = distance;
						d[y].best_index = z;
					}
					else if (d[y].second_index != z)
					{
						if (d[y].second < distance)
						{
							d[y].second = distance;
							d[y].second_index = z;
						}
					}
					else
					{
						if (d[y].second < distance)
						{
							d[y].second = distance;
						}
					}
				}
				else
				{
					if (d[y].best < distance)
					{
						d[y].best = distance;
					}
				}
			}
		}
		else
		{
			int x = A[i].index;
			int y = x;
			int max = 0;
			if (parent[x] == -1)max = d[y].best;
			else
			{
				while (y != -1)
				{
					if (active[y] == 0) { y = parent[y]; cont; }
					int best;
					if (d[y].best_index == -1 && d[y].second_index == -1)
					{
						best = 0;
					}
					else if (d[y].best_index == -1)
					{
						//if (!is_ancestor(d[y].second_index, x))
						//	best = d[y].second;
						best = 0;
					}
					else
					{
						if (!is_ancestor1(d[y].best_index, x))
							best = d[y].best;
						else
							best = d[y].second;
					}
					int lca = LCA(x, y);
					int distance = depth[x] + depth[y] - 2 * depth[lca];
					distance += best;
					max = maximum(max, distance);
					y = parent[y];
				}
			}
			cout << max << endl;
		}
	}
}