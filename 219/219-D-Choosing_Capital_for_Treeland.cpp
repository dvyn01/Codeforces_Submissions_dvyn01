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
pll adj[200050];
ll n, mx, t;
ll dp[200050][2];

void dfs(ll x, ll p, ll ct, ll cd)
{
    dp[x][0] = ct;
    dp[x][1] = cd;
    f(0, adj[x].size())
    {
        if(adj[x][i].first == p)
            continue;
        dfs(adj[x][i].first, x, ct + adj[x][i].second, cd + 1);
        t += adj[x][i].second;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    f(0, n-1)
        cin>>x>>y,      adj[x].pb(mp(y, 0)),    adj[y].pb(mp(x, 1));
    pll p;
    dfs(1, -1, 0, 0);
    f(1, n+1)
        p.pb(mp(t - 2 * dp[i][0] + dp[i][1], i));
    sort(p.begin(), p.end());
    cout<<p[0].first<<"\n";
    cout<<p[0].second<<" ";
    f(1, p.size())
    {
        if(p[i].first != p[0].first)
            break;
        cout<<p[i].second<<" ";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

