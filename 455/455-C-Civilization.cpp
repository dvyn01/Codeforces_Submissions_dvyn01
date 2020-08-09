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
vll adj[300050];
ll md, mv, n, m, q, a[300050], s[300050], d[300050];
bool vis[300050], vis1[300050];

void dfs(ll x, ll cd)
{
    if(cd > md)
    {
        md = cd;
        mv = x;
    }
    vis[x] = true;
    f(0, adj[x].size())
        if(!vis[adj[x][i]])
            dfs(adj[x][i], cd + 1);
}

void dusra_dfs(ll x, ll cd)
{
    if(cd > md)
    {
        md = cd;
        mv = x;
    }
    vis1[x] = true;
    f(0, adj[x].size())
        if(!vis1[adj[x][i]])
            dusra_dfs(adj[x][i], cd + 1);
}

void init()
{
    f(0, n+1)       a[i] = i,       s[i] = 1;
}

ll root(ll i)
{
    while(a[i] != i)
        i = a[a[a[a[i]]]];
    return i;
}

void unionn(ll x, ll y)
{
    ll xr = root(x), yr = root(y), xs = s[xr], ys = s[yr];
    if(xr == yr)
        return;
    ll k1, k2;
    if(d[xr] & 1)
        k1 = d[xr] / 2 + 1;
    else k1 =d[xr] / 2;
    if(d[yr] & 1)
        k2 = d[yr] / 2 + 1;
    else k2 = d[yr] / 2;
    if(xs >= ys)
    {
        a[yr] = a[xr];
        s[xr] += ys;
        d[xr] = (max(d[xr], max(d[yr], k1 + k2 + 1)));
    }
    else
    {
        a[xr] = a[yr];
        s[yr] += xs;
        d[yr] = (max(d[xr], max(d[yr], k1 + k2 + 1)));
    }
  //  cout<<xr<<" "<<yr<<" "<<k1<<" "<<k2<<" "<<d[xr]<<" "<<d[yr]<<"\n";
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;
    ll x, y;
    init();
    f(0, m)     cin>>x>>y,      adj[x].pb(y),       adj[y].pb(x),       unionn(x, y);
    f(1, n+1)
    {
        if(!vis[i])
        {
            md = 0; mv = 0;
            dfs(i, 0);
            md = 0;
            dusra_dfs(mv, 0);
            d[root(i)] = md;
        }
    }
    while(q--)
    {
        ll t;
        cin>>t;
        if(t == 1)
        {
            cin>>x;
            cout<<d[root(x)]<<"\n";
        }
        else
        {
            cin>>x>>y;
            unionn(x, y);
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

