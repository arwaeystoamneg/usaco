#include "grader.h"
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
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
#define inf 1000000007
#define endl '\n'
#define ednl '\n'
#define test int t;cin>>t;while(t--)
#define vin(v,n) vi (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vlln(v,n) vector<ll> (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vvin(v,n,m) vector<vi>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pi 3.1415926535
#define vvlln(v,n,m) vector<vector<ll>>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pq priority_queue
#define linf 1000000000000000000LL

int n;
vector<vi>adjacency;
vpi edges;
void addRoad(int a, int b)
{
	n++;
	edges.pb({ a,b });
}

int t1;
int t2;
vi tin;
vi tout;
vi parents;
vi depth;
bool is_ancestor(int anc, int node)
{
	return tin[anc] <= tin[node] && tout[anc] >= tout[node];
}
void preorder(int index)
{
	tin[index] = ++t1;
	trav(x, adjacency[index])
	{
		if (tin[x] == -1)
		{
			parents[x] = index;
			depth[x] = depth[index] + 1;
			preorder(x);
		}
	}
	tout[index] = ++t2;
}
int logh;
vector<vi>jump;
vpi position;/*
void setFarmLocation(int a, int b, int c)
{
	cout << "set: " << a << " " << b << " " << c << ednl;
}*/
void buildFarms()
{
	n++;
	adjacency.rsz(n);
	F0R(i, n - 1)
	{
		int a = edges[i].f;
		int b = edges[i].s;
		adjacency[a].pb(b);
		adjacency[b].pb(a);
	}
	tin.rsz(n, -1);
	tout.rsz(n);
	parents.rsz(n);
	depth.rsz(n);
	preorder(0);
	parents[0] = -1;
	int h = *max_element(all(depth));
	logh = log2(h - 1) + 1;
	jump.rsz(n);
	F0R(i, n)jump[i].rsz(logh + 1);
	F0R(i, n)jump[i][0] = parents[i];
	FOR(i, 1, logh + 1)F0R(j, n)
	{
		int a = jump[j][i - 1];
		if (a != -1)jump[j][i] = jump[a][i - 1];
		else jump[j][i] = -1;
	}
	position.rsz(n);
	F0R(i, n)position[i] = { tin[i],tout[i] };
	F0R(i, n)setFarmLocation(i, position[i].f, position[i].s);
	//cout << "position: " << endl;
	//trav(x, position)
	//	cout << x.f << " " << x.s << endl;
}

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
}/*
void addBox(int a, int b, int c, int d)
{
	cout << a << " " << b << " " << c << " " << d << endl;
}*/
void add_box(int i, int j)
{
	addBox(min(position[i].f, position[j].f), min(position[i].s, position[j].s), max(position[i].f, position[j].f), max(position[i].s, position[j].s));
}
int find_anc(int lca, int node)
{
	int d = depth[node] - depth[lca];
	d--;
	int change = 15;
	while (change >= 0)
	{
		if (d >= (1 << change))
		{
			d -= (1 << change);
			node = jump[node][change];
		}
		change--;
	}
	return node;
}
void notifyFJ(int a, int b)
{
	if (depth[a] > depth[b])swap(a, b);
	int lca = LCA(a, b);
	add_box(lca, a);
	if (a != b || lca != a)
	{
		int l = find_anc(lca, b);/*
		trav(x, adjacency[lca])
		{
			if (parents[lca] != x && is_ancestor(x, b))
			{
				l = x;
				break;
			}
		}*/
		add_box(l, b);
	}
}/*
int main()
{
	while (1)
	{
		int b, c;
		cin >> b >> c;
		if (b == -1)
		{
			buildFarms();
			break;
		}
		addRoad(b, c);
	}
	int q;
	cin >> q;
	int a, b;
	F0R(i, q)
	{
		cin >> a >> b;
		notifyFJ(a, b);
	}
}*/