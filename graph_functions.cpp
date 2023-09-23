#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

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

class union_find
{ 
	vi links; // n iota(all(links),0)
	int find(int a)
	{
		return links[a] == a ? a : links[a] = find(links[a]);
	}
	void unite(int a, int b)
	{
		links[find(a)] = find(b);
	}
};
class prims
{
	int n;
	vector<vpi>adjacency;
	vi visited;
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
};
class dijkstras
{
	vector<vpi>adjacency;
	vll dist;
	int N;
	vi parents;
	void dijkstra(int i)
	{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
		priority_queue<pair<ll, ll>>todo;
		vi finalized;
		finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
		todo.push(mp(0, i));
		while (!todo.empty())
		{//.s is indexs while .f is weight
			pair<ll, ll> temp = todo.top();
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
	void dijkstra(int i, vll& dist, vi& parents, vector<vpll>&adj)
	{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
		int N = sz(adj);
		dist.rsz(N, linf); parents.rsz(N, -1);
		fill(all(dist), linf); fill(all(parents), -1);
		dist[i] = 0; parents[i] = -1;
		priority_queue<pair<ll, ll>, vpll, greater<pair<ll, ll>>>todo;
		todo.push(mp(0, i));
		while (sz(todo))
		{//.s is indexs while .f is weight
			pair<ll, ll> temp = todo.top();
			int j = temp.second;
			todo.pop();
			if (temp.f != dist[j])cont;
			trav(x, adj[j])
			{
				if (dist[x.f] > x.s + dist[j])
				{
					dist[x.first] = x.s + dist[j];
					parents[x.f] = j;
					todo.push(mp(dist[x.first], x.f));
				}
			}
		}
	}
};
class euler_paths
{
	vector<set<int>>adj;
	vi ans;
	void find_circuit(int i)
	{
		if (!sz(adj[i])) { ans.pb(i); return; }
		while (sz(adj[i]))
		{
			int j = *adj[i].begin();
			adj[i].erase(j);
			adj[j].erase(i);
			find_circuit(j);
		}
		ans.pb(i);
	}
	/*
	euler_circuit();
	if (sz(ans) < m - 1 || sz(ans) == 0)cout << "IMPOSSIBLE" << endl;
	else trav(x, ans)cout << x + 1 << " ";
	*/
	void euler_circuit()
	{
		int n = sz(adj);
		F0R(i, n)
		{
			if (sz(adj[i]) & 1)
			{
				return;
			}
		}
		find_circuit(0);
	}
	void euler_path()
	{
		int n = sz(adj);
		int a = 0, b = 0;
		F0R(i, n)
		{
			if (sz(adj[i]) & 1)
				a++;
			else
				b++;
		}
		if (a != 2 && a != 0)return;
		int i = 0;
		for(;i<n;i++)
		{
			if (sz(adj[i]) & 1)break;
		}
		find_circuit(i);
	}
};
class max_flow
{
	template <int MAXV, class T = int> struct Dinic {
		const static bool SCALING = false; // non-scaling = V^2E, Scaling=VElog(U) with higher constant
		int lim = 1;
		const T INF = numeric_limits<T>::max();
		struct edge {
			int to, rev;
			T cap, flow;
		};
		int s = 0, t = MAXV - 1;

		int level[MAXV], ptr[MAXV];
		vector<edge> adj[MAXV];
		void addEdge(int a, int b, T cap, bool isDirected = true) {
			adj[a].push_back({ b, sz(adj[b]), cap, 0 });
			adj[b].push_back({ a, sz(adj[a]) - 1, isDirected ? 0 : cap, 0 });
		}
		bool bfs() {
			queue<int> q({ s });
			fill(level, level + MAXV, -1);
			level[s] = 0;
			while (!q.empty() && level[t] == -1) {
				int v = q.front();
				q.pop();
				for (auto e : adj[v]) {
					if (level[e.to] == -1 && e.flow < e.cap && (!SCALING || e.cap - e.flow >= lim)) {
						q.push(e.to);
						level[e.to] = level[v] + 1;
					}
				}
			}
			return level[t] != -1;
		}
		T dfs(int v, T flow) {
			if (v == t || !flow)
				return flow;
			for (; ptr[v] < adj[v].size(); ptr[v]++) {
				edge& e = adj[v][ptr[v]];
				if (level[e.to] != level[v] + 1)
					continue;
				if (T pushed = dfs(e.to, min(flow, e.cap - e.flow))) {
					e.flow += pushed;
					adj[e.to][e.rev].flow -= pushed;
					return pushed;
				}
			}
			return 0;
		}
		long long calc() {
			long long flow = 0;
			for (lim = SCALING ? (1 << 30) : 1; lim > 0; lim >>= 1) {
				while (bfs()) {
					fill(ptr, ptr + MAXV, 0);
					while (T pushed = dfs(s, INF))
						flow += pushed;
				}
			}
			return flow;
		}
	};
	// O(n^3) - Dinic
	template <int MAXV, class T = int> struct Dinic {
		const static bool SCALING = false; // non-scaling = V^2E, Scaling=VElog(U) with higher constant
		int lim = 1;
		const T INF = numeric_limits<T>::max();
		struct edge {
			int to, rev;
			T cap, flow;
		};
		int s = MAXV - 2, t = MAXV - 1;

		int level[MAXV], ptr[MAXV];
		vector<edge> adj[MAXV];
		void addEdge(int a, int b, T cap, bool isDirected = true) {
			adj[a].push_back({ b, adj[b].size(), cap, 0 });
			adj[b].push_back({ a, adj[a].size() - 1, isDirected ? 0 : cap, 0 });
		}
		bool bfs() {
			queue<int> q({ s });
			fill(all(level), -1);
			level[s] = 0;
			while (!q.empty() && level[t] == -1) {
				int v = q.front();
				q.pop();
				for (auto e : adj[v]) {
					if (level[e.to] == -1 && e.flow < e.cap && (!SCALING || e.cap - e.flow >= lim)) {
						q.push(e.to);
						level[e.to] = level[v] + 1;
					}
				}
			}
			return level[t] != -1;
		}
		T dfs(int v, T flow) {
			if (v == t || !flow)
				return flow;
			for (; ptr[v] < adj[v].size(); ptr[v]++) {
				edge& e = adj[v][ptr[v]];
				if (level[e.to] != level[v] + 1)
					continue;
				if (T pushed = dfs(e.to, min(flow, e.cap - e.flow))) {
					e.flow += pushed;
					adj[e.to][e.rev].flow -= pushed;
					return pushed;
				}
			}
			return 0;
		}
		long long calc() {
			long long flow = 0;
			for (lim = SCALING ? (1 << 30) : 1; lim > 0; lim >>= 1) {
				while (bfs()) {
					fill(all(ptr), 0);
					while (T pushed = dfs(s, INF))
						flow += pushed;
				}
			}
			return flow;
		}
	};
	// O(m * flow) - Ford - fulkerson
	ll get_flow(vector<vll>adj, int source, int sink)
	{
		int n = sz(adj);
		if (source == sink)
		{
			return linf;
		}
		ll ans = 0;
		while (1)
		{
			vi prev(n, -1);
			vi flow(n, 0);
			vi visited(n, 0);
			flow[source] = linf;
			ll maxflow = 0, maxloc = -1;
			while (1)
			{
				maxflow = 0, maxloc = -1;
				F0R(i, n)
				{
					if (flow[i] > maxflow && !visited[i])
					{
						maxflow = flow[i];
						maxloc = i;
					}
				}
				if (maxloc == -1)break;
				if (maxloc == sink)break;
				visited[maxloc] = 1;
				F0R(i, n)
				{
					if (adj[maxloc][i] == 0)continue;
					if (flow[i] < min(maxflow, adj[maxloc][i]))
					{
						prev[i] = maxloc;
						flow[i] = min(maxflow, adj[maxloc][i]);
					}
				}
			}
			if (maxloc == -1)break;
			ll pathcapacity = flow[sink];
			ans += pathcapacity;
			int cur = sink;
			while (cur != source)
			{
				int next = prev[cur];
				adj[next][cur] -= pathcapacity;
				adj[cur][next] += pathcapacity;
				cur = next;
			}
		}
		return ans;
	}
};
template<int MAX>struct scc
{
	int mode = 0;
	vector < vector<int> > g, gr;
	bitset<MAX>used;
	vector<int> order, component;

	void dfs1(int v) {
		used[v] = true;
		for (size_t i = 0; i < g[v].size(); ++i)
			if (!used[g[v][i]])
				dfs1(g[v][i]);
		order.push_back(v);
	}

	void dfs2(int v) {
		used[v] = true;
		component.push_back(v);
		for (size_t i = 0; i < gr[v].size(); ++i)
			if (!used[gr[v][i]])
				dfs2(gr[v][i]);
	}
	void init(vector<vi>& adj)
	{
		mode = 1;
		int n = sz(adj);
		g = adj;
		gr.rsz(n);
		F0R(i, n)
		{
			trav(x, adj[i])
			{
				gr[x].push_back(i);
			}
		}
	}
	vi get_component()
	{
		assert(mode);
		int n = sz(g);
		vi ans(n);
		F0R(i, n)if (!used[i])dfs1(i);
		F0R(i, MAX)used[i] = 0;
		int count = 0;
		F0R(i, n)
		{
			int v = order[n - 1 - i];
			if (!used[v])
			{
				dfs2(v);
				trav(x, component)ans[x] = count;
				count++;
				component.clear();
			}
		}
		return ans;
	}
	vi get_2sat()
	{
		int n = sz(g) / 2;
		vi comp = get_component();
		//pv(comp);
		F0R(i, n)
		{
			if (comp[2 * i] == comp[2 * i + 1])
			{
				return {};
			}
		}
		//F0R(i, 2 * n)cout << i << " " << comp[i] << endl;
		int k = *max_element(all(comp)) + 1;
		vector<vi>Adj(k);
		vi sizes(k);
		vi todo;
		F0R(i, 2 * n)
		{
			trav(x, g[i])
			{
				if (comp[i] != comp[x])
				{
					Adj[comp[i]].pb(comp[x]);
				}
			}
		}
		vi ans;
		ans.rsz(2 * n, -1);
		F0R(i, n)
		{
			if (comp[2 * i] < comp[2 * i + 1])
				ans[2 * i] = false, ans[2 * i + 1] = 1;
			else
				ans[2 * i] = true, ans[2 * i + 1] = 0;
		}
		return ans;
	}
};
struct bcc
{
	vector<vpi>ans;
	vpi cur;
	int n;
	vector<vi>adj;
	vi low, disc, parent;
	vpi todo;// stack
	int TIME = -1;
	void init(int x, vector<vi>& y)
	{
		n = x;
		adj = y;
		low.rsz(n, -1);
		disc.rsz(n, -1);
		parent.rsz(n, -1);
		TIME = 0;
	}
	void dfs(int i)
	{
		low[i] = ++TIME;
		disc[i] = TIME;
		int child = 0;
		trav(x, adj[i])
		{
			if (disc[x] == -1)
			{
				child++;
				todo.pb({ i,x });
				parent[x] = i;
				dfs(x);
				low[i] = min(low[i], low[x]);
				if ((disc[i] == 1 && child > 1) || (disc[i] > 1 && low[x] >= disc[i]))
				{
					while (todo.back() != mp(i, x))
					{
						//cout << todo.back().f << " " << todo.back().s << endl;
						cur.push_back({ todo.back().f,todo.back().s });
						todo.pop_back();
					}
					//cout << todo.back().f << " " << todo.back().s << endl;
					cur.push_back({ todo.back().f,todo.back().s });
					ans.pb(cur);
					cur.clear();
					todo.pop_back();
				}
			}
			else if (parent[i] != x && disc[x] < low[i])
			{
				low[i] = disc[x];
				todo.push_back({ i,x });
			}
		}
	}
	vector<vpi> biconnected_components()
	{
		assert(TIME != -1);
		ans.clear();
		F0R(i, n)
		{
			if (disc[i] == -1)
			{
				dfs(i);
				while (sz(todo))
				{
					//cout << todo.back().f << " " << todo.back().s << endl;
					cur.push_back({ todo.back().f,todo.back().s });
					todo.pop_back();
				}
				if (sz(cur))
				{
					ans.push_back(cur);
					cur.clear();
				}
			}
		}
		return ans;
	}
};
int main()
{
	int n, m; cin >> n >> m;
	vector<vi>adj(n);
	F0R(i, m)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bcc graph;
	graph.init(n, adj);
	vector<vpi> a= graph.biconnected_components();
	cout << sz(a);
}