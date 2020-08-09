/*
    * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

inline ll mul(ll x, ll y, ll m)	{	ll z = 1LL * x * y;		if(z >= m)	z %= m;		return z;	}
inline ll add(ll x, ll y, ll m)	{	ll z = x + y;			if(z >= m)	z %= m;		return z;	}
inline ll sub(ll x, ll y, ll m)	{	ll z = x - y;			if(z < 0)	z += m;		z %= m;		return z;	}

vector< pair<ll, pair<ll, ll> > > adj[300050];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, x, y, w;
    cin>>n>>m>>k;
    f(1, m+1)       cin>>x>>y>>w,   adj[x].pb({y, {w, i}}),     adj[y].pb({x, {w, i}});
    set<pl> q;
    q.insert({0, 1});
    ll in[n+1], d[n+1];     memset(in, -1, sizeof(in));
    f(0, n+1)       d[i] = 1e18;
    d[1] = 0;
    vll ans;
 //   bool vis[n+1];      memset(vis, false, sizeof(vis));      AB NAHI !
    while(!q.empty() && ans.size() < k)     
    {
        auto p = q.begin();
        q.erase(q.begin());
        ll du = p -> first, u = p -> second;
        if(in[u] != -1)
            ans.pb(in[u]);
        f(0, adj[u].size())
        {
            ll v = adj[u][i].first;
            if(d[v] > du + adj[u][i].second.first)
            {
                q.erase({d[v], v});
                d[v] = du + adj[u][i].second.first;
                in[v] = adj[u][i].second.second;                    
                q.insert({d[v], v});
            }
        }
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())
        cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}