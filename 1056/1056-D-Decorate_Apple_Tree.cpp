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
vll adj[100005], v;


ll dfs(ll x, ll p)
{
    if(x != 1 && adj[x].size() == 1)
    {   v.pb(1);    return 1;   }
    ll r = 0;
    f(0, adj[x].size())
        if(adj[x][i] != p)
            r += dfs(adj[x][i], x);
    v.pb(r);
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

    ll n, x;
    cin>>n;
    if(n == 1)
    {
        cout<<1;
        return 0;
    }
    f(2, n+1)       cin>>x,      adj[x].pb(i),       adj[i].pb(x);
    dfs(1, -1);
    sort(v.begin(), v.end());
    f(0, v.size())  cout<<v[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

