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
ll a, b, h, w, n, x;
vll v;
unordered_map<ll, unordered_map<ll, unordered_map<ll, ll> > > dp;

ll rec(ll i, ll ch, ll cw)
{
    if(max(ch, cw) >= max(a, b) && min(ch, cw) >= min(a, b))
        return 0;
    if(i >= n)
        return 1e18;
    if(dp[i][max(ch, cw)][min(cw, ch)] != 0)
        return dp[i][max(ch, cw)][min(cw, ch)];
    ll k = 1e18;
    if(max(ch, cw) < max(a, b) && min(ch, cw) < min(a, b))
        k = min(k, min(1 + rec(i+1, max(ch, cw) * v[i], min(ch, cw)), 1 + rec(i+1, max(ch, cw), min(ch, cw) * v[i])));
    else if(min(ch, cw) < min(a, b))
        k = min(k, 1 + rec(i+1, min(ch, cw) * v[i], max(ch, cw)));
    else if(max(ch, cw) < max(a, b))
        k = min(k, 1 + rec(i+1, max(ch, cw) * v[i], min(ch, cw)));
    return dp[i][max(ch, cw)][min(cw, ch)] = k;
}

bool compare(ll a, ll b)
{
    return a > b;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>h>>w>>n;
    f(0, n)     cin>>x,     v.pb(x);
    sort(v.begin(), v.end(), compare);
    ll ans = rec(0, h, w);
    if(ans >= 1e18)
        ans = -1;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

