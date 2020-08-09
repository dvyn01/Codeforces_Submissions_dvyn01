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
ll n, k, a, b, dp[5005];

/*
ll rec(ll x, ll k, ll le)
{
  //  cout<<x<<" "<<k<<"\n";
    if(k == 0 && x > 0 && x <= n)
        return 1;
    if(k <= 0)
        return 0;
    if(abs(le - x) >= abs(le - b))
        return 0;
    if(x > n || x < 1)
        return 0;
    if(dp[x][k] != -1)
        return dp[x][k];
    ll p = 0;
    if(le == -1e10)
    {
        p += 1 + rec(x+1, k-1, x);
        p += 1 + rec(x-1, k-1, x);
    }
    else if(le > x)
    {
        p += 1 + rec(x-1, k, le);
        p += 1 + rec(x-1, k-1, x);
        p += 1 + rec(x+1, k-1, x);
    }
    else
    {
        p += 1 + rec(x+1, k, le);
        p += 1 + rec(x-1, k-1, x);
        p += 1 + rec(x+1, k-1, x);
    }
    return dp[x][k] = p;
}
*/

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b>>k;
    f(1, n+1)
    {
        ll x = abs(i - b);
        ll l = max(1ll, i-x+1),   r = min(n, i+x-1);
        dp[i] = r - l;
    }
    if(k != 1)  f(2, n+1)   dp[i] += dp[i-1], dp[i] %= mod;
    f(1, k)
    {
        ll dp1[5005];
        f(1, n+1)
        {
            ll x = abs(i - b);
            ll l = max(1ll, i-x+1),   r = min(n, i+x-1);
            ll y = dp[r] - dp[i] + dp[i-1] - dp[l-1] + 2 * mod;
            y %= mod;
            dp1[i] = y;
        }
        f(1, n+1)       dp[i] = dp1[i];
        if(i != k-1)    f(2, n+1)       dp[i] += dp[i-1], dp[i] %= mod;
    }
    cout<<dp[a];

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


