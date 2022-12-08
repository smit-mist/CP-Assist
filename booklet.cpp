
/*-----Template Begin-----*/
//g++ -Wall -Wextra -Wshadow -std=c++17 a.cpp -o a.exe
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace std::chrono;
// using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vp vector<pi>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define sz(x) ((ll)((x).size()))
#define LLMAX LLONG_MAX
#define debug2(x,y) cout<<"Debug "<<#x<<" -> "<< x<<" | "<<#y<<" -> "<<y <<endl;
#define debug(x) cout<<"Debug " << #x<<" -> "<< x << endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define REAL(n) fixed << setprecision((n))
#define endl "\n";
// template<typename T>
// using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class key, class value, class cmp = less<key>>
// using ord_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(ind) returns iterator to element at ind starting from 0
// order_of_key(val) returns index of element having value = val starting from 0
const ll maxn = 1e5 + 7; const ll mod = 1e9 + 7;
void solve() {}
bool TestCase1 = 1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll t; t = 1;
	if (TestCase1) {cin >> t;}
	while (t--)solve();
	return 0;
}
/*-----Template End-----*/

/*-----Segment Tree Start-----*/
struct Item {ll x;};
struct segtree {
	// Ending of the range is non inclusive, and starting is inclusive :)
	// Update index must be 0 based
	vector<Item>values;
	ll size = 1; Item NEUTRAL = {0};
	Item merge(Item a, Item b) {
		Item c; c.x = a.x; c.x += b.x;
		return c;
	}
	Item single(ll x) {
		Item c; c.x = x;
		return c;
	}
	void init(ll n) {
		while (size < n)size *= 2;
		values.assign(2 * size, NEUTRAL);
	}
	void build(vll &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (ll)a.size())
				values[x] = single(a[lx]);
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}
	void build(vll &a) {
		build(a, 0, 0, size);
	}
	void set(int i, ll v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx == i)
				values[x] = single(v);
			return;
		}
		if (lx > i)return;
		if (rx < i)return;
		int mid = (rx + lx) / 2;
		set(i, v, 2 * x + 1, lx, mid);
		set(i, v, 2 * x + 2, mid, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}
	void set(int i, ll v) {
		set(i, v, 0, 0, size);
	}
	Item calc(int l, int r, int x, int lx, int rx) {
		if (rx <= r && lx >= l) {
			return values[x];
		}
		if (rx - lx == 1) {
			if (lx >= l && lx < r)return values[lx];
			return NEUTRAL;
		}
		if (rx <= l)return NEUTRAL;
		if (lx >= r)return NEUTRAL;
		int mid = (rx + lx) / 2;
		return merge(calc(l, r, 2 * x + 1, lx, mid), calc(l, r, 2 * x + 2, mid, rx));
	}
	Item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};
/*-----Segment Tree End-----*/

/*-----String Hashing Start-----*/
string s; int n; // string and its length.
const ll p = 31; // might need to change based on string, prime.
// const ll mod = 1e9 + 7;
// const ll maxn = 1e5 + 9;
ll p_pow[maxn];
ll h[maxn];
void compute_hash() {
	p_pow[0] = 1LL;
	for (int i = 1; i <= n; i++) {
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
	h[0] = 0;
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
	}// don't mess with this function
}
ll get_hash(int a, int b) {
	// a and b both are zero based
	ll here = ((h[b + 1] - h[a]) % mod + mod) % mod;
	here = (p_pow[n - 1 - a] % mod * here % mod) % mod;
	return here;
}
/*-----String Hashing End-----*/

/*-----Random Start-----*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
/*-----Random End-----*/

/*-----Tree utils start-----*/
struct Tree {
	int n;
	int bits;
	vector<vector<int>>adj;
	vector<vector<int>>dp;
	vector<int> par, hei, siz;
	void init(int x) {
		n = x; adj.resize(n + 1);
		int curr = 1, bitSize = 0;
		while (curr <= n) {curr *= 2; bitSize++;}
		bitSize += 1; bits = bitSize;
		dp.assign(bitSize, vector<int>(n + 1, 1));
		par.resize(n + 1);	hei.resize(n + 1); siz.resize(n + 1);
	}
	void edge(int a, int b) {
		adj[a].pb(b); adj[b].pb(a);
	}
	void dfs(int currNode, int parent) {
		par[currNode] = parent;
		hei[currNode] = hei[parent] + 1;
		int currSize = 1;
		for (auto &x : adj[currNode]) {
			if (x != parent) {dfs(x, currNode); currSize += siz[x];}
		}
		siz[currNode] = currSize;
	}
	void calcDp() {
		for (int i = 1; i <= n; i++) {
			if (i == 1) par[i] = 1;
			dp[0][i] = par[i];
		}
		for (int j = 1; j < bits; j++) {
			for (int i = 1; i <= n; i++) {
				dp[j][i] = dp[j - 1][dp[j - 1][i]];
			}
		}
	}
	void doLCA() {
		dfs(1, 0);	calcDp();
	}
	int getKthAns(int node, int k) {
		if (k == 0)return node;
		for (int i = bits - 1; i > -1; i--) {
			if ((k & (1 << i))) {
				k -= (1 << i);
				node = dp[i][node];
			}
		}
		return node;
	}
	int getLCA(int a, int b) {
		if (hei[a] > hei[b])
			swap(a, b);
		int lca = hei[b] - hei[a];
		b = getKthAns(b, hei[b] - hei[a]);
		if (a == b)return a;
		for (int j = bits - 1; j > -1; j--) {
			if (dp[j][a] != dp[j][b]) {
				a = dp[j][a];	b = dp[j][b];
			}
		}
		return dp[0][a];
	}
	int calcDist(int a, int b) {
		if (hei[a] > hei[b])swap(a, b);
		ll dist = hei[b] - hei[a];
		b = getKthAns(b, hei[b] - hei[a]);
		ll comPar = getLCA(a, b);
		dist += 2 * abs(hei[comPar] - hei[a]);
		return dist;
	}
};
/*-----Tree utils end-----*/

/*-----fenwick start-----*/
struct FenwickTree {
	// Never access 0 index in fenwick tree.
	// Don't touch anything.
	ll n; vll bst;
	void init(ll x) {
		n = x; bst.assign(n, 0);
	}
	ll func(ll k) {
		ll s = 0;
		while (k >= 1 && k < n) {
			s += bst[k]; k -= (k & (-k));
		}
		return s;
	}
	void add(ll k, ll x) {
		while (k < n) {
			bst[k] += x; k += (k & (-k));
		}
	}
};
/*-----fenwick end-----*/

/*-----articulation start-----*/
const int N = 1e5 + 5;
int n; int timer;
int tinN[N], low[N];
bool vis[N], isArticulation[N];
vector<int> g[N]; // g is adjacency list.
void dfs(int u, int par) {
	vis[u] = 1;
	tinN[u] = low[u] = ++timer;
	int children = 0;
	for (auto &it : g[u])
	{
		if (it == par)
			continue;
		if (vis[it])
			low[u] = min(low[u], tinN[it]);
		else
		{
			dfs(it, u);
			low[u] = min(low[u], low[it]);
			if (low[it] >= tinN[u] && par != -1)
				isArticulation[u] = 1;
			children++;
		}
	}
	if (par == -1 && children > 1)
		isArticulation[u] = 1;
}
void articulationPoints() {
	timer = 0;
	memset(vis, 0, sizeof(vis));
	memset(isArticulation, 0, sizeof(isArticulation));
	memset(tinN, -1, sizeof(tinN)); memset(low, -1, sizeof(low));
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i, -1);
	}
}
/*-----articulation end-----*/

/*-----bridge start-----*/
const int M = 1e6;// number of edges.
int tim = 0;
int u[N], v[N], vis[N];
int tinN[N], tout[N], isBridge[M], minAncestor[N];
vector<pair<int, int> > g[N]; //vertex, index of edge
void dfs(int k, int par) {
	vis[k] = 1; tinN[k] = ++tim;
	minAncestor[k] = tinN[k];
	for (auto it : g[k]) {
		if (it.first == par)
			continue;
		if (vis[it.first]) {
			minAncestor[k] = min(minAncestor[k], tinN[it.first]);
			continue;
		}
		dfs(it.first, k);
		minAncestor[k] = min(minAncestor[k], minAncestor[it.first]);
		if (minAncestor[it.first] > tinN[k])
			isBridge[it.second] = 1;
	}
	tout[k] = tim;
}
/*-----bridge end-----*/

/*-----centriod decompo start-----*/
int nodes = 0;
int subtree[N], parentcentroid[N];
set<int> g[N];
void dfs(int u, int par) {
	nodes++;
	subtree[u] = 1;
	for (auto &it : g[u]) {
		if (it == par)
			continue;
		dfs(it, u);
		subtree[u] += subtree[it];
	}
}
int centroid(int u, int par) {
	for (auto &it : g[u]) {
		if (it == par)
			continue;
		if (subtree[u] > (nodes >> 1))
			return centroid(u, it);
	}
	return u;
}
void decompose(int u, int par) {
	nodes = 0;
	dfs(u, u);
	int node = centroid(u, u);
	parentcentroid[node] = par;
	for (auto &it : g[node]) {
		g[it].erase(node);
		decompose(it, node);
	}
}
/*-----centriod decompo end-----*/

/*-----HLD start-----*/
int n;
vi adj[maxn];
int nextId = 0;
vi siz(maxn), par(maxn), depth(maxn), heavy(maxn);
segtree tree; // segment tree based on queries.
vi label(maxn), chain(maxn);
const int bits = 20; // might need change.
// Create the tree class such that lca, getKth can be done.
void dfs_size(int curr, int prev, int d) {
	par[curr] = prev; depth[curr] = d;
	int subSize = 1;
	int bigChild = -1, bigSize = -1;
	for (auto &x : adj[curr]) {
		if (x != prev) {
			dfs_size(x, curr, d + 1);
			if (bigSize < siz[x]) {
				bigSize = siz[x];
				bigChild = x;
			}
			subSize += siz[x];
		}
	}
	siz[curr] = subSize;
	heavy[curr] = bigChild;
}
void dfs_label(vector<int>&v, int curr, int prev) {
	label[curr] = nextId; nextId++;
	// 'v' is assumed to be in zero based indexing.
	tree.set(label[curr], v[curr - 1]);
	if (heavy[curr] != -1) {
		dfs_label(v, heavy[curr], curr);
	}
	for (auto &x : adj[curr]) {
		if (x != prev && x != heavy[curr]) {
			dfs_label(v, x, curr);
		}
	}
}
void dfs_chain(int curr, int prev) {
	if (heavy[curr] != -1) {
		chain[heavy[curr]] = chain[curr];
	}
	for (auto &x : adj[curr]) {
		if (x != prev) {
			dfs_chain(x, curr);
		}
	}
}
long long query_chain(int curr, int prev) {
	long long ans = 0;
	while (depth[curr] > depth[prev]) {
		int top = chain[curr];
		if (depth[top] <= depth[prev]) {
			int diff = depth[prev] - depth[top];
			top = getKthAns(curr, diff - 1);
		}
		// change here
		ans = (ans ^ tree.calc(label[top], label[curr] + 1).x);
		curr = par[top];
	}
	return ans;
}
long long handle_query(int fir, int sec) {
	int lc = getLCA(fir, sec);
	// Change here.
	long long ans = (query_chain(fir, lc) ^ handle_query(sec, lc));
	ans = (ans ^ tree.calc(label[lc], label[lc + 1]).x);
	return ans;
}
/*-----HLD end-----*/

/*-----sack on tree start-----*/
//Logic: https://codeforces.com/blog/entry/44351
int col[N], cnt[N], f[N], subtree[N], big[N], ans[N];
vector<int> g[N];
multiset<int> active;
void getsz(int v, int p) {
	subtree[v] = 1;
	for (auto u : g[v]) {
		if (u == p)
			continue;
		getsz(u, v);
		subtree[v] += subtree[u];
	}
}

void add(int v, int p, int x) { //Function changes as per question,
	active.erase(cnt[col[v]]);
	f[cnt[col[v]]] -= col[v];
	cnt[col[v]] += x;
	active.insert(cnt[col[v]]);
	f[cnt[col[v]]] += col[v];
	for (auto u : g[v]) {
		if (u != p && !big[u])
			add(u, v, x);
	}
}
void computeans(int v) {
	int maxf = *(--active.end());
	ans[v] = f[maxf];
}
void dfs(int v, int p, int keep) {
	int mx = -1, bigChild = -1;
	for (auto u : g[v]) {
		if (u != p && subtree[u] > mx)
			mx = subtree[u], bigChild = u;
	}
	for (auto u : g[v]) {
		if (u != p && u != bigChild)
			dfs(u, v, 0); //Run DFS on small children and clear them
	}
	if (bigChild != -1) {
		dfs(bigChild, v, 1);
		big[bigChild] = 1;
	}
	add(v, p, 1);
	//Now we have the information of subtree of v
	computeans(v);
	if (bigChild != -1)
		big[bigChild] = 0;
	if (keep == 0)
		add(v, p, -1);
}
/*-----sack on tree end-----*/

/*-----bipartite matching start-----*/
//1 indexed Hopcroft-Karp Matching in O(E sqrtV)
struct Hopcroft_Karp {
	static const int inf = 1e9;
	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;
	Hopcroft_Karp(int n) :
		n(n), matchL(n + 1), matchR(n + 1), dist(n + 1), g(n + 1) {}
	void addEdge(int u, int v) {
		g[u].push_back(v);
	}
	bool bfs() {
		queue<int> q;
		for (int u = 1; u <= n; u++) {
			if (!matchL[u]) {
				dist[u] = 0;
				q.push(u);
			}
			else
				dist[u] = inf;
		}
		dist[0] = inf;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (dist[matchR[v]] == inf) {
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);
				}
			}
		}
		return (dist[0] != inf);
	}
	bool dfs(int u) {
		if (!u)
			return true;
		for (auto v : g[u]) {
			if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
				matchL[u] = v; matchR[v] = u;
				return true;
			}
		}
		dist[u] = inf;
		return false;
	}
	int max_matching() {
		int matching = 0;
		while (bfs()) {
			for (int u = 1; u <= n; u++) {
				if (!matchL[u])if (dfs(u))matching++;
			}
		}
		return matching;
	}
};
/*-----bipartite matching end-----*/

/*-----negative cycle directed start-----*/
// SPFA: faster than bellman ford.
int n, m;
int dist[N], cnt[N];
bool inqueue[N];
vector<pair<int, int> > g[N];
// Returns true if there is a negative cycle
bool negativeCycle() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dist[i] = cnt[i] = 0;
		q.push(i), inqueue[i] = true;
	}
	while (!q.empty())	{
		int v = q.front();
		q.pop();
		inqueue[v] = false;
		for (auto &edge : g[v]) {
			int to = edge.first;
			int w = edge.second;
			if (dist[v] + w < dist[to]) {
				dist[to] = dist[v] + w;
				dist[to] = max(dist[to], INF);
				if (!inqueue[to]) {
					q.push(to);
					inqueue[to] = true;
					cnt[to]++;
					if (cnt[to] > n)
						return true;
				}
			}
		}
	}
	return false;
}
/*-----negative cycle directed end-----*/

/*-----subset enumeration-----*/
for (int s = m; ; s = (s - 1)&m) { // ... you can use s ...
	if (s == 0)  break;
}

/*-----scc kosaraju start-----*/
ll n;
vi adj[100001], Radj[100001];// Directed graph both tranposed and normal..
stack<int>order;// Order of ending of first dfs
vector<bool>vis(100001, 0);
vi scc;
void dfs(int start) {
	vis[start] = 1;
	for (auto x : adj[start]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
	order.push(start);
}
void Rdfs(int start) {
	vis[start] = 1;
	scc.pb(start);
	for (auto x : Radj[start]) {
		if (!vis[x]) {
			Rdfs(x);
		}
	}

}
// usage
// take input make adj, and radj.
for (int i = 1; i <= n; i++) {
	if (!vis[i])dfs(i);
}
// step - 1&2 complete
vector<vi>compo; // This will contain vector of every component..
for (int i = 1; i <= n; i++)vis[i] = 0;// Clearing vis ...
// Performing Rdfs in the order of stact...
while (!order.empty()) {
	int curr = order.top();
	order.pop();
	if (!vis[curr]) {
		scc.clear();
		Rdfs(curr);
		if (scc.size() > 0)
			compo.pb(scc);
	}
}
/*-----scc kosaraju end-----*/

/*-----bst with avl start-----*/
class Node {
public:
	int key;
	Node *left;
	Node *right;
	int height;
};
int height(Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
Node* newNode(int key) {
	Node* node = new Node();
	node->key = key;
	node->left = NULL; node->right = NULL;
	node->height = 1; // new node is initially
	// added at leaf
	return (node);
}
// Black-box from here.
Node *rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left),
	                height(y->right)) + 1;
	x->height = max(height(x->left),
	                height(x->right)) + 1;
	return x;
}
Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left),
	                height(x->right)) + 1;
	y->height = max(height(y->left),
	                height(y->right)) + 1;

	return y;
}
// Get Balance factor of node N
int getBalance(Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key) {
	if (node == NULL)
		return (newNode(key));
	if (goLeft(node->key, key))
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	node->height = 1 + max(height(node->left),
	                       height(node->right));
	int balance = getBalance(node);
	if (node->left && balance > 1 && goLeft(node->key, node->left->key))
		return rightRotate(node);
	if (node->right && balance < -1 && goLeft(node->key, node->right->key) == false)
		return leftRotate(node);
	if (node->left && balance > 1 && goLeft(node->key, node->left->key))	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (node->right && balance < -1 && goLeft(node->key, node->right->key) == false)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
/*-----bst with avl end-----*/

/*-----square root decompo start-----*/
const int SZ = sqrt(N);
struct sqrtDecomposition {
	int L, R; int col[SZ], contrib[SZ];	bool lazy = 0;
	int extra = 0; int sumBlock = 0; int lazyValue = 0;
	void init(int l, int r) {
		for (int i = l; i <= r; i++) {
			col[i - l] = a[i]; contrib[i] = 0;
		}
		L = l, R = r; extra = 0; sumBlock = 0; lazyValue = 0;
	}
	void semiUpdate(int l, int r, int val) {
		if (l > r)return;
		if (lazy) {
			for (int i = L; i <= R; i++) {
				contrib[i - L] += extra; col[i - L] = lazyValue;
			}
			lazy = 0; extra = 0;
		}
		for (int i = l; i <= r; i++) {
			sumBlock += abs(val - col[i - L]);
			contrib[i - L] += abs(val - col[i - L]); col[i - L] = val;
		}
	}
	void fullUpdate(int val) {
		if (lazy) {
			sumBlock += (abs(val - lazyValue) * (R - L + 1));
			extra += abs(val - lazyValue);
		}
		else {
			for (int i = L; i <= R; i++) {
				contrib[i - L] += abs(col[i - L] - val);
				sumBlock += abs(col[i - L] - val);	col[i - L] = val;
			}
		}
		lazy = 1;	lazyValue = val;
	}
	void update(int l, int r, int val) {
		if (l <= L && r >= R)
			fullUpdate(val);
		else
			semiUpdate(max(l, L), min(r, R), val);
	}
	int semiQuery(int l, int r) {
		if (l > r)return 0;
		if (lazy) {
			for (int i = L; i <= R; i++) {
				contrib[i - L] += extra;
				col[i - L] = lazyValue;
			}
			lazy = 0; extra = 0;
		}
		int answer = 0;
		for (int i = l; i <= r; i++)answer += contrib[i - L];
		return answer;
	}

	int fullQuery() {
		return sumBlock;
	}

	int query(int l, int r) {
		if (l <= L && r >= R)
			return fullQuery();
		else
			return semiQuery(max(l, L), min(r, R));
	}
};
sqrtDecomposition blocks[SZ + 5];
void init() {
	int blcks = n / SZ + 1;
	int curL = 1, curR = SZ;
	for (int i = 1; i <= blcks; i++) {
		curR = min(curR, n);
		blocks[i].init(curL, curR);
		curL += SZ;
		curR += SZ;
	}
}
void update(int l, int r, int x) {
	int left = (l - 1) / SZ  + 1;
	int right = (r - 1) / SZ + 1;
	for (int i = left; i <= right; i++)
		blocks[i].update(l, r, x);
}
int query(int l, int r) {
	int left = (l - 1) / SZ  + 1;
	int right = (r - 1) / SZ + 1;
	int answer = 0;
	for (int i = left; i <= right; i++)
		answer += blocks[i].query(l, r);
	return answer;
}
/*-----sqrt root decompo end-----*/

/*----treap start-----*/
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int getRand(int l, int r)
struct Treap {
	struct data {
		int priority, val, cnt; data *l, *r;
		data() {val = 0, cnt = 0, l = NULL, r = NULL;}
		data (int _val) {
			val = _val, cnt = 1;
			l = NULL, r = NULL;
			priority = getRand(1, 2e9);
		}
	};
	typedef struct data* node;
	node head;
	Treap(): head(0) {}
	int cnt(node cur)	{
		return cur ? cur->cnt : 0;
	}
	void updateCnt(node cur) {
		if (cur)cur->cnt = cnt(cur->l) + cnt(cur->r) + 1;
	}
	// Lazy prop
	void push(node cur) {;}
	void combine(node &cur, node l, node r) {
		if (!l) {cur = r; return;}
		if (!r) {cur = l; return;}
		//Merge Operations like in segment tree
	}
	//To reset other fields of cur except value and cnt
	void reset(node &cur) {
		if (!cur)return;
	}
	void operation(node &cur) {
		if (!cur)return;
		reset(cur);
		combine(cur, cur->l, cur);
		combine(cur, cur, cur->r);
	}
	void splitPos(node cur, node &l, node &r, int k, int add = 0) {
		if (!cur)return void(l = r = 0);
		push(cur); int idx = add + cnt(cur->l);
		if (idx <= k)splitPos(cur->r, cur->r, r, k, idx + 1), l = cur;
		else splitPos(cur->l, l, cur->l, k, add), r = cur;
		updateCnt(cur);
		operation(cur);
	}

	void split(node cur, node &l, node &r, int k) {
		if (!cur)return void(l = r = 0);
		push(cur);
		int idx = cur -> val;
		if (idx <= k)split(cur->r, cur->r, r, k), l = cur;
		else split(cur->l, l, cur->l, k), r = cur;
		updateCnt(cur);
		operation(cur);
	}
	void merge(node &cur, node l, node r) {
		push(l);
		push(r);
		if (!l || !r)
			cur = l ? l : r;
		else if (l->priority > r->priority)
			merge(l->r, l->r, r), cur = l;
		else
			merge(r->l, l, r->l), cur = r;
		updateCnt(cur);
		operation(cur);
	}
	void insert(int val) {
		if (!head) {
			head = new data(val);
			return;
		}
		node l, r, mid, mid2, rr;
		mid = new data(val);
		split(head, l, r, val - 1);
		merge(l, l, mid);
		split(r, mid2, rr, val);
		merge(head, l, rr);
	}
	void erase(int val) {
		node l, r, mid;
		split(head, l, r, val - 1);
		split(r, mid, r, val);
		merge(head, l, r);
	}
	// void inorder(node cur){
	// 	if (!cur)
	// 		return;
	// 	push(cur);	inorder(cur->l);
	// 	//cout << cur->val << " ";
	// 	inorder(cur->r);
	// }
	// void inorder(){
	// 	inorder(head);
	// 	// cout << endl;
	// }
	void clear(node cur) {
		if (!cur)return;
		clear(cur->l), clear(cur->r);
		delete cur;
	}
	void clear() {clear(head);}
	int find_by_order(int x) {
//1 indexed
		if (!x)	return -1;
		x--;
		node l, r, mid;
		splitPos(head, l, r, x - 1);
		splitPos(r, mid, r, 0);
		int ans = -1;
		if (cnt(mid) == 1)	ans = mid->val;
		merge(r, mid, r);
		merge(head, l, r);
		return ans;
	}
	int order_of_key(int val) {
		//1 indexed
		node l, r, mid;
		split(head, l, r, val - 1);
		split(r, mid, r, val);
		int ans = -1;
		if (cnt(mid) == 1)
			ans = 1 + cnt(l);
		merge(r, mid, r);
		merge(head, l, r);
		return ans;
	}
};

/*-----lazy segment tree start-----*/
const int maxn = 1e5 + 10;

template<typename NODE, typename UPDATE>
struct segtree {
	bool built = false, lazy[4 * maxn];
	NODE zero = NODE(), t[4 * maxn];
	UPDATE noop = UPDATE(), upds[4 * maxn];
	int32_t tl[4 * maxn], tr[4 * maxn];
	inline void pushdown(int32_t v)
	{
		if (lazy[v]) {
			apply(v * 2, upds[v]);
			apply(v * 2 + 1, upds[v]);
			lazy[v] = 0;
			upds[v] = noop;
		}
	}
	inline void apply(int32_t v, UPDATE &val)
	{
		if (tl[v] != tr[v]) {
			lazy[v] = 1;
			upds[v].combine(val, tl[v], tr[v]);
		}
		val.apply(t[v], tl[v], tr[v]);
	}
	template<typename T>
	void build(T &a, int32_t v, int32_t l, int32_t r) {
		tl[v] = l;
		tr[v] = r;
		if (l == r) {
			t[v] = a[l];
			return;
		} else {
			int32_t tm = (l + r) / 2;
			build(a, v * 2, l, tm);
			build(a, v * 2 + 1, tm + 1, r);
			t[v].merge(t[v * 2], t[v * 2 + 1]);
		}
	}
	NODE query(int32_t v, int l, int r) {
		if (l > tr[v] || r < tl[v])
			return zero;
		if (l <= tl[v] && tr[v] <= r) {
			return t[v];
		}
		pushdown(v);
		NODE a, b, ans;
		a = query(v * 2, l, r);
		b = query(v * 2 + 1, l, r);
		ans.merge(a, b);
		return ans;
	}
	void rupd(int32_t v, int l, int r, UPDATE &val)
	{
		if (l > tr[v] || r < tl[v])
			return;
		if (l <= tl[v] && tr[v] <= r)
		{
			apply(v, val);
			return;
		}
		pushdown(v);
		rupd(v * 2, l, r, val);
		rupd(v * 2 + 1, l, r, val);
		t[v].merge(t[v * 2], t[v * 2 + 1]);
	}

	int len = maxn;
	void clear() {
		fill(t, t + 4 * len, zero);
		fill(lazy, lazy + 4 * len, false);
		fill(upds, upds + 4 * len, noop);
		built = false;
	}
	template<typename T>
	void build(T &a) {
		build(a, 1, 0, len - 1);
		built = true;
	}
	NODE query(int l, int r) {
		if (!built)build(t);
		return query(1, l, r);
	}
	void rupd(int l, int r, UPDATE val) {
		if (!built)build(t);
		rupd(1, l, r, val);
	}
};

#define node node1
#define update update1
struct node {
	int v = 0;
	node() {}
	node(int val) {
		v = val;
	}
	void merge(node &l, node &r)
	{
		v = (l.v + r.v);
	}
};
struct update {
	int v = 0;
	// use more values to store more things.
	// use identity values to initialize.
	update() {}
	update(int val) {
		v = val;
	}
	//combine the current update with the other update.
	void combine(update &other, int32_t tl, int32_t tr) {
		v += other.v;
	}
	//store the current information in the node x.
	void apply(node &x, int32_t tl, int32_t tr) {
		x.v += (tr - tl + 1) * v;
	}
};
segtree<node, update> t;
#undef node
#undef update
/*-----lazy segment tree end-----*/

/*----- Sparse Table Ends ----*/
template<typename T>
struct SparseTable {
	vector<vector<T>> sptb;
	vector<int> logvals;
	int max_log;
	T neutral;
	function<T(const T& , const T& )> cmp;
	SparseTable() {}
	SparseTable(int max_n, T ini, decltype(cmp) opr) {
		neutral = ini;
		max_log = __lg(max_n + 2) + 3, cmp = opr;
		logvals = vector<int> (max_n + 20, 0);
		for (int i = 2; i < max_n + 10; i++) logvals[i] = logvals[i / 2] + 1;
		sptb = vector<vector<T>> (max_n + 10, vector<T> (max_log + 2, neutral));
	}
	void refresh(vector<T>& arr) {
		int n = arr.size(), lg = (__lg(n) + 2); assert(lg < max_log);
		for (int i = 0; i < n; i++) fill(sptb[i].begin(), sptb[i].begin() + lg, neutral);
		build(arr);
	}
	void build(vector<T>& arr) {
		int n = arr.size();
		for (int j = 0; j < max_log; j++) {
			int x = 1 << j;
			for (int i = 0; (i + x) <= n; i++) {
				if (j == 0) sptb[i][j] = arr[i];
				else sptb[i][j] = cmp(sptb[i][j - 1], sptb[i + (x / 2)][j - 1]);
			}
		}
	}
	T query(int l, int r) {
		T ans = neutral;
		for (int j = logvals[r - l + 1]; j > -1; j--) {
			int x = 1 << j;
			if (((r - l + 1)&x)) {ans = cmp(ans, sptb[l][j]), l += x;}
		}
		return ans;
	}
	T Iquery(int l, int r) {
		int j = logvals[r - l + 1], x = 1 << j;
		T ans = neutral;
		ans = cmp(ans, sptb[l][j]), ans = cmp(ans, sptb[r - (x) + 1][j]);
		return ans;
	}
};
template<typename T>
auto sp_cmp = [](const T &VAL1, const T &VAL2)->T {
	return max(VAL1, VAL2);
};
/*----- Sparse Table Ends ----*/

/*----- LCA O(1) Starts ----*/
class gNode {
public:
	// @val stores hieght and @idx stores the index of the node.
	int val = 0, idx = -1;
	gNode() {val = 0, idx = -1;}
	gNode(int _val, int _idx) {val = _val, idx = _idx;}
};
auto lca_cmp = [](const gNode &VAL1, const gNode &VAL2)->gNode {
	gNode ans;
	if (VAL1.val < VAL2.val) {ans.val = VAL1.val, ans.idx = VAL1.idx;}
	else {ans.val = VAL2.val, ans.idx = VAL2.idx;}
	return ans;
};
class LCA_const_time {
public:
	int n;
	vector<int> ind, vert;
	vector<gNode> eulerTour;
	SparseTable<gNode> sp;
	LCA_const_time(int _n, vector<int> tree[], int root) {
		n = _n;
		ind.resize(n);
		dfs(root, tree, -1, 0);
		sp = SparseTable<gNode> (sz(eulerTour), gNode(), lca_cmp);
		sp.build(eulerTour);
	}
	inline int lca(int u, int v) {
		return vert[sp.Iquery( min(ind[u], ind[v]), max(ind[u], ind[v]) ).idx];
	}
	inline int height(int u) {return eulerTour[ind[u]].val;}
private:
	void dfs(int root, vector<int> tree[], int par, int ht) {
		ind[root] = sz(eulerTour);
		eulerTour.pb(gNode(ht, root)), vert.pb(root);
		for (auto &ch : tree[root]) {
			if (ch != par) {
				dfs(ch, tree, root, ht + 1);
				eulerTour.pb(gNode(ht, root)), vert.pb(root);
			}
		}
	}
};
/*----- LCA O(1) Ends ----*/

/*----- Auxillary Tree Construction Starts ----*/
struct Aux_Tree {
	int n = 0, timer = 0, root = 1;
	vector<vector<int>> adj, adj_vt;
	vector<int> stm, etm;
	bool done_dfs = 0;
	Aux_Tree() {}
	Aux_Tree(int _n, int _root = 1) {
		n = _n, done_dfs = 0, timer = 0, root = _root;
		adj.assign(n + 5, vector<int> ()), stm.assign(n + 5, -1), etm.assign(n + 5, -1);
		adj_vt.assign(n + 5, vector<int> ());
	}
	void addEdge(int u, int v) {
		adj[u].pb(v), adj[v].pb(u);
	}
#warning // do call this function after adding all edges of input.
	void init() {
		this->dfs_timer(root, -1), done_dfs = 1;
	}
#warning // use any black-box LCA structure.
	int getLCA(int u, int v) {return u;}
	void dfs_timer(int u, int p) {
		stm[u] = ++timer;
		for (auto &v : adj[u]) if (v != p) dfs_timer(v, u);
		etm[u] = timer;
	}
	bool isAbove(int u, int v) {
		return (stm[u] <= stm[v] && etm[v] <= etm[u]);
	}
	void clean(vector<int> &vert) {
		for (auto &id : vert) adj_vt[id].clear();
	}
	bool cmp(int u, int v) {
		return stm[u] < stm[v];
	}
	int get_aux_root(vector<int> vert) {
		sort(all(vert), cmp);
		int k = sz(vert);
		for (int i = 0; i < k - 1; i++) {
			int new_vert = this->getLCA(vert[i], vert[i + 1]);
			vert.pb(new_vert);
		}
		sort(all(vert), cmp);
		vert.erase(unique(all(vert)), vert.end());
		this->clean(vert);
		vector<int> ver_st;
		ver_st.pb(vert[0]);
		for (int i = 1; i < sz(vert); i++) {
			int curr = vert[i];
			while (sz(ver_st) >= 2 && !isAbove(ver_st.back(), curr)) {
				// add edge.
				int par = ver_st[sz(ver_st) - 2];
				adj_vt[par].pb(ver_st.back());
				ver_st.pop_back();
			}
			ver_st.pb(curr);
		}
		while (sz(ver_st) >= 2) {
			// add edge.
			int par = ver_st[sz(ver_st) - 2];
			adj_vt[par].pb(ver_st.back());
			ver_st.pop_back();
		}
		assert(ver_st[0] == vert[0]);
		return ver_st[0];
	}
};
/*----- Auxillary Tree Construction Ends ----*/

/*----- General Geometry Starts ----*/
/*----- AshishGup Geometry Starts ----*/
struct point {
	ll x, y, idx;
};
struct Geometry {
	// Finds squared euclidean distance between two points
	ll dist(point &a, point &b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	// Checks if angle ABC is a right angle
	int isOrthogonal(point &a, point &b, point &c) {
		return (((b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y)) == 0);
	}
	// Checks if ABCD form a rectangle (in that order)
	int isRectangle(point &a, point &b, point &c, point &d) {
		return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
	}
	// Checks if ABCD form a rectangle, in any orientation
	int isRectangleAnyOrder(point &a, point &b, point &c, point &d) {
		return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) || isRectangle(c, a, b, d);
	}
	// Checks if ABCD form a square (in that order)
	int isSquare(point &a, point &b, point &c, point &d) {
		return ( isRectangle(a, b, c, d) && ( dist(a, b) == dist(b, c) ) );
	}
	// Checks if ABCD form a square, in any orientation
	int isSquareAnyOrder(point &a, point &b, point &c, point &d) {
		return isSquare(a, b, c, d) || isSquare(b, c, a, d) || isSquare(c, a, b, d);
	}
};
/*----- AshishGup Geometry Ends ----*/

/*----- CP Algo Geometry Starts ----*/

/*----- Intersection point of Lines Starts ----*/
struct pt1 {double x, y;};
struct line {double a, b, c;};
const double int_EPS = 1e-9;
double det(double a, double b, double c, double d) {
	return (a * d - b * c);
}
bool intersect(line m, line n, pt1 &res) {
	double zn = det(m.a, m.b, n.a, n.b);
	if (abs(zn) < int_EPS) return false;
	res.x = -det(m.c, m.b, n.c, n.b) / zn;
	res.y = -det(m.a, m.c, n.a, n.c) / zn;
	return true;
}
bool parallel(line m, line n) {
	return abs(det(m.a, m.b, n.a, n.b)) < int_EPS;
}
bool equivalent(line m, line n) {
	return abs(det(m.a, m.b, n.a, n.b)) < int_EPS
	       && abs(det(m.a, m.c, n.a, n.c)) < int_EPS
	       && abs(det(m.b, m.c, n.b, n.c)) < int_EPS;
}
/*----- Intersection point of Lines Ends ----*/

/*----- Check Two Segment Intersects Starts ----*/
struct pt2 {
	long long x, y;
	pt2() {}
	pt2(long long _x, long long _y) : x(_x), y(_y) {}
	pt2 operator-(const pt2 &p) const { return pt2(x - p.x, y - p.y); }
	long long cross(const pt2 &p) const { return x * p.y - y * p.x; }
	long long cross(const pt2 &a, const pt2 &b) const { return (a - *this).cross(b - *this); }
};
int sgn(const long long &x) { return x >= 0 ? x ? 1 : 0 : -1; }
bool inter1(long long a, long long b, long long c, long long d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}
bool check_inter(const pt2 &a, const pt2 &b, const pt2 &c, const pt2 &d) {
	if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
		return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
	return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
	       sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
/*----- Check Two Segment Intersects Ends ----*/

/*----- Finding area of simple polygon Starts ----*/
// Intended point struct.
//	struct point {
//		ll x, y, idx;
//	};
double area(const vector<point> &fig) {
	double res = 0;
	for (int i = 0; i < sz(fig); i++) {
		point p = i ? fig[i - 1] : fig.back();
		point q = fig[i];
		res += (p.x - q.x) * (p.y + q.y);
	}
	return fabsl(res) / 2;
}
/*----- Finding area of simple polygon Ends ----*/

/*----- CP Algo Geometry Ends ----*/

/*----- General Geometry Ends ----*/

/*----- Mo's Algorithm Starts ----*/
// TODO: add appropriate block size
int block_size;
struct Query {
	int l, r, idx;
	bool operator<(Query other) const {
		return mp(l / block_size, r) < mp(other.l / block_size, other.r);
	}
};
struct Mos_Algo {
	void remove(int idx);  // TODO: remove value at idx from data structure
	void add(int idx);     // TODO: add value at idx from data structure
	int get_answer();  // TODO: extract the current answer of the data structure
	vector<int> run_algo(vector<Query> queries) {
		vector<int> answers(queries.size());
		sort(queries.begin(), queries.end());
		// TODO: initialize data structure
		int cur_l = 0;
		int cur_r = -1;
		// invariant: data structure will always reflect the range [cur_l, cur_r]
		for (Query q : queries) {
			while (cur_l > q.l) {
				cur_l--; this->add(cur_l);
			}
			while (cur_r < q.r) {
				cur_r++; this->add(cur_r);
			}
			while (cur_l < q.l) {
				this->remove(cur_l); cur_l++;
			}
			while (cur_r > q.r) {
				this->remove(cur_r); cur_r--;
			}
			answers[q.idx] = get_answer();
		}
		return answers;
	}
};
/*----- Mo's Algorithm Ends ----*/

/*----- KMP Algorithm Starts ----*/
// what does pref_func[i] represent
// It represent longest prefix which is equivalent to suffix for the string from [0...i]
// lets say pref_func[i]=k --> s[0]+s[1]+s[2]...+s[k] = s[k-i+1]+s[k-i+2]+....+s[i]
// for e.g. "abcab" the pref_func[4] = 2, i.e. "ab"[0,1] = "ab"[3,4] (0-based indexing)
// REMEMBER --> that pref_func[i]<=i (for 0-based indexing)
// because obviously whole string prefix and suffix is equal to itself
// so it's considered INVALID
// Also called LPS array (Longest Prefix Function) array
vector<int> ComputePi(string pattern) {
	int n = pattern.size();
	vector<int> pref_func(n);
	pref_func[0] = 0; // length 1 is INVALID
	for (int i = 1; i < n; i++) {
		pref_func[0] = 0;
		int j = pref_func[i - 1];
		while (j > 0 && pattern[j] != pattern[i]) {
			j = pref_func[j - 1];
		}
		if (pattern[j] == pattern[i]) {
			pref_func[i] = j + 1;
		}
	}
	return pref_func;
}
// returns all starting index's where the substring of text matches whole pattern string
vector<int> KMP_Match(string text, string pattern) {
	int psz = pattern.size(), tsz = text.size();
	string temp = pattern + "$" + text;
	vector<int> pref_func = ComputePi(pattern), ans;
	for (int i = psz + 1; i <= psz + tsz; i++) {
		if (pref_func[i] == psz)
			ans.pb(i - 2 * psz);
	}
	return ans;
}
/*----- KMP Algorithm Ends ----*/

/*----- Z-function Starts ----*/
vector<int> z_function(string s) {
	int n = sz(s);
	vector<int> z_fun(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z_fun[i] = min (r - i + 1, z_fun[i - l]);
		while (i + z_fun[i] < n && s[z_fun[i]] == s[i + z_fun[i]])
			++z_fun[i];
		if (i + z_fun[i] - 1 > r)
			l = i, r = i + z_fun[i] - 1;
	}
	return z_fun;
}
/*----- Z-function Ends ----*/

/*----- Suffix-Array Starts ----*/
// Gives the sorted order of suffix substrings. O(N*log(N))
vector<int> suffix_array(string s) {
	int n = s.size(), N = n + 256;
	vector<int> sa(n), ra(n);
	for (int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
	for (int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);
		for (int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
		for (int i = 0; i < n; i++) cnt[ra[i]]++;
		for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
		int r = 0;
		for (int i = 1; i < n; i++) {
			if (ra[sa[i]] != ra[sa[i - 1]]) r++;
			else if (ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
			nra[sa[i]] = r;
		}
		ra = nra;
	}
	return sa;
}
// Computes LCP (Longest common prefix of
// suff_array[i]th substring and suff_array[i+1]th substring). O(N)
vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;
	for (int i = 0; i < n; i++) {
		if (k) k--;
		if (ra[i] == n - 1) {k = 0; continue;}
		int j = sa[ra[i] + 1];
		while (k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
		lcp[ra[i]] = k;
		if (ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
	}
	return lcp;
}
/*----- Suffix-Array Ends ----*/

/*----- Binary Exponentiation Starts ----*/
ll binpw(ll x, ll n, ll mod) {
	ll ans = 1;  x = x % mod;
	if (!x) return 0LL;
	for (; n > 0; n /= 2LL, x = (x * x) % mod)
		if (n % 2) ans = (ans * x) % mod;
	return ans;
}
/*----- Binary Exponentiation Ends ----*/

/*----- Matrix Multiplication Starts ----*/
vector<vector<ll>> matrix_mult(vector<vector<ll>> &m1, vector<vector<ll>> &m2, ll mod) {
	// m1: A * B, m2: B * C, ans: A * C
	int A = sz(m1), B = sz(m1[0]), C = sz(m2[0]);
	vector<vector<ll>> ans(A, vector<ll> (C));
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < B; k++) {
				ans[i][j] =  (ans[i][j] % mod + (m1[i][k] % mod * m2[k][j] % mod)) % mod;
			}
		}
	}
	return ans;
}
/*----- Matrix Multiplication Ends ----*/

/*----- Extended GCD Starts ----*/
int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {return false;}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}
// Eqn.: a*x0 + b*y0 = c;
// g = gcd(a, b)
// x = x0 + (b/g)
// y = y0 - (a/g)
/*----- Extended GCD Ends ----*/

/*----- Euler Totient Starts ----*/
// phi(n): number of integers between 1 and n inclusive, which are coprime to n.
// for prime numbers, phi(p) = p - 1
// for p^(k), phi(p^(k)) = p^(k) - p^(k-1)
// if a and b are co-prime, phi(a*b) = phi(a) * phi(b).
// for non-coprime a and b, phi(a*b) = (phi(a) * phi(b) * g / phi(g)); g = gcd(a, b).
// for n = (p1^a1)*(p2^a2)*....; phi(n) = n * (1 - (1/p1)) * (1 - (1/p2)) * ....;
// O( sqrt(N) )
int phi(int n) {
	int result = n;
	for (int i = 2; i * 1LL * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}
// O(N * log ( log(N) ) )
void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	for (int i = 0; i <= n; i++)
		phi[i] = i;
	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}
/*----- Euler Totient Ends ----*/

/*----- DSU with Rollback Starts ----*/

/*----- DSU with Rollback Ends ----*/

/*----- Math Equations Starts ----*/
// 1) Sum of divisors
// 	for N = p1^a1 * p2^a2 * ....;
// 	sum_of_div(N) = ((p1 ^ (a1 + 1) - 1) / (p1 - 1)) * ((p2 ^ (a2 + 1) - 1) / (p2 - 1)) * ....;

// 2) sum(0 to n, k) of (n-k)C(k) = Fib[n+1]
// 3) sum(0 to k, i) of (n+i)C(i) = sum(0 to k, i) of (n+i)C(n) = (n+k+1)C(k)
// 4) Stars and Bars put k bars between n stars = (n+k-1)C(k)
// 5)a+b=a⊕b+2(a&b): a+b=a∣b+a&b: a⊕b=a∣b−a&b
/*----- Math Equations Ends----*/

/*----- Stress Test Starts ----*/
// g++ trial1.cpp -o zzzzz_trial1
// g++ trial2.cpp -o zzzzz_trial2
// g++ z_generator.cpp -o zzzzz_trial3

// for((i=1; ;++i)); do
// 	./zzzzz_trial3 > zzzzz_random_Inp
// 	./zzzzz_trial1 < zzzzz_random_Inp > zzzzz_my_Out
// 	./zzzzz_trial2 < zzzzz_random_Inp > zzzzz_correct_Out
// 	diff -w zzzzz_my_Out zzzzz_correct_Out || break
// 	echo "Passed test: " $i
// done

// echo -e "\nWrong on the following test: "
// cat zzzzz_random_Inp
// echo "Code Answer: "
// cat zzzzz_my_Out
// echo "Correct Answer: "
// cat zzzzz_correct_Out
/*----- Stress Test Ends ----*/

