//Classic
//g++ -std=c++17 -O2 -Wall a.cpp -o test
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
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
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)
/////////////
bool isGoogles = 0;
const ll maxn = 1e5 + 10;
const ll max_val = 2e5 + 10;
const ll mod = 1000000007;
const ll bits = 19;
ll caseNumber = 1;
/*

*/
////////////////////////////////////////////////////////////////
// Time Complexity - O(n+mlogm)
vp adj[maxn];
vb vis(maxn, 0);
void jabru() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].pb(mp(b, c));

	}
	vll dist(n + 1, 1e18);
	dist[1]  = 0;
	priority_queue<pll>q;
	q.push(mp(0, 1));
	while (!q.empty()) {
		ll a = q.top().S; q.pop();
		if (vis[a])continue;
		vis[a] = 1;
		for (auto u : adj[a]) {
			ll b = u.F, w = u.S;
			if (dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w;
				q.push(mp(-dist[b], b));
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << dist[i] << " "; cout << endl;

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
Sunday - Graph
Monday - Graph
Tuesday - Math
Wednesday - DP
Thursday - DP/RQ
Friday - RQ
Saturday - Tree
*/