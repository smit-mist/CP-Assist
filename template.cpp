//Classic
//g++ -std=c++17 -O2 -Wall a.cpp -o test
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
#define debug2(x,y) cout<<"This side ----> "<<#x<<" -> "<<x<<" | "<<#y<<" -> "<<y<<endl;
#define debug(x) cout<<"This side    ----> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
//#define mod 1000000007
#define ciN cin
#define tu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)
////////////////////////////////////////////////////////////////
bool isGoogles = 0;
bool TestCase = 1;
const ll maxn = 1e6 + 10;
const ll mod = 1000000007;

void jabru() {

}

//////////////////////////////////////////////////////////////////




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	t = 1;
	if (TestCase) {
		cin >> t;

	}
	ll ss = 1;
	while (t--) {
		if (isGoogles) {
			cout << "Case #" << ss << ": ";

		}
		ss++;
		jabru();

	}

	return 0;




}