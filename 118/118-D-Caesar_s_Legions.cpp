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
#define mod 100000000
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
ll k1, k2, n1, n2;
ll dp[101][101][2][101];

ll rec(ll c1, ll c2, ll lc, ll c)
{
    if(c1 < 0 || c2 < 0)
        return 0;
    if(dp[c1][c2][lc][c] != -1)
        return dp[c1][c2][lc][c];
    if(lc == 0 && c > k1)
        return 0;
    if(lc == 1 && c > k2)
        return 0;
    if(c1 == 0 && c2 == 1)
    {
        if(lc == 0)
            return 1;
        if(c < k2)
            return 1;
        return 0;
    }
    if(c1 == 1 && c2 == 0)
    {
        if(lc == 1)
            return 1;
        if(c < k1)
            return 1;
        return 0;
    }
    ll p = 0;
    if(lc == 0)
        p = (rec(c1 - 1, c2, 0, c + 1) % mod + rec(c1, c2 - 1, 1, 1) % mod) % mod;
    if(lc == 1)
        p = (rec(c1, c2 - 1, 1, c + 1) % mod + rec(c1 - 1, c2, 0, 1) % mod) % mod;
    if(lc == -1)
        p = (rec(c1 - 1, c2, 0, 1) % mod + rec(c1, c2 - 1, 1, 1) % mod) % mod;
    return dp[c1][c2][lc][c] = p;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
    ll ans = rec(n1, n2, -1, 0);
    cout<<ans % mod;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

