// Qg3
// //g++ -std=c++17 -O2 -Wall a.cpp -o test
// ()
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
#define debug2(x,y) cout<<"Debug "<<#x<<" -> "<< x<<" | "<<#y<<" -> "<<y <<endl;
#define debug(x) cout<<"Debug " << #x<<" -> "<< x << endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define ciN cin
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)

const ll maxn = 2e5 + 3;
const ll nax = 2e5 + 2;
const ll max_val = 5e4 + 10;
const ll mod = 998244353;
const ll mod2 = 1e9 + 6;
const ll bits = 18;
ll caseNumber = 1;
#define endl "\n"
/*
count inversion for each bit, present or not-present.
*/
struct FenwickTree {
	ll n;
	vll bst;
	void init(ll x) {
		n = x;
		bst.assign(n, 0);
	}
	ll func(ll k) {
		ll s = 0;
		while (k >= 1 && k < n) {
			s += bst[k];
			k -= (k & (-k));
		}
		return s;
	}
	void add(ll k, ll x) {
		while (k <= n) {
			bst[k] += x;
			k += (k & (-k));
		}
	}
};

ll cntInversions(vll v) {
	set<ll>ok;
	for (auto x : v)ok.insert(x);
	int ind = 1;
	map<int, int> id;
	for (auto x : ok) {

		id[x] = ind; ind++;
	}
	for (auto x : id)debug2(x.F, x.S);

	FenwickTree tree;
	tree.init(ind + 1);
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		tree.add(v[i], 1LL);
		ll tot = tree.func(ind);
		tot -= tree.func(v[i]);
		ans += tot > 0 ? tot : 0;
	}
	return ans;
}
void solve() {
	ll n; cin >> n;
	vll v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];

	}
	cout << cntInversions(v) << endl;

}



bool TestCase1 = 0;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	t = 1;



	if (TestCase1) {
		cin >> t;
	}
	int youcantusethis = 1;
	while (t--) {
		//	cout << "Case #" << youcantusethis << ": ";
		solve();
		//	youcantusethis++;
	}
	return 0;
}