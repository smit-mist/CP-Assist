#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;
#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vi vector<int>
#define vp vector<pi>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define POB pop_back 
#define f(i,x,z) for(ll i=x;i<z;i++)
#define debug(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define setall(x,a) memset(x, a, sizeof(x))
#define INF 1000000000000000003 
#define mathpi 3.141592653589793238 
#define F first;
#define S second;
#define vpair vector<pair<ll,ll>>
#define vpairs vector<pair<string,string>>
#define tin tuple<ll,ll,ll>
#define rev(i,x,z) for(ll i=x;i>=z;i--)  
#define ld long double 
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n"; 
#define print_pair(v) for(auto x:v){cout<<x.first<<" "<<x.second<<" ";}cout<<"\n"; 
#define reverse(v) reverse(v.begin(),v.end()) 
#define nline "\n"
#define nl "\n"
#define pq priority_queue<ll>
ll sum=0;
vector<int>v;
vi v2;
void subset(int i,int n,vector<int> &arr)
{
    if(i==n)
    {
        v.push_back(sum);
        print(v2);
        return;
    }
    v2.push_back(arr[i]);
    sum+=arr[i];
    subset(i+1,n,arr);
    sum-=arr[i];
    v2.pop_back();
    subset(i+1,n,arr);
}
int main()
{
	// freopen("inp.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);// Input and output clearance
	cin.tie(0);
    vi v1;
    f(i,0,4)
    {
        v1.pb(i);
    }
    subset(0,v1.size(),v1);
}
