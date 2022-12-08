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

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 3;
const ll bits = 25;

vector<int>ans(maxn);





struct CentroidDecomposition {
	// Time complexity is :O(NlogN)
	int n;
	vector<set<int>> tree;
	vector<set<int>> cdTree;
	int centroidRoot = -1;
	vector<int>subSiz, par;

	void init(int siz, vp &edges) {
		// Everything is 1-based.
		n = siz;
		tree.resize(n + 1);
		cdTree.resize(n + 1);
		subSiz.resize(n + 1);
		par.resize(n + 1);

		for (auto &x : edges) {
			tree[x.F].insert(x.S);
			tree[x.S].insert(x.F);
		}
		calcSubSize(1, 0);
	}

	void calcSubSize(int root, int p) {
		int curr = 1;
		par[root] = p;
		for (auto &x : tree[root]) {
			if (x != p) {
				calcSubSize(x, root);
				curr += subSiz[x];
			}
		}
		subSiz[root] = curr;
	}

	int findCentriod(int currNode) {
		int totalSize = subSiz[currNode];
		int req = totalSize / 2;
		int prev = currNode;
		while (1) {
			prev = currNode;
			for (auto &x : tree[currNode]) {
				if (x == par[currNode])
					continue;
				if (subSiz[x] > req) {
					currNode = x; break;
				}
			}
			if (prev == currNode)break;

		}
		return currNode;
	}

	int decompose(int st) {
		int now = findCentriod(st);
		if (centroidRoot == -1)centroidRoot = now;

		for (auto &x : tree[now]) {
			tree[x].erase(now);
			calcSubSize(x, 0);
			cdTree[now].insert(decompose(x));
		}
		return now;

	}
};


void fillAns(int node, int p, CentroidDecomposition &mal) {
	// Use this to procecss answer for all centroids.
	if (p == -1)ans[node] = 0;
	for (auto &x : mal.cdTree[node]) {
		if (x != p) {
			ans[x] = ans[node] + 1;
			fillAns(x, node, mal);
		}
	}
}

void solve() {
	int n; cin >> n;
	vp v(n - 1);
	for (auto &x : v)cin >> x.F >> x.S;
	for (int i = 0; i <= n; i++)ans[i] = 0;
	CentroidDecomposition cd =  CentroidDecomposition();
	cd.init(n, v);
	// decompose with any node, use 'centroidRoot' for future uses.
	cd.decompose(1);

	fillAns(cd.centroidRoot, -1, cd);

	for (int i = 1; i <= n; i++) {
		char smit = ans[i] + 'A';
		cout << smit << " ";
	}
	cout << endl;

}




bool TestCase1 = 0;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll t;
	t = 1;
	int cnt = 1;
	if (TestCase1) {
		cin >> t;
	}
	while (t--) {
		//	cout << "Case #" << cnt << ": ";
		cnt++;
		solve();
	}
	return 0;
}