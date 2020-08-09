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

vll adj[300050];
ll a[300050], n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll u, v;
    cin>>n>>m;
    f(0, n)    cin>>a[i];
    f(0, m)    cin>>u>>v,   adj[v].pb(u);
    set<ll> s;
    f(0, adj[a[n-1]].size())     
        s.insert(adj[a[n-1]][i]);
    ll cp = n-2;
    ll ans = 0;
    while(cp >= 0)
    {
        if(s.empty())
            break;
        ll k = a[cp];
        cp--;
        if(s.find(k) != s.end())
        {
            ans++;
            continue;
        }
        set<ll> s1;
        f(0, adj[k].size())
        {
            ll x = adj[k][i];
            if(s.find(x) != s.end())
                s1.insert(x);
        }
        s = s1;
    }
    cout<<ans;


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}