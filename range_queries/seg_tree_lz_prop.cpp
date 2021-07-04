// Qg3
// //g++ -std=c++17 -O2 -Wall a.cpp -o test
// _()_
#include<bits/stdc++.h>
using namespace std;
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
#define For(i,a,b) for(ll i=a;i<b;i++)
#define debug2(x,y) cout<<"This side ----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"This side    ----> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define ciN cin
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)

/////////////
const ll max_val = 5e4 + 10;
const ll mod = 998244353;
const ll bits = 18;
ll caseNumber = 1;
#define endl "\n"
const ll maxn = 5e2 + 5;


////////////////////////////////////////////////////////////////
struct Item
{
	ll x;

};
struct segtree
{
	// Lazy Propagation for non-cummulative function (funciton in which order matters)
	// Ending of the range is non inclusive, and starting is inclusive :)
	// Update index must be 0 based
	// L must be 0 based
	// R must be 1 based
	vector<Item>values;
	ll size = 1;
	ll NO_OPS = 1e10 + 5;
	Item NEUTRAL = {0LL};

	Item operation(Item a, Item b) {
		if (b.x == NO_OPS)return a;
		return b;
	}

	void apply_operation(Item &a, Item b) {
		a = operation(a, b);
	}

	Item single(ll x) {
		// to make in Item from given X
		Item c;
		c.x = x;
		return c;
	}
	void propagate(int x, int lx, int rx) {
		// Lazy Propagation
		if (rx - lx == 1) {
			return;
		}
		apply_operation(values[2 * x + 1], values[x]);
		apply_operation(values[2 * x + 2], values[x]);
		values[x].x = NO_OPS;
	}
	void init(ll n) {
		// Ignition
		while (size < n)size *= 2;
		values.assign(2 * size, NEUTRAL);
	}
	void rangeAdd(int l, int r, ll v, int x, int lx, int rx) {
		// Range Modify
		propagate(x, lx, rx);
		if (rx <= r && lx >= l) {
			apply_operation(values[x], single(v));
			return;
		}
		if (rx - lx == 1) {
			if (lx >= l && lx < r)apply_operation(values[x], single(v));
			return;
		}
		if (rx <= l)return;
		if (lx >= r)return;
		int mid = (rx + lx) / 2;
		rangeAdd(l, r, v, 2 * x + 1, lx, mid);
		rangeAdd(l, r, v, 2 * x + 2, mid, rx);

	}
	void rangeAdd(int l, int r, ll v) {
		rangeAdd(l, r, v, 0, 0, size);
	}
	Item get(int ind, int x, int lx, int rx) {
		// get values at index ind
		propagate(x, lx, rx);
		if (rx - lx == 1) {
			return values[x];
		}
		if (ind >= rx)return NEUTRAL;
		if (ind < lx)return NEUTRAL;
		int mid = (rx + lx) / 2;
		if (ind < mid) {
			return get(ind, 2 * x + 1, lx, mid);
		}
		return get(ind, 2 * x + 2, mid, rx);
	}
	Item get(int ind) {
		return get(ind, 0, 0, size);
	}


};
void solve() {
	ll n, m; cin >> n >> m;
	segtree tree;
	tree.init(n + 1);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x == 1) {
			int l, r; cin >> l >> r;
			ll v; cin >> v;
			tree.rangeAdd(l, r, v);
		}
		else {
			int ind; cin >> ind;
			cout << tree.get(ind).x << endl;
		}
	}
}
/*


*/

bool TestCase1 = 0;
bool isGoogles = 0;



//////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	t = 1;



	if (TestCase1) {
		cin >> t;
	}
	while (t--) {
		solve();

	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH

*/