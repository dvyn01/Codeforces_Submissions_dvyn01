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
ll dp[3005];


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, ans = 1e18;
    cin>>n;
    ll a[n],    c[n];
    f(0, n)     cin>>a[i];
    f(0, n)     cin>>c[i];
    dp[n-1] = 1e18;
    fr(n-2, 0)
    {
        dp[j] = 1e18;
        f(j+1, n)
        {
            if(a[i] > a[j])
                dp[j] = min(dp[j], c[j] + c[i]);
        }
        f(j+1, n)
            if(a[i] > a[j] && dp[i] != 1e18)
                ans = min(ans, dp[i] + c[j]);
    }
    if(ans == 1e18)
        ans = -1;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

