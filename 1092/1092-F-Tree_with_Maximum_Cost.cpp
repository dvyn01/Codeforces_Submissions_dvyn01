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
ll a[200050], s[200050], ans[2000050], d[2000050], t;
vll adj[200050];

ll go_kill(ll x, ll p, ll ds)
{
    t += a[x];
    s[x] = a[x];
    d[x] = ds;
    f(0, adj[x].size())
        if(adj[x][i] != p)
            s[x] += go_kill(adj[x][i], x, ds + 1);
    return s[x];
}

void kill_again(ll x, ll p, ll v)
{
    ans[x] = v;
    f(0, adj[x].size())
        if(adj[x][i] != p)
            kill_again(adj[x][i], x, v + t - 2 * s[adj[x][i]]);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin>>n;
    f(1, n+1)       cin>>a[i];
    f(0, n-1)
        cin>>x>>y,      adj[x].pb(y),       adj[y].pb(x);
    go_kill(1, 0, 0);
    f(1, n+1)   ans[1] += d[i] * a[i];
    kill_again(1, -1, ans[1]);
    ll mx = 0;
    f(1, n+1)       if(ans[i] > mx)      mx = ans[i];
    cout<<mx;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

