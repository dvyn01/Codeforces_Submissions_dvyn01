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
ll n, m, b, dp[(1LL << 20) + 5];
pair<ll, pair<ll, ll> > p[105];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>b;
    pll wow;
    f(0, n)
    {
        ll q;
        cin>>p[i].second.first>>p[i].first>>q;
        fi(0, q)
        {
            ll y;
            cin>>y;
            p[i].second.second += (1LL << (y-1));
        }
    }
    sort(p, p+n);
    ll ans = 3e18;
    f(1, 1LL << m)  dp[i] = 3e18;
    f(0, n)
    {
        for(ll j = 0; j < (1LL << m); j++)
        {
            if(dp[j] < 1e18)
            {
                ll xxx = j | p[i].second.second;
                dp[xxx] = min(dp[xxx], dp[j] + p[i].second.first);
            }
        }
        if(dp[(1LL << m) - 1] != 3e18)
            ans = min(ans, dp[(1LL << m) - 1] + b * p[i].first);
    }
    if(ans == 3e18)
        ans = -1;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

