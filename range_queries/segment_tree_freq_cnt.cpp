//Classic
//g++ -std=c++17 -O2 -Wall a.cpp -o test
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
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
#define endl "\n"
#define debug2(x,y) cout<<"This side ----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"This side    ----> "<<#x<<" -> "<<x<<endl
//#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
//#define ao(a, n) {for (int ele = 0; ele < (n); ele++) {cout << a[ele]<<" "; } cout << '\n';}
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define ciN cin
#define g(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)
/////////////
bool isGoogles = 0;
const ll maxn = 2e5 + 10;
const ll max_val = 2e5 + 10;
ll mod = 1000000007;
const ll bits = 19;
ll caseNumber = 1;

////////////////////////////////////////////////////////////////
/*

*/
struct segtree
{
	// Update index must be 0 based
	// L must be 0 based
	// R must be 1 based
	// Second in Pair will have frequency of the minimum
	vector<pair<ll, ll>>sums;
	ll size = 1;

	void init(ll n) {
		while (size < n)size *= 2;
		sums.assign(2 * size, {INT_MAX, INT_MAX}); // Change

	}

	void build(vll &a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				sums[x].F = a[lx]; sums[x].S = 1LL;
			}
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		pll f = min(sums[2 * x + 1], sums[2 * x + 2]), s = max(sums[2 * x + 1], sums[2 * x + 2]); // Change
		if (f.F == s.F) {
			sums[x].F = f.F;
			sums[x].S = f.S + s.S;
		}
		else {
			sums[x] = f;
		}
	}
	void build(vll &a) {
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			sums[x].F = v;
			sums[x].S = 1;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		pll f = min(sums[2 * x + 1], sums[2 * x + 2]), s = max(sums[2 * x + 1], sums[2 * x + 2]); // Change
		if (f.F == s.F) {
			sums[x].F = f.F;
			sums[x].S = f.S + s.S;
		}
		else {
			sums[x] = f;
		}
	}

	void set(ll i, ll v) {
		set(i, v, 0, 0, size);
	}
	pll sum(ll l, ll r, ll x, ll lx, ll rx) {
		// R must be non Inclusive
		if (lx >= r || rx <= l) {
			return {INT_MAX, INT_MAX}; // Change
		}
		if (lx >= l && rx <= r)return sums[x];
		ll m = (lx + rx) / 2;
		pll s1 = sum(l, r, 2 * x + 1, lx, m);
		pll s2 = sum(l, r, 2 * x + 2, m, rx);
		pll f = min(s1, s2), s = max(s1, s2); // Change
		if (f.F == s.F) {
			f.S += s.S;
		}
		return f;
	}

	pll sum(ll l, ll r) {
		return sum(l, r, 0, 0, size);
	}

};
void jabru() {
	ll n;
	cin >> n;
	ll q; cin >> q;
	vll a(n);
	segtree tree;

	tree.init(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//tree.set(i, a[i]);
	}

	tree.build(a);
	for (int i = 0; i < q; i++) {
		ll x, y, z; cin >> x >> y >> z;
		if (x == 1) {
			tree.set(y, z);
		}
		else {
			pll aa = tree.sum(y, z);
			cout << aa.F << " " << aa.S << endl;
		}
	}



}


bool TestCase = 0;



//////////////////////////////////////////////////////////////////






void brain_wash() {

}


/*

*/
//////////////////////////////////////////////////////////

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll t;
	t = 1;
	if (TestCase) {
		cin >> t;
	}
	while (t--) {
		if (isGoogles) {cout << "Case #" << caseNumber << ": ";} caseNumber++;
		jabru();
		brain_wash();

	}
	return 0;
}

/*

*/