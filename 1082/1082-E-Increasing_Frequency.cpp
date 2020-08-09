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
ll n, c, a[500050], f[500050], dp[500050], in[500050];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    f(1, n+1)   {   cin>>a[i];      if(a[i] == c)   f[i] = f[i-1] + 1;  else f[i] = f[i-1];     }
    ll ans = f[n];
    f(1, n+1)
    {
        if(a[i] == c)
            continue;
        ll x = f[n] - f[i];
        ll y = f[i] - in[a[i]];
        dp[a[i]] = max(dp[a[i]], y + 1);
        ans = max(ans, in[a[i]] + x + dp[a[i]]);
        in[a[i]]++;
    //    cout<<i<<" "<<x<<" "<<y<<" "<<dp[a[i]]<<" "<<ans<<"\n";
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

