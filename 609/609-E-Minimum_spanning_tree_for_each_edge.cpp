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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll n, mm, p[200050][32], parent[200050], dp[200050][32], a[200050], s[200050], level[200050], mx, mstw;
vector< pair< ll, pair<ll, ll> >> adj;
vll t[200050];
map<ll, map<ll, ll>> m;

void init(ll n)
{
    f(0, n+1)
        a[i] = i, s[i] = 1;
}

ll root(ll i)
{
    while(i != a[i])
        i = a[a[a[a[a[a[a[a[a[a[i]]]]]]]]]];        // This Works :-O
    return i;
}

void unionn(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if(xr == yr)
        return;
    ll xs = s[xr], ys = s[yr];
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

void kruskal()
{
    f(0, adj.size())
    {
        ll x = adj[i].second.first, y = adj[i].second.second;
        if(root(x) == root(y))
            continue;
        unionn(x, y);
        t[x].pb(y);
        t[y].pb(x);
        m[x][y] = adj[i].first;     m[y][x] = adj[i].first;
        mstw += adj[i].first;
    }
}

void dfs(ll x, ll pr)
{
    if(pr != -1)
        level[x] = level[pr] + 1;
    parent[x] = pr;
    f(0, t[x].size())
        if(t[x][i] != pr)
            dfs(t[x][i], x);
}

void pre()
{
    memset(p, -1, sizeof(p));
    memset(dp, -1, sizeof(dp));
    f(1, n+1)
        p[i][0] = parent[i];
    f(1, n+1)
        dp[i][0] = m[i][parent[i]];
    for(ll j = 1; (1<<j) < n; j++)
    {
        f(1, n+1)
        {
            if(p[i][j-1] != -1)
            {
                p[i][j] = p[p[i][j-1]][j-1];
                dp[i][j] = max(dp[i][j-1], dp[p[i][j-1]][j-1]);
            }
        }
    }
}

void lca(ll u, ll v)
{
    if(level[u] < level[v])
        swap(u, v);
    mx = 0;
    ll d = level[u] - level[v];
    while(d)
    {
        ll raise = log2(d);
        d -= (1 << raise);
    //    cout<<u<<" "<<(1<<raise)<<" "<<dp[u][raise]<<" --- \n";
        mx = max(mx, dp[u][raise]);
        u = p[u][raise];
    }
    if(u == v)
        return;
    for(ll j = 31; j >= 0; j--)
    {
        if(p[u][j] != -1 && p[u][j] != p[v][j])
        {
            mx = max(mx, dp[u][j]);
            mx = max(mx, dp[v][j]);
            u = p[u][j];
            v = p[v][j];
        }
    }
    mx = max(mx, dp[u][0]);
    mx = max(mx, dp[v][0]);
  //  cout<<"lca: "<<parent[u]<<"\n";
    return;
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

    cin>>n>>mm;
    init(n);
    vector< pair < pair<ll, ll>, ll> > pp;
    f(0, mm)
    {
        ll x, y, w;
        cin>>x>>y>>w;
        adj.pb(mp(w, mp(x, y)));
        pp.pb(mp(mp(x, y), w));
    }
    sort(adj.begin(), adj.end());
    kruskal();
    dfs(1, -1);
    pre();
    f(0, pp.size())
    {
        ll x = pp[i].first.first,   y = pp[i].first.second;
        if(m[x][y])
            cout<<mstw<<"\n";
        else
        {
            lca(x, y);
     //       cout<<"mx: "<<mx<<"\n";
            cout<<mstw + pp[i].second - mx<<"\n";
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

