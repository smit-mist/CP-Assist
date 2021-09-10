//Classic
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
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug(x) cout<<"AA Baju Smit------> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mod 1000000007
#define ciN cin
#define X INT_MAX
#define N INT_MIN
////////////////////////////////////////////////////////////////
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
		while (k < n) {
			bst[k] += x;
			k += (k & (-k));
		}
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	t = 1;
	cin >> t;
	while (t--) {
		jabru();
	}


	return 0;
}