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
ll a[200050];
map<ll, ll> m;

ll powmod(ll x, ll y)
{
    ll r = 1;
    while(y)
    {
        if(y & 1)   r = (r * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
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

    ll n;
    cin>>n;
    f(0, n)     {   cin>>a[i];  m[a[i]] = i;    }
    ll ans = 0, c = 0, cp = 0;
    while(cp < n)
    {
        if(cp == n-1)
        {
            c++;
            break;
        }
        ll k = m[a[cp]];
        f(cp, k+1)
        {
            if(m[a[i]] > k)
            {
                k = m[a[i]];
            }
        }
        c++;
        cp = k + 1;
        if(cp == n)
            break;
    }
    ans = powmod(2, c-1);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

