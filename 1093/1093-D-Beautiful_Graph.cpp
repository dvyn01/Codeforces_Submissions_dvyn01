/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 998244353
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll ans, c[3000050], oc, tc;
vll adj[3000050];
bool b[3000050], ok;

void dfs(ll x, ll cv)
{
    b[x] = true;
    c[x] = cv;
    if(cv == 1)
        oc++;
    else tc++;
    f(0, adj[x].size())
    {
        if(c[x] == c[adj[x][i]])
        {
            ok = false;
            return;
        }
        if(!b[adj[x][i]])
        dfs(adj[x][i], cv ^ 1);
    }
}

/*  ll root(ll i)
{
    while(i != a[i])
        i = a[a[a[a[a[i]]]]];
    return i;
}

void unionn(ll x, ll y)
{
    if(root(x) == root(y))
    {
        cycle = true;
        return;
    }
    ll xr = root(x),    yr = root(y),   xs = s[xr],     ys = s[yr];
    if(xs > ys)
    {
        a[yr] = a[xr];
        s[xr] += ys;
    }
    else
    {
        a[xr] = a[yr];
        s[yr] += xs;
    }
}

void bfs(ll x, ll p, ll level)
{
    lc[level]++;
    f(0, adj[x].size())
    {
        if(adj[x][i] != p)
            bfs(adj[x][i], x, level + 1);
    }
}

void init(ll n)
{
    f(0, n+1)
        a[i] = i,   s[i] = 1, lc[i] = 0;
}
*/

ll powmod(ll x, ll y)
{
    x %= mod;
    ll r = 1;
    while(y)
    {
        if(y & 1)
            r = (r * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return r;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ok = true;
        ll n, m, x, y;
  //      cycle = false;
        cin>>n>>m;
        f(0, n+1)       {   c[i] = -1;  b[i] = false;       }
        f(1, n+1)       adj[i].clear();
    //    init(n);
      //  f(1, n+1)       adj[i].clear();
        f(0, m)
        {
            cin>>x>>y;
            adj[x].pb(y);   adj[y].pb(x);
    //        if(!cycle)
    //            unionn(x, y);
        }
        ans = 1;
        ll ta = 0;
        f(1, n+1)
        {
            if(!b[i])
            {
                ll ca = 0;
                oc = 0; tc = 0;
                ta = 0;
                dfs(i, 0);
                ca = powmod(2, oc);
                ta = (ta + ca) % mod;
                ca = powmod(2, tc);
                ta = (ta + ca) % mod;
                ans = (ans * ta) % mod;
            }
        }
        if(!ok)
        {
            cout<<"0\n";
            continue;
        }
        cout<<ans<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

