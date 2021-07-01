//Classic
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
//#define endl "\n"
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
#define ul ll
/////////////

const ll maxn = 2e5 + 5;
const ll max_val = 2e5 + 10;
ll mod = 1e9 + 7;
const ll bits = 20;
ll caseNumber = 1;
////////////////////////////////////////////////////////////////
struct Item
{
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
	Item single(int x) {
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
void jabru() {
	ll n, q; cin >> n >> q;
	vll v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	segtree tree;
	tree.init(n + 1);
	tree.build(v);
	for (int i = 0; i < q; i++) {
		ll p; cin >> p;
		if (p == 2) {
			ll a, b; cin >> a >> b;
			cout << tree.Qg3(a, b).x << endl;
		}
		else {
			ll a, b; cin >> a >> b;
			tree.set(a, b);
		}

	}


}



bool TestCase = 0;
bool isGoogles = 0;



//////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	t = 1;
	if (TestCase) {
		cin >> t;
	}
	while (t--) {
		if (isGoogles) {cout << "Case #" << caseNumber << ": ";} caseNumber++;
		jabru();

	}
	return 0;
}