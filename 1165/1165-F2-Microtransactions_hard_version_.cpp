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

vll v[2000050];
ll a[2000050], n, m;

bool possible(ll k)
{
    ll b[n];
    f(0, n) b[i] = a[i];
    ll cd = k;
    fr(k, 1)
    {
        f(0, v[j].size())   
        {
            ll u = v[j][i];
            if(b[u] > 0)
            {
                ll x = min(b[u], cd);
                cd -= x;
                b[u] -= x;
            }
        }
        if(cd > j - 1)
            cd = j - 1;
    }
    ll s = 0;
    cd = k;
    f(0, n)
        s += b[i], cd -= a[i] - b[i];
    // cout<<k<<" "<<cd<<"\n";
    // f(0, n)
    //     cout<<b[i]<<" ";    cout<<"\n";
    if(cd >= 2*s)
        return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin>>n>>m;
    f(0, n)
        cin>>a[i];
    f(0, m)
        cin>>x>>y,      v[x].pb(y-1);
    ll l = 1, r = 2000050, ans = -1;
    while(l <= r)
    {
        ll mid = l + r >> 1;
        if(possible(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}