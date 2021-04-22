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
const ll maxn = 1e5 + 10;
const ll max_val = 2e5 + 10;
ll mod = 1000000007;
const ll bits = 19;
ll caseNumber = 1;

////////////////////////////////////////////////////////////////
/*


*/
ll dp[bits][maxn];
void jabru() {
	ll n, q; cin >> n >> q;
	vll v(n);
	ll sum = 0;
	For(i, 0, n) {
		cin >> v[i];
	}
	// preprossesing starts
	for (int i = 0; i < n; i++) {
		dp[0][i] = v[i];
	}
	for (int i = 1; i < bits; i++)for (int j = 0; j < n; j++)dp[i][j] = 1e18;
	for (int i = 1; i < bits; i++) {
		for (int j = 0; j < n; j++) {
			ll f = dp[i - 1][j];
			ll done = j + (1LL << (i - 1));
			ll s = LLONG_MAX;
			if (done < n) {
				s = dp[i - 1][done];
			}
			dp[i][j] = min(f, s);
		}

	}
	// making for sparse table ends here
	// range query starts...
	for (int i = 0; i < q; i++) {
		ll l, r; cin >> l >> r;
		l--; r--;
		ll len = r - l + 1;
		ll ind = 0;
		for (ll j = 18; j > -1; j--) {
			if (len & (1LL << j)) {
				ind = j; break;
			}
		}
		ll a = dp[ind][l];
		//	debug(ind);
		ll xx = r - (1LL << ind) + 1;
		ll b = dp[ind][xx];
		cout << min(a, b) << endl;
	}
	// sum type queries
	// long long sum = 0;
	// for (int j = K; j >= 0; j--) {
	// 	if ((1 << j) <= R - L + 1) {
	// 		sum += st[L][j];
	// 		L += 1 << j;
	// 	}
	// }

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