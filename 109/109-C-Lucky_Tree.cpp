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

ll n, ans, b;

pll adj[100050];
vll v;
ll baap[100050];

bool check_kr(ll n)
{
    bool nii = false;
    while(n)
    {
        if(n % 10 != 4 && n % 10 != 7)
            nii = true;
        n /= 10;
    }
    return !nii;
}

ll dfs(ll x, ll pr)
{
    ll berozgar = 1;
    f(0, adj[x].size())
    {
        if(adj[x][i].first != pr)
        {
            baap[adj[x][i].first] = adj[x][i].second;
            ll y = dfs(adj[x][i].first, x);
            if(!check_kr(adj[x][i].second))
                berozgar += y;
        }
    }
    if(x == 1 || check_kr(baap[x]))
        ans += berozgar * (berozgar -1 ) * (berozgar - 2) + berozgar * (berozgar - 1) * (n - berozgar) * 2;
 //   cout<<x<<" "<<baap[x]<<" "<<r<<" "<<ans<<"\n";
    return berozgar;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, w;
    cin>>n;
    f(0, n-1)  cin>>x>>y>>w,        adj[x].pb({y, w}),      adj[y].pb({x, w});
    dfs(1, -1);
    ans = n * (n - 1) * (n - 2) - ans;
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}