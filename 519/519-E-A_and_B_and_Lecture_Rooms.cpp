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
ll n, parent[100005], p[100005][32], level[100005], subtree[100005], a, b;
vll adj[100005];
bool done;

ll dfs(ll x, ll pr)
{
    if(pr != -1)
        level[x] = level[pr] + 1;
    parent[x] = pr;
    ll k = 0;
    f(0, adj[x].size())
    {
        if(adj[x][i] != pr)
            k += dfs(adj[x][i], x);
    }
    return subtree[x] = k + 1;
}

void pre()
{
    memset(p, -1, sizeof(p));
    f(1, n+1)
        p[i][0] = parent[i];
    for(ll j = 1; (1<<j) < n; j++)
    {
        f(1, n+1)
            if(p[i][j-1] != -1)
                p[i][j] = p[p[i][j-1]][j-1];
    }
}

void same(ll x, ll y, ll l)
{
    ll u = x;
    ll d = l;
    while(d != 1)
    {
        u = parent[u];
        d--;
    }
  //  cout<<x<<" "<<u<<" "<<l<<"---\n";
    cout<<subtree[parent[u]] - subtree[u]<<"\n";
}

ll lca(ll u, ll v)
{
    if(level[v] > level[u])
        swap(u, v);
    ll d = level[u] - level[v];
    ll uu = u, vv = v;
    while(d)
    {
        ll raise = log2(d);
        u = p[u][raise];
        d -= (1 << raise);
    }
    for(ll j = 31; j >= 0; j--)
    {
        if(p[u][j] != p[v][j])
        {
            u = p[u][j];
            v = p[v][j];
        }
    }
    if(level[uu] != level[vv])
    {
        done = true;
        ll d;
        if(u != uu && u != vv)
            d = (level[uu] + level[vv] - 2 * level[parent[u]]);
        else   d = (level[uu] - level[u]);
 //       cout<<"D = "<<d<<" "<<level[uu]<<" "<<level[vv]<<" "<<uu<<" "<<vv<<" "<<u<<" "<<level[parent[u]]<<"\n";
        if(d & 1)
            cout<<"0\n";
        else
            same(uu, vv, d / 2);
        return 0;
    }
    a = u;  b = v;
    return parent[u];
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

    cin>>n;
    f(0, n-1){ll x, y;      cin>>x>>y;      adj[x].pb(y);       adj[y].pb(x);}
    dfs(1, -1);
    pre();
    ll q;
    cin>>q;
    while(q--)
    {
        ll x, y;
        cin>>x>>y;
        if(x == y)
        {
            cout<<n<<"\n";
            continue;
        }
        done = false;
        ll l = lca(x, y);
        if(done)    continue;
        cout<<n - subtree[a] - subtree[b]<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

