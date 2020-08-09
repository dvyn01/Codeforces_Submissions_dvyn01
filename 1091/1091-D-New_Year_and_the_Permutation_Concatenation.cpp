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

ll f[1000050], inv[1000050];

ll powmod(ll x, ll y)
{
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

ll npr(ll n, ll r)
{
    if(r == n || r == 1)
        return n;
    if(r > n)
        return 0;
    return (((f[n] * inv[r]) % mod * inv[n-r]) % mod * f[r]) % mod;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f[0] = 1;
    inv[0] = 1;
    f(1, 1000050)
        f[i] = (f[i-1] * i) % mod, inv[i] = powmod(f[i], mod - 2);
    ll n;
    cin>>n;
    ll ans = 0;
    ans += f[n-1];
    f(1, n)
        ans = (ans + ((f[n-i] - 1) * npr(n-1, i-1)) % mod) % mod;
    ans = (ans * n) % mod;
    cout<<ans;


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

