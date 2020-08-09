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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll dp[100050];

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
    ll a[n];
    f(0, n)     cin>>a[i];
    dp[n-1] = abs(a[n-1]);
    ll cps = 0, cns = 0;
    if(a[n-1] <= 0)
        cns = dp[n-1];
    else cps = dp[n-1];
    fr(n-2, 0)
    {
        if(a[j] <= 0)
        {   dp[j] = max(dp[j+1] + a[j], cns - a[j] - cps);    cns += abs(a[j]);   }
        else {  dp[j] = max(dp[j+1] + a[j], cps + a[j] - cns);    cps += a[j];    }
    }
  //  f(0, n)     cout<<dp[i]<<" ";   cout<<"\n";
    ll ans = 0;
    cps = 0;    cns = 0;
    f(0, n)
    {
        if(a[i] <= 0)   cns += abs(a[i]);
        else cps += a[i];
        ans = max(ans, max(dp[i+1] + cns - cps, dp[i+1] + cps - cns));
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

