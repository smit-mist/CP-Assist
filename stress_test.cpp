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
vll solver()
{

}

vll jabru() {

}
////////////////////////////////////////////////////////////////



// Step before testing

/*
1. Take input in main and provide as parameter
2. Change the return type of the functions
3. Make other copy of variables in the funtion
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("output.txt", "w", stdout);
	int t;
	int cases_cnt = 0;
	while (1) {


		vll first = jabru();
		vll second = solver();
		if (first != second) {
			cout << "---------> Test Case" << endl;
			cout << aa << " " << bb << endl;
			for (auto x : xx)cout << x << " ";
			cout << endl;
			cout << "---------> Correct Output" << endl;
			for (auto x : first)cout << x << " ";
			cout << endl;
			cout << "---------> Incorrect but accepted output" << endl;
			for (auto x : second)cout << x << " ";
			cout << endl;
			cout << "------------------------------------------" << endl;
			cases_cnt++;
		}
		else
			//cout << "DONE" << endl;
			if (cases_cnt == 100)return 0;
	}


	return 0;
}




