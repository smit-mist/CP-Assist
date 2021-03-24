//Classic
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define mod 998244353
#define ciN cin
#define X INT_MAX
#define N INT_MIN
////////////////////////////////////////////////////////////////
// Binary Expo...
// Calculates power in O(logN) here N is the power required...
ll calcpo(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
// Binary Expo.. with MOD
// Same func.. but gives ans%mod
ll calcpom(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
ll mult(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{
	return ((a % mod) + (b % mod)) % mod;
}
ll sub(ll a, ll b) {
	return ((a % mod) - (b % mod) + mod) % mod;
}
// Modulo inv. of a number mod must be prime number to use this
// Also don't forget to inlucde calcpom with this one..
ll modInv(ll k) {
	return calcpom(k, mod - 2) % mod;
}
// Iterative code for Gcd to calculate in O(logN)..
// Here N is min(a,b)

ll gcd (ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
// To calculate nCr for given value of n and r modulo something..
// include mod inverese and binary exponentiation...
// also make an array to store factorial % mod...
ll nCr(ll n, ll r) {

	if (r == 0)
		return 1;
	if (r > n) {
		return 0;
	}

	return (fact[n] * modInv(fact[r]) % mod * modInv(fact[n - r]) % mod) % mod;
}
// Extended GCD use this to solve Ax+By = C type of equation...
// This function will return the gcd of both numbers..
// but X, Y later on can be used as co-efficient of the above equation and gives us the solution..
// Though before using this check if C is divisible by d if not no solution is there.
// Once again only in logn
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
	x = 1, y = 0;
	ll x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}
// This gives us all the prime numbers till n inclusive..
// It returns a vector of bool and its true if the index is prime else false..
// Works in O(N(log(logN)))

vector<bool> Sieve(ll n) {

	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (is_prime[i] && 1LL * i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return is_prime;
}


void jabru() {
}
////////////////////////////////////////////////////////////////


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





///////////////////////////////////////////////////////////////////////////////////////////
//Kai baju bhai?s