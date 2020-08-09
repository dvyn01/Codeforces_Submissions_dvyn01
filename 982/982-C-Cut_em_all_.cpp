//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
vll v[100010];
ll n, ans;

ll dfs(ll x, ll p)
{
    ll c = 1;
    f(0, v[x].size()){
        if(v[x][i] != p)
            c += dfs(v[x][i], x);
    }
    ans += c&1^1;
    return c;
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0) ;

    cin>>n;
    f(0,n-1){ll a,b; cin>>a>>b; v[a].pb(b); v[b].pb(a);}
    dfs(1, 0);
    if(!(n%2))
    cout<<ans-1;
    else cout<<"-1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

