//Coded By Vishal Mourya
#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define f(var,a,b) for(ll var = a ; var < b ; var++ )
#define fr(var,a,b) for(ll var = a ; var > b ; var-- )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int pi[200001];

int main(void){
    fasthoja;
    string pat, text; cin >> pat >> text;

    string st = pat + "#" + text;

    f(i, 1, st.size()) {
        int j = pi[i-1];

        while( j > 0 && st[i] != st[j] )
            j = pi[j-1];
        
        if( st[i] == st[j] )
            j++;
        pi[i] = j;
    }

    int res = 0;

    f(i, pat.size() , st.size())
        if( pi[i] == pat.size() )
            res++;
    
    cout << res << "\n";
    return 0;
}