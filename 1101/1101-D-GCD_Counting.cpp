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

ll n, a[200050], b[200050], ans;
vll adj[200050];
unordered_map<ll, unordered_map<ll, ll> > dp;       // Unordered 😎

void sieve()
{
    f(0, 200050)        b[i] = i;
    f(2, 200050)
    {
        if(b[i] != i)
            continue;
        for(ll j = 2 * i; j < 200050; j += i)
            if(b[j] == j)   b[j] = i;
    }
}

vll factors(ll n)
{
    vll v;
    while(n != 1)
    {
        v.pb(b[n]);
        ll x = b[n];
        while(n % x == 0) 
            n /= x;
    }
    return v;
}

void dfs(ll x, ll p)
{
    vll v = factors(a[x]);
    f(0, adj[x].size())
        if(adj[x][i] != p)
            dfs(adj[x][i], x);
    if(v.size() == 0)
        return;
    unordered_map<ll, ll> m1, m2;
    fi(0, v.size())
    {
        ll val = v[j];
        f(0, adj[x].size())
        {
            ll v = adj[x][i];
            if(dp[v][val] > m1[val])
                m2[val] = m1[val],  m1[val] = dp[v][val];
            else if(dp[v][val] > m2[val])
                m2[val] = dp[v][val];
        }
        ans = max(ans, 1 + m1[val] + m2[val]);
        dp[x][val] = m1[val] + 1;
    }
}

inline ll mul(ll x, ll y, ll m)	{	ll z = 1LL * x * y;		if(z >= m)	z %= m;		return z;	}
inline ll add(ll x, ll y, ll m)	{	ll z = x + y;			if(z >= m)	z %= m;		return z;	}
inline ll sub(ll x, ll y, ll m)	{	ll z = x - y;			if(z < 0)	z += m;		z %= m;		return z;	}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin>>n;    
    f(1, n+1)       cin>>a[i];
    f(0, n-1)       cin>>x>>y,      adj[x].pb(y),       adj[y].pb(x);
    sieve();
    dfs(1, -1);
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}