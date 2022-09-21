/*
*/
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
#define debug2(x,y) cout<<"Debug "<<#x<<" -> "<< x<<" | "<<#y<<" -> "<<y <<endl;
#define debug(x) cout<<"Debug " << #x<<" -> "<< x << endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define endl "\n";


/*
*/


const ll maxn = 1e5 + 6;
const ll mod = 998244353;


struct Item {
	ll x;
};
struct segtree
{
	// Ending of the range is non inclusive, and starting is inclusive :)
	// Update index must be 0 based
	// L must be 0 based
	// R must be 1 based
	vector<Item>values;
	ll size = 1;
	Item NEUTRAL = {0};
	Item merge(Item a, Item b) {
		Item c; c.x = a.x;
		//	if (b.x < a.x) {
		c.x += b.x;
		//	}
		return c;
	}
	Item single(ll x) {
		Item c;
		c.x = x;
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
	Item Qg3(int l, int r, int x, int lx, int rx) {
		if (rx <= r && lx >= l) {
			//	debug(values[x].x);
			return values[x];
		}
		if (rx - lx == 1) {
			if (lx >= l && lx < r)return values[lx];
			return NEUTRAL;
		}
		if (rx <= l)return NEUTRAL;
		if (lx >= r)return NEUTRAL;
		int mid = (rx + lx) / 2;
		return merge(Qg3(l, r, 2 * x + 1, lx, mid), Qg3(l, r, 2 * x + 2, mid, rx));
	}
	Item Qg3(int l, int r) {
		return Qg3(l, r, 0, 0, size);
	}


};

int n;
vi adj[maxn];
int nextId = 0;
vi siz(maxn), par(maxn), depth(maxn), heavy(maxn);

segtree tree;
vi label(maxn);

vi chain(maxn);

const int bits = 20;
int dp[bits][maxn];



/// Nothing to change here, just normal sparce table created and found the lca.

void calc_dp() {
	for (int i = 1; i <= n; i++) {
		dp[0][i] = par[i];
	}

	for (int i = 1; i < bits; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
}


int get_kth_ance(int node, int k) {
	if (k == 0) {
		return node;
	}
	for (int i = bits - 1; i > -1; i--) {
		int val = (1 << i);
		if ((val & k)) {
			node = dp[i][node];
		}
	}
	return node;
}

bool is_same_bin_search(int mid, int a, int b) {
	return (get_kth_ance(a, mid) == get_kth_ance(b, mid));
}

int get_lca(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}

	int diff = depth[b] - depth[a];
	b = get_kth_ance(b, diff);

	int l = 0, r = n;

	while (r - l > 1) {
		int mid = (l + (r - l) / 2);
		if (is_same_bin_search(mid, a, b)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if (is_same_bin_search(l, a, b)) {
		return get_kth_ance(a, l);
	}
	return get_kth_ance(b, l);
}

// lca, and get_kth part ends here.



void dfs_size(int curr, int prev, int d) {
	par[curr] = prev;
	depth[curr] = d;

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

			top = get_kth_ance(curr, diff - 1);
		}
		// change here

		ans = (ans ^ tree.Qg3(label[top], label[curr] + 1).x);
		curr = par[top];
	}

	return ans;
}

long long handle_query(int fir, int sec) {
	int lc = get_lca(fir, sec);

	// Change here.
	long long ans = (query_chain(fir, lc) ^ handle_query(sec, lc));
	ans = (ans ^ tree.Qg3(label[lc], label[lc + 1]).x);

	return ans;
}


void solve() {
	cin >> n;
	nextId = 1;
	tree.init(n + 5);
	for (int i = 0; i <= n; i++) {
		adj[i].clear();

		siz[i] = 0;
		par[i] = 0;
		depth[i] = 0;
		heavy[i] = 0;

		label[i] = 0;

		chain[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	par[1] = 1;

	dfs_size(1, 1, 0);
}


bool TestCase1 = 1;



int main() {
	ll t;
	t = 1;
	if (TestCase1) {
		cin >> t;
	}
	ll cnt = 1;
	while (t--) {
		solve();

	}
	return 0;
}
