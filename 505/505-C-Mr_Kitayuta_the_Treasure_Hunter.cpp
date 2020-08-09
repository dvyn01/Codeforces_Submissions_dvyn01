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
ll a[30005], n, d;
ll dp[30005][500];

ll rec(ll cp, ll l)
{
//    cout<<cp<<" "<<l<<"\n";
    ll xxx = l - (d - 250);
    if(cp > 30000)
        return 0;
    if(dp[cp][xxx] != -1)
        return dp[cp][xxx];
    ll k;
    k = max(rec(cp + l, l), rec(cp + l + 1, l + 1)) + a[cp];
    if(l > 1)
        k = max(k, a[cp] + rec(cp + l - 1, l - 1));
    return dp[cp][xxx] = k;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin>>n>>d;
    memset(dp, -1, sizeof(dp));
    f(1, n+1)       cin>>x,     a[x]++;
    ll ans = rec(d, d);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

