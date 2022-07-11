/*
Qg3
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
#define endl "\n"



/*


*/

const ll maxn = 3e5 + 6;
const ll mod = 1e9 + 7;


struct Tree {
	int n;
	int bits;
	vector<vector<int>>adj;
	vector<vector<int>>dp;
	vector<int> par, hei, siz;

	void init(int x) {
		n = x;
		adj.resize(n + 1);
		int curr = 1;
		int bitSize = 0;
		while (curr <= n) {
			curr *= 2;
			bitSize++;
		}
		bitSize += 1;
		bits = bitSize;
		dp.assign(bitSize, vector<int>(n + 1, 1));
		par.resize(n + 1);
		hei.resize(n + 1);
		siz.resize(n + 1);
	}
	void edge(int a, int b) {
		adj[a].pb(b);
		adj[b].pb(a);
	}
	void dfs(int currNode, int parent) {
		par[currNode] = parent;
		hei[currNode] = hei[parent] + 1;
		int currSize = 1;
		for (auto &x : adj[currNode]) {
			if (x != parent) {
				dfs(x, currNode);
				currSize += siz[x];
			}
		}
		siz[currNode] = currSize;
	}

	void calcDp() {
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				par[i] = 1;
			}
			dp[0][i] = par[i];
		}
		for (int j = 1; j < bits; j++) {
			for (int i = 1; i <= n; i++) {
				dp[j][i] = dp[j - 1][dp[j - 1][i]];
			}
		}
	}

	void doLCA() {
		dfs(1, 0);
		calcDp();
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
	bool check(int mid, int a, int b) {
		return getKthAns(a, mid) == getKthAns(b, mid);
	}
	int getLCA(int a, int b) {
		if (hei[a] > hei[b])
			swap(a, b);
		int lca = hei[b] - hei[a];
		b = getKthAns(b, hei[b] - hei[a]);
		ll l = 0, r = n;
		while (r - l > 1) {
			ll mid = (r + l) / 2;
			if (check(mid, a, b)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (check(l, a, b)) {
			lca = getKthAns(a, l);
		}
		else {
			lca = getKthAns(b, r);
		}
		return lca;
	}

	int calcDist(int a, int b) {
		if (hei[a] > hei[b])swap(a, b);
		ll dist = hei[b] - hei[a];
		b = getKthAns(b, hei[b] - hei[a]);
		ll l = 0, r = n;
		while (r - l > 1) {
			ll mid = (r + l) / 2;
			if (check(mid, a, b)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (check(l, a, b)) {
			dist += (2 * l);
		}
		else {
			dist += r * 2;
		}
		return dist;
	}
};




int main() {

	return 0;
}