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
vll adj[100050];
bool b[100050];
ld ans;

void dfs(ll x, ld p, ld d)
{
    b[x] = true;
    if(x!=1 && adj[x].size() == 1)
    {
        ans += (d/p)*1.0;
        return;
    }
    f(0, adj[x].size())
    {
        if(!b[adj[x][i]])
        {
            if(x==1)
                dfs(adj[x][i], p*adj[x].size(), d+1);
            else    dfs(adj[x][i], p*(adj[x].size()-1), d+1);
        }
    }
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
    cin>>n;
    f(0, n-1)
    {
        ll x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1, 0);
    cout<<fixed<<setprecision(15)<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
