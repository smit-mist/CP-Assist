
/*
	Binary Search - O(logN)

	When we have a function which we want to minimize or maximize and we have
	specific range of answer to perform binary search on.. works for very long
	inputs..


*/


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
#define mt make_tuple
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug(x) cout<<"AA Baju Smit------> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mod 998244353
#define ciN cin
////////////////////////////////////////////////////////////////

void jabru() {

	// Take input for the problem.... and make a fuction to maximize or minimize..
	string k; cin >> k;



	ll b = count(all(k), 'B'), s = count(all(k), 'S'), c = count(all(k), 'C');
	ll nb, ns, nc, pb, ps, pc; cin >> nb >> ns >> nc >> pb >> ps >> pc;
	ll r; cin >> r;
	ll end = 1e14;// Set the range of answer very imp
	ll start = 0;
	ll ans = 0;
	ll prev = -1;
	while (end - start > 1) {//condition for loop termination
		ll mid = (end + start) / 2;

		ll rb = mid * b, rc = mid * c, rs = mid * s;
		ll curr = max(0LL, rb - nb) * pb + max(0LL, rc - nc) * pc + ps * max(rs - ns, 0LL);
		// here come the fuction
		// truncate left or right part as per needed
		if (curr < r) {
			ans = start;// make sure to equate with starting value..
			start = mid;
		}
		else if (curr > r) {
			ans = start;
			end = mid;
		}
		else {
			ans = mid;// here mid as we can directly terminate
			cout << ans << endl; return;
			break;
		}
	}
	ans = start;// answer is the left hand side value this is very imp...
	cout << ans << endl;

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	t = 1;
	while (t--) {
		jabru();
	}

	return 0;
}