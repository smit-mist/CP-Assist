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
const ll maxn = 1e3 + 3;
const ll max_val = 5e4 + 10;
const ll mod = 1e9 + 7;
const ll bits = 18;
ll caseNumber = 1;
#define endl "\n"
ll mult(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{
	return ((a % mod) + (b % mod)) % mod;
}
////////////////////////////////////////////////////////////////

struct segtree
{
	ll NEUTRAL = LLONG_MAX;
	ll NO_OPERATION = LLONG_MAX - 1;
	vll ops, val;
	ll size = 1LL;
	void propagate(int x, int lx, int rx) {
		if (rx - lx == 1)return;
		apply_modify_op(val[2 * x + 1], ops[x]);
		apply_modify_op(ops[2 * x + 1], ops[x]);
		apply_modify_op(val[2 * x + 2], ops[x]);

		apply_modify_op(ops[2 * x + 2], ops[x]);
		ops[x] = NO_OPERATION;

	}
	ll modify_op(ll a, ll b) {
		if (b == NO_OPERATION)return a;
		return b;
		// this is the modify function when we modify a range

	}
	ll calc_op(ll a, ll b) {
		// this is the function to get the answer for a range
		return min(a, b);
	}
	void apply_modify_op(ll &a, ll b) {
		a = modify_op(a, b);
	}

	void init(ll n) {
		size = 1;
		while (size < n)size *= 2;
		ops.assign(2 * size, 0LL);
		val.assign(2 * size, 0LL);
	}

	void modify(int l, int r, ll v, int x, int lx, int rx) {
		propagate(x, lx, rx);
		if (lx >= r || l >= rx)return;

		if (lx >= l && rx <= r) {
			ll len = rx - lx;
			ops[x] = modify_op(ops[x], v); // length one because we will add length when calculate it.
			val[x] = modify_op(val[x], v);
			return;
		}
		if (rx - lx == 1)return;
		int mid = (lx + rx) / 2;
		modify(l, r, v, 2 * x + 1, lx, mid);
		modify(l, r, v, 2 * x + 2, mid, rx);
		val[x] = calc_op(val[2 * x + 1], val[2 * x + 2]);
		ll len = rx - lx;
		apply_modify_op(val[x], ops[x]);
	}
	void modify(int l, int r, ll v) {
		modify(l, r, v, 0, 0, size);
	}
	ll calc(int l, int r, int x, int lx, int rx) {
		propagate(x, lx, rx);

		if (lx >= r || l >= rx)return NEUTRAL;
		if (lx >= l && rx <= r) {
			return val[x];
		}
		if (rx - lx == 1)NEUTRAL;

		int mid = (lx + rx) / 2;
		auto lef = calc(l, r, 2 * x + 1, lx, mid);
		auto righ = calc(l, r, 2 * x + 2, mid, rx);
		auto res = calc_op(lef, righ);
		apply_modify_op(res, ops[x]);
		return res;
	}
	ll calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};

void solve() {

	int n, m; cin >> n >> m;
	segtree tree;
	tree.init(n);

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x == 1) {
			int l; int r; ll v;
			cin >> l >> r >> v;
			tree.modify(l, r, v);

		}
		else {
			int l, r; cin >> l >> r;
			cout << tree.calc(l, r) << endl;
		}
	}


}


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