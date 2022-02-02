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
/////////////
bool isGoogles = 0;
const ll maxn = 2e3 + 3;
const ll max_val = 2e5 + 10;
ll mod = 1000000007;
const ll bits = 20;
ll caseNumber = 1;
////////////////////////////////////////////////////////////////
vll bst(maxn, 0);
vi adj[maxn];
vi ans(maxn, 0);
vi small(maxn, 0);
ll func(ll k) {
	ll s = 0;
	while (k >= 1 && k < maxn) {
		s += bst[k];
		k -= (k & (-k));
	}
	return s;
}
ll give_kth(int k)
{

	int l = 0;
	int h = bst.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= func(mid))
			h = mid;
		else
			l = mid + 1;
	}
	if (func(l) < k)return -1;
	return l;
}
void add(ll k, ll x) {
	while (k <= maxn - 1) {
		bst[k] += x;
		k += (k & (-k));
	}
}

void jabru() {
	// finding the kth smallest number present in DS in logn*logn
	// deletion, insertion, searching, kthsmallest operation alllowed


}



bool TestCase = 0;



//////////////////////////////////////////////////////////////////








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

	}
	return 0;
}