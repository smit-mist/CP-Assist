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
#define ciN cin
#define X INT_MAX
#define N INT_MIN
////////////////////////////////////////////////////////////////
struct ModArt
{
	ll mod;
	int N;
	vll fact, ifact;
	void init(int x, ll m) {
		N = x + 5;
		mod = m;
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
	ll modInv(ll k) {
		return calcpom(k, mod - 2) % mod;
	}
	void calc_facts() {
		fact.assign(N, 1LL);
		ifact.assign(N, 1LL);
		ifact[0] = modInv(fact[0]);
		for (ll j = 1; j < N; j++) {
			fact[j] = mult(j, fact[j - 1]);
			ifact[j] = modInv(fact[j]);
		}
	}
	ll nCr(ll n, ll r) {

		if (r == 0)
			return 1;
		if (r > n) {
			return 0;
		}

		return (fact[n] * ifact[r] % mod * ifact[n - r] % mod) % mod;
	}

};
ll gcd (ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
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

vector<int> Sieve(ll n) {

	vector<int> is_prime(n + 1, 0);
	is_prime[0] = is_prime[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (is_prime[i] == 0 && 1LL * i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				is_prime[j] = i;
		}
	}
	return is_prime;
}
int NcR(int n, int r)
{
	int p = 1, k = 1;

	if (n - r < r)
		r = n - r;
	while (r)
	{
		p *= n;
		k *= r;
		ll m = __gcd(p, k);
		p /= m;
		k /= m;
		n--;
		r--;
	}

	return p;

}
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