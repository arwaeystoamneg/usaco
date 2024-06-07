#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define mp make_pair
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define cont continue
#define inf 1000000007
#define endl '\n'


int ceilingOf(double a)
{
	if (a == (int)a)
		return (int)a;
	return (int)a + 1;
}
int floorOf(double a)
{
	return (int)a;
}
int maximum(int x, int y)
{
	if (x > y)
		return x;
	return y;
}
ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
int minimum(int x, int y)
{
	if (x < y)
		return x;
	return y;
}
void shuffle_array(int arr[], int n)
{
	//set up to call the shuffle function
	random_shuffle(arr, arr + n);
}
void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void print_array(bool arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void print_array(long long arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void print_array(char** arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void print_array(int** arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void print_array(long long** arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int floodArea(int N, int M, bool** pos, bool** visited, int i, int j)
{
	if (pos[i][j] == 0)
		return 0;
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < M; j++)
	//		visited[i][j] = 0;
	list<int> a;
	int maxar = -INT_MAX;
	visited[i][j] = 1;
	a.push_back((N + M) * i + j);
	int counts = 1;
	while (!a.empty())
	{
		int index = a.back();
		a.pop_back();
		int row = index / (M + N);
		int col = index % (M + N);
		if ((row + 1 < N) && visited[row + 1][col] == 0 && pos[row + 1][col] == pos[i][j])
		{
			visited[row + 1][col] = 1;
			a.push_back((M + N) * (row + 1) + col);
			//cout << "    adding to flood " << row + 1 << " " << col << endl;
			counts++;
		}
		if ((col + 1 < M) && visited[row][col + 1] == 0 && pos[row][col + 1] == pos[i][j])
		{
			visited[row][col + 1] = 1;
			a.push_back((M + N) * row + (col + 1));
			//cout << "    adding to flood " << row  << " " << col+1  << endl;
			counts++;
		}
		if ((row - 1 >= 0) && visited[row - 1][col] == 0 && pos[row - 1][col] == pos[i][j])
		{
			visited[row - 1][col] = 1;
			a.push_back((M + N) * (row - 1) + col);
			//cout << "    adding to flood " << row-1 << " " << col << endl;
			counts++;
		}
		if ((col - 1 >= 0) && visited[row][col - 1] == 0 && pos[row][col - 1] == pos[i][j])
		{
			visited[row][col - 1] = 1;
			a.push_back((M + N) * row + (col - 1));
			//cout << "    adding to flood " << row  << " " << col-1 << endl;
			counts++;
		}
	}
	//cout << i<<" "<<j<< " "<<counts << endl;
	if (counts > maxar)
	{
		maxar = counts;
	}
	return maxar;
}
void deleteFlood(int N, int M, int** pos, int** visited, int i, int j)
{
	int val = pos[i][j];
	pos[i][j] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = 0;
	list<int> a;
	int maxar = -INT_MAX;
	visited[i][j] = 1;
	a.push_back((N + M) * i + j);
	int counts = 1;
	while (!a.empty())
	{
		int index = a.back();
		a.pop_back();
		int row = index / (M + N);
		int col = index % (M + N);
		if ((row + 1 < N))
		{
			if (visited[row + 1][col] == 0 && pos[row + 1][col] == val)
			{
				visited[row + 1][col] = 1;
				a.push_back((M + N) * (row + 1) + col);
				pos[row + 1][col] = 0;
			}
		}
		if ((col + 1 < M))
		{
			if (visited[row][col + 1] == 0 && pos[row][col + 1] == val)
			{
				visited[row][col + 1] = 1;
				a.push_back((M + N) * row + (col + 1));
				pos[row][col + 1] = 0;
			}
		}
		if ((row - 1 >= 0))
		{
			if (visited[row - 1][col] == 0 && pos[row - 1][col] == val)
			{
				visited[row - 1][col] = 1;
				a.push_back((M + N) * (row - 1) + col);
				pos[row - 1][col] = 0;
			}
		}
		if ((col - 1 >= 0))
		{
			if (visited[row][col - 1] == 0 && pos[row][col - 1] == val)
			{
				visited[row][col - 1] = 1;
				a.push_back((M + N) * row + (col - 1));
				pos[row][col - 1] = 0;
			}
		}
	}
	//cout << i << " " << j << " " << counts << endl;
}
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<char>amount)
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
void print_vector(vector<int>amount, int N)
{
	for (auto i = amount.begin(); i != amount.begin() + N; i++)
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
	cout << '\t';
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	cout << '\t';
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<ll, ll>>amount)
{
	cout << '\t';
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	cout << '\t';
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<string, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s << endl;
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
void print_vector(vector<pair<pii, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void print_vector(vector<tuple<int, int, int, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << " " << get<3>(*i) << endl;
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
void print_map_vector(map<string, vector<bool>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<int, bool> m)
{
	for (map<int, bool>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void print_map(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
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
	if (x.second > y.s)
	{
		return 0;
	}
	if (x.second == y.s)
	{
		return x.first < y.f;
	}
	return 1;
}
class segment_tree {

	vi tree;   // array of segment tree

	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:segment_tree(int n) {

	height = (int)ceilingOf(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	  // build the tree using the original array A
public:void buildSegTree(vi& A) {
	A.rsz(1 << height, 0);
	//print_vector(A);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}

	  // p: ID of current node
	  // low: left end of the range of node x (inclusive)
	  // high: right end of the range of node x (inclusive)
	  // A: original array
public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}

	int mid = (low + high) / 2;

	tree[p] = buildSegTreeRec(low, mid, leftChild(p), A)
		+ buildSegTreeRec(mid + 1, high, rightChild(p), A);

	return tree[p];
}


	  // find the partial sum between A[x...y], inclusive (0-based)
public:int getSum(int x, int y) {

	if (x < 0 || ENDINDEX < y)
		return -INT_MAX;

	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}

	  // p: ID of current node in the segment tree
	  // [low, high]: range of current node
	  // [x, y]: query range
public:int getSumRec(int low, int high, int x, int y, int p) {

	if (x <= low && high <= y)  // [x, y] contains [low, high]
		return tree[p];

	if (y < low || high < x)   // [x, y] doesn't overlap [low, high]
		return 0;

	int mid = (low + high) / 2;

	return getSumRec(low, mid, x, y, leftChild(p))
		+ getSumRec(mid + 1, high, x, y, rightChild(p));
}

	  // add "val" at position "pos": A[pos] += val
public:void addValue(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, val, 0);
}

	  // p: ID of current node in the segment tree
	  // [low, high]: range of current node
	  // pos: position to be modified
	  // val: the change to the specified position
public:void addValueRec(int low, int high, int pos, int val, int p) {
	if (low <= pos && pos <= high) {
		tree[p] = tree[p] + val;

		if (low != high) {
			int mid = (low + high) / 2;
			addValueRec(low, mid, pos, val, leftChild(p));
			addValueRec(mid + 1, high, pos, val, rightChild(p));
		}
	}
}
public:void print()
{
	print_vector(tree);
}
};



class max_tree {

	vi tree;   // array of segment tree
	int counts = 0;
	int height;   // height of the segment tree
	int maxSize;  // the size of the segment tree in its entirety
				  //   (some nodes may have unused zeros)

	int STARTINDEX = 0;   // the left most range of any query
	int ENDINDEX;         // the right most range of any query

public:max_tree(int n) {

	height = (int)ceilingOf(log2(n));
	maxSize = (1 << (height + 1)) - 1;   // 1 << (height+1) - 1;
	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	  // build the tree using the original array A
public:void build_max_tree(vi& A) {
	A.rsz(1 << height, 0);
	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}

	  // p: ID of current node
	  // low: left end of the range of node x (inclusive)
	  // high: right end of the range of node x (inclusive)
	  // A: original array
public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}
	int mid = (low + high) / 2;
	//cout << low << " " << high << endl;
	tree[p] = max(buildSegTreeRec(low, mid, leftChild(p), A), buildSegTreeRec(mid + 1, high, rightChild(p), A));

	return tree[p];
}


	  // find the partial sum between A[x...y], inclusive (0-based)
public:int get_max(int x, int y) {

	if (x < 0 || ENDINDEX < y)
		return -INT_MAX;

	return get_max1(STARTINDEX, ENDINDEX, x, y, 0);
}

	  // p: ID of current node in the segment tree
	  // [low, high]: range of current node
	  // [x, y]: query range
public:int get_max1(int low, int high, int x, int y, int p) {

	if (x <= low && high <= y)  // [x, y] contains [low, high]
		return tree[p];

	if (y < low || high < x)   // [x, y] doesn't overlap [low, high]
		return 0;

	int mid = (low + high) / 2;

	return max(get_max1(low, mid, x, y, leftChild(p)), get_max1(mid + 1, high, x, y, rightChild(p)));;
}

	  // add "val" at position "pos": A[pos] += val
public:void addValue(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, val, 0);
}

	  // p: ID of current node in the segment tree
	  // [low, high]: range of current node
	  // pos: position to be modified
	  // val: the change to the specified position
public:void addValueRec(int low, int high, int pos, int val, int p) {
	if (low <= pos && pos <= high) {
		tree[p] = tree[p] + val;

		if (low != high) {
			int mid = (low + high) / 2;
			addValueRec(low, mid, pos, val, leftChild(p));
			addValueRec(mid + 1, high, pos, val, rightChild(p));
		}
	}
}
public:void print()
{
	print_vector(tree);
}
};
class FenwickTree {
private:
	vi ft; // recall that vi is: typedef vector<int> vi;
public:
	FenwickTree(int n)
	{
		ft.assign(n + 1, 0);
	} // init n + 1 zeroes
	int rsq(int b)
	{ // returns RSQ(1, b)
		int sum = 0;
		for (; b; b -= b & (-b))
			sum += ft[b];
		return sum;
	} // note: LSOne(S) (S & (-S))
	int rsq(int a, int b)
	{ // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v)
	{ // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += k &= (-k))
			ft[k] += v;
	}
	void print()
	{
		print_vector(ft);
	}
};
struct Graph
{
	int V, E;
	vector<pair<int, pii>> edges; // node a, b, weight

	//constructor
	Graph(int a, int b)
	{
		V = a;
		E = b;
	}

	void addEdge(int a, int b, int w)
	{
		edges.push_back({ w,{a,b} });
	}

	// add function generate adj based on vertices and edges.

	vector<int> link, size;

	int find(int a) // return the root for node a
	{
		if (a == link[a])
			return a;
		return link[a] = find(link[a]);
	}

	bool same(int a, int b) // check if node a and b has the same root
	{
		return find(a) == find(b);
	}

	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (size[a] < size[b]) swap(a, b);
		size[a] += size[b]; //a always bigger than b, move subtree b under a
		link[b] = a;
	}

	void sort_edges()
	{
		sort(edges.begin(), edges.end());
	}

	ll kruskalMST()
	{
		sort_edges();
		//initialize for MST
		link.resize(V);
		size.resize(V);

		for (int i = 0; i < V; i++)
		{
			link[i] = i;
			size[i] = 1;
		}
		ll sum = 0;
		int count = 0;
		F0R(i, E)
		{
			int start = edges[i].s.f;
			int end = edges[i].s.s;
			if (!same(start, end))
			{
				unite(start, end);
				sum += edges[i].f;
				count++;
			}
		}
		if (count != V - 1)return -inf;
		return sum;
	}
};

/*
void dfs(int index, int dist)
{
	Visited[index] = dist;
	trav(x, adjacency[index])
	{
		if (Visited[x.f] == 0 || minimum(x.second, dist) > Visited[x.first])
			dfs(x.f, maximum(Visited[x.first], minimum(dist, x.s)));
	}
}

void bfs(int i)
{
	list<int>todo;
	todo.pb(i);
	Visited[i] = INT_MAX;
	while (!todo.empty())
	{
		int index = todo.back();
		todo.pop_back();
		trav(x, adjacency[index])
		{
			if (Visited[x.first] != 0)
				continue;
			Visited[x.f] = minimum(x.s, Visited[index]);
			todo.push_front(x.f);
		}
	}
}
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is index while .f is weight
		pii temp = todo.top();
		int index = temp.second;
		todo.pop();
		if (finalized[index])continue;
		finalized[index] = 1;
		trav(x, adjacency[index])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[index])
			{
				dist[x.first] = x.second + dist[index];
				parents[x.f] = index;
				todo.push(mp(-dist[x.first], x.f));
			}
		}
	}
}
void make_adjacency()
{
	F0R(i, NN)
	{
		a = i / N;
		b = i % N;
		if (a > 0)
		{
			adjacency[i].pb(mp(i - N, abs(positions[a][b] - positions[a - 1][b])));
		}
		if (a < N - 1)
		{
			adjacency[i].pb(mp(i + N, abs(positions[a][b] - positions[a + 1][b])));
		}
		if (b > 0)
		{
			adjacency[i].pb(mp(i - 1, abs(positions[a][b] - positions[a][b - 1])));
		}
		if (b < N - 1)
		{
			adjacency[i].pb(mp(i + 1, abs(positions[a][b] - positions[a][b + 1])));
		}
	}
}
*/
//end of preprogrammed methods
int a, b, c;
ifstream fin("bbreeds.in");
ofstream fout("bbreeds.out");
int N;
vi types;
vector<vi>DP;//DP[i][j][k] means that you have completed the types from 1 - i-1 and you have j Hs and k Gs
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string d;
	fin >> d;
	N = d.size();
	types.rsz(N);
	F0R(i, N)if (d[i] == '(')types[i] = 1; else types[i] = -1;
}
int main()
{
	init();

	//print_vector(types);


	//These 5 lines are an attempt to save space
	vi sums;
	sums.rsz(N);
	sums[0] = 0;
	F0R(i, N - 1)sums[i + 1] = sums[i] + types[i];
	//print_vector(sums);

	DP.rsz(N);
	F0R(i, N)
	{
		DP[i].rsz(N);
	}
	F0R(i, N)
	{
		F0R(j, N)
		{
			DP[N - 1][i] = 0;
		}
	}
	DP[N - 1][1] = 1;
	DP[N - 1][0] = 1;
	R0F(i, N - 1)
	{
		R0F(j, N)
		{
			int k = sums[i] - j;
			if (k < 0)cont;
			if ((i + j + k) % 2)cont;
			if (types[i] == 1)
			{
				a = 0;
				b = 0;
				if (j < DP[i].size() - 1)
					a = DP[i + 1][j + 1];
				if (k < DP[i].size() - 1)
					b = DP[i + 1][j];
				DP[i][j] = (a + b) % 2012;
			}
			else
			{
				a = 0;
				b = 0;
				if (j > 0)
					a = DP[i + 1][j - 1];
				if (k > 0)
					b = DP[i + 1][j];
				DP[i][j] = (a + b) % 2012;
			}
		}
	}
	//print_vector(DP);
	fout << DP[0][0] << endl;
}