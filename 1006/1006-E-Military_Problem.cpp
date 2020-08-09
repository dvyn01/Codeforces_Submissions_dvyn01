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
#define fii(a,b) for(ll k=a; k<b; k++)
vll adj[200010];
vll d, b;
map<ll,ll> m, mm;

ll dfs(int x)
{
    ll c=1;
    mm[x] = d.size();
    d.pb(x);
    f(0, adj[x].size())
    {
        c += dfs(adj[x][i]);
    }
    return m[x] = c;
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, q;
    cin>>n>>q;
    f(2, n+1)
    {
        ll x; cin>>x;
        adj[x].pb(i);
    }
    f(1, n+1) sort(adj[i].begin(), adj[i].end());
    dfs(1);
    while(q--)
    {
        ll u, k;
        cin>>u>>k;
        if(k > m[u])
        {
            cout<<"-1\n";
            continue;
        }
        ll p = mm[u];
        cout<<d[p+k-1]<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

