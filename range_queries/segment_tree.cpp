//Classic
//g++ -std=c++11 -O2 -Wall a.cpp -o test
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug2(x,y) cout<<"AA Baju Smit----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"AA Baju Smit------> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mod 1000000007
#define ciN cin
#define tu(a,s) get<a>(s)
#define tin tuple<int,int,int>
////////////////////////////////////////////////////////////////
struct segtree
{
	// Ending of the range is non inclusive, and starting is inclusive :)
	// Update index must be 0 based
	// L must be 0 based
	// R must be 1 based
	vector<ll>sums;
	ll size = 1;

	void init(ll n) {
		while (size < n)size *= 2;
		sums.assign(2 * size, INT_MAX); // Change

	}

	void build(vll &a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]); // Change
	}
	void build(vll &a) {
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			sums[x] = v; return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]); // Change
	}

	void set(ll i, ll v) {
		set(i, v, 0, 0, size);
	}
	ll sum(ll l, ll r, ll x, ll lx, ll rx) {
		// R must be non Inclusive
		if (lx >= r || rx <= l) {
			return INT_MAX; // Change
		}
		if (lx >= l && rx <= r)return sums[x];
		ll m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return min(s1, s2); // Change
	}

	ll sum(ll l, ll r) {
		return sum(l, r, 0, 0, size);
	}

};
void jabru() {

	ll n, m; cin >> n >> m;
	vll v(n);
	segtree st;
	st.init(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	st.build(v);
	for (int i = 0; i < m; i++) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			st.set(b, c);
		}
		else {
			cout << st.sum(b, c) << endl;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	t = 1;
//	cin >> t;
	while (t--) {
		jabru();
	}

	return 0;




}