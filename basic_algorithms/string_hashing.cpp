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
#define endl "\n"

/////////////
const ll maxn = 1e6 + 3;
const ll max_val = 5e4 + 10;
const ll mod = 1e9 + 7;
const ll bits = 18;
ll caseNumber = 1;

////////////////////////////////////////////////////////////////
string s; int n;
const ll p = 31; // might need to change based on string
ll p_pow[maxn];
ll h[maxn];
void compute_hash() {
	p_pow[0] = 1LL;
	for (int i = 1; i <= n; i++) {
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
	h[0] = 0;
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
	}

	// don't mess with this function
}
ll get_hash(int a, int b) {
	// a and b both are zero based
	ll here = ((h[b + 1] - h[a]) % mod + mod) % mod;
	here = (p_pow[n - 1 - a] % mod * here % mod) % mod;
	return here;
}
void solve() {
	string s;
	cin >> s;
	n = s.size();
	compute_hash();
	// abbabb

}


bool TestCase1 = 1;
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