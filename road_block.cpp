
#include<iostream>
#include<algorithm>
#include<ctime>
#include<array>
#include<fstream>
#include <chrono>
#include<istream>
#include <queue> 
#include<climits>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<vector>


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
#define inf 1000000007
#define endl '\n'
#define cont continue


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
double maximum(double x, double y)
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
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s << endl;
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
void print_vector(vector<vector<pair<pii, int>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
	cout << endl;
}
void print_vector(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
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
void print_set(set<vi>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		print_vector(*i);
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
void print_map(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_set(i->second);
	}
}
void print_map(map<string, vector<bool>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<char, vi> m)
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
void print_map(map<int, pii> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s.f << " " << i->second.s << endl;
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
bool asd(pii x, pii y)
{
	if (x.second == y.s)
		return x.first < y.first;
	return x.second > y.second;
}
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
{
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);
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
				todo.push(mp(dist[x.first], x.f));
			}
		}
	}
}
*/
//end of preprogrammed methods
ifstream fin("rblock.in");
ofstream fout("rblock.out");
int N, M;
vector<vpi>adjacency;
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fin >> N >> M;
	adjacency.rsz(N);
	int a, b, c;
	F0R(i, M)
	{
		fin >> a >> b >> c;
		a--; b--;
		adjacency[a].pb(mp(b, c));
		adjacency[b].pb(mp(a, c));
	}
}
vi dist;
vi parents;
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is index while .f is weight
		pii temp = todo.top();
		int index = temp.second;
		todo.pop();
		if (finalized[index])continue;
		finalized[i] = 1;
		trav(x, adjacency[index])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[index])
			{
				dist[x.first] = x.second + dist[index];
				parents[x.f] = index;
				todo.push(mp(dist[x.first], x.f));
			}
		}
	}
}
int main()
{
	init();

	//print_vector(adjacency);
	dist.rsz(N, INT_MAX);
	dist[N - 1] = 0;
	parents.rsz(N, 0);
	parents[N - 1] = -1;
	dijkstra(N - 1);

	//print_vector(dist);
	//print_vector(parents);
	int start = dist[0];
	int max = -INT_MAX;
	list<pii>todo;
	int pos = 0;
	while (parents[pos] != -1)
	{
		todo.pb(mp(pos, parents[pos]));
		pos = parents[pos];
	}
	while (!todo.empty())
	{
		pii a = todo.back(); todo.pop_back();
		trav(x, adjacency[a.f])
		{
			if (x.f == a.s)x.s *= 2;
		}
		trav(x, adjacency[a.s])
		{
			if (x.f == a.f)x.s *= 2;
		}
		dist.rsz(0);
		dist.rsz(N, INT_MAX);
		dist[N - 1] = 0;
		dijkstra(N - 1);
		if (dist[0] > max)max = dist[0];
		trav(x, adjacency[a.f])
		{
			if (x.f == a.s)x.s /= 2;
		}
		trav(x, adjacency[a.s])
		{
			if (x.f == a.f)x.s /= 2;
		}
	}
	fout << max - start << endl;
}