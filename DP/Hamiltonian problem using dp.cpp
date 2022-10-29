#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
bool Hamiltonian_path(
    vector<vector<int> >& adj, int N)
{
    int dp[N][(1 << N)];
 
    memset(dp, 0, sizeof dp);
 
    for (int i = 0; i < N; i++)
        dp[i][(1 << i)] = true;
 
    for (int i = 0; i < (1 << N); i++) {
 
        for (int j = 0; j < N; j++) {
 
            if (i & (1 << j)) {
 
                for (int k = 0; k < N; k++) {
 
                    if (i & (1 << k)
                        && adj[k][j]
                        && j != k
                        && dp[k][i ^ (1 << j)]) {

                        dp[j][i] = true;
                        break;
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < N; i++) {
 
        if (dp[i][(1 << N) - 1])
            return true;
    }
 
    return false;
}
 
int main()
{
 
    vector<vector<int>> adj;

    int n,t;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        int temp=n;
        while(temp--)
        {
            int a;
            cin>>a;
            v.pb(a);
        }
        adj.pb(v);

    }


    int N = adj.size();
 
    if (Hamiltonian_path(adj, N))
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}
