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

ll n, a[1005], dp[1005][1005];

ll rec(ll i, ll li)
{
    if(i > n)
        return 0;
    if(dp[i][li] != -1)
        return dp[i][li];
    ll k = 1e18;
    if(li == 0)
        k = min( rec(i+2, 0) + max(a[i], a[i+1]), min( rec(i+3, i) + max(a[i+1], a[i+2]), rec(i+3, i+1) + max(a[i], a[i+2]) ) );
    else k = min( rec(i+1, 0) + max(a[li], a[i]), min( rec(i+2, i) + max(a[li], a[i+1]), rec(i+2, li) + max(a[i], a[i+1]) ) );
//    cout<<i<<" "<<li<<" "<<k<<"\n";
    return dp[i][li] = k;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    f(1, n+1)       cin>>a[i];
    ll xXxXxXxXxX = n;
    if(n & 1)       n++;
    memset(dp, -1, sizeof(dp));
    f(n+1, n+3)       a[i] = 1e18;
    ll anss = rec(1, 0);
    cout<<anss<<"\n";
    pll ans;
    ll i = 1, li = 0;   
    while(i <= n)
    {
        if(li == 0)
        {
            ll k1 = dp[i+2][0] + max(a[i], a[i+1]),  k2 = dp[i+3][i] + max(a[i+1], a[i+2]), k3 = dp[i+3][i+1] + max(a[i], a[i+2]);
            ll x = min(k1, min(k2, k3));
            if(x == k1)
                ans.pb({i, i+1}),   i += 2;
            else if(x == k2)
                ans.pb({i+1, i+2}),     li = i,     i += 3;
            else ans.pb({i, i+2}),      li = i+1,   i += 3;
        }
        else
        {
            ll k1 = dp[i+1][0] + max(a[li], a[i]),  k2 = dp[i+2][i] + max(a[li], a[i+1]), k3 = dp[i+2][li] + max(a[i], a[i+1]);
            ll x = min(k1, min(k2, k3));
            if(x == k1)
                ans.pb({li, i}),   i += 1,      li = 0;
            else if(x == k2)
                ans.pb({li, i+1}),     li = i,     i += 2;
            else ans.pb({i, i+1}),      i += 2;
        }
    }
    f(0, ans.size())
    {
        if(ans[i].first <= xXxXxXxXxX && ans[i].second <= xXxXxXxXxX)
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        else if(ans[i].second > xXxXxXxXxX)
            cout<<ans[i].first;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}