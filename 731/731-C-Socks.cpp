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

vll adj[200050];
bool b[200050];
unordered_map<ll,ll> m;
ll c, nn, a[200050];

ll dfs(ll x)
{
    nn++;
    b[x] = true;
    m[a[x]]++; if(m[a[x]] > c) c=m[a[x]];
    f(0, adj[x].size())
    {
        if(!b[adj[x][i]])
            dfs(adj[x][i]);
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

    ll n, mm, k;
    cin>>n>>mm>>k;
    f(1, n+1) cin>>a[i];
    f(0, mm)
    {
        ll x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll ans=0;
    f(1, n+1)
    {
        if(!b[i])
        {
            nn=0;
            c=0;
            m.clear();
            dfs(i);
            ans += nn-c;
        }
    }
    cout<<ans;


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

