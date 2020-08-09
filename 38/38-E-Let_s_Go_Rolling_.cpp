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
ll n, dp[3005][3005];
pll p;

ll rec(ll i, ll li)
{
    if(i >= n)
        return 0;
    if(dp[i][li] != -1)
        return dp[i][li];
    ll wow = 1e18;
    if(i == 0)
        wow = rec(i+1, i) + p[i].second;
    else wow = min(rec(i+1, i) + p[i].second, rec(i+1, li) + p[i].first - p[li].first);
    return dp[i][li] = wow;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, c;
    cin>>n;
    f(0, n)     cin>>x>>c,      p.pb(mp(x, c));
    memset(dp, -1, sizeof(dp));
    sort(p.begin(), p.end());
    ll ans = rec(0, 0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

