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
vll adj[300010];
ll x, y, ct;
bool bb[300010] = {false};

bool dfs(ll j, ll p)
{
    if(j==y)
        return bb[j] = true;
    if(adj[j].size()==1 && j!=x)
        return bb[j] = false;
    f(0, adj[j].size())
    {
        if(adj[j][i] != p)
          {
              bb[j] = dfs(adj[j][i], j);
              if(bb[j]) break;
          }
    }
    return bb[j];
}

ll dfs1(ll j)
{
    ct++;
    if(adj[j].size()==1)
        return 0;
    bb[j] = true;
    f(0, adj[j].size())
    {
        if(!bb[adj[j][i]])
            dfs1(adj[j][i]);
    }
    return 0;
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

    ll n;
    cin>>n>>x>>y;
    f(0, n-1)
    {
        ll a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(x, 0);
    ll xx = dfs1(x);
    xx = ct;
    ct = 0;
    ll yy = dfs1(y);
    yy = ct;
    xx *= yy;
    ll ans = n*(n-1) - xx;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
