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
ll n, t;
ll dp[22][5][11][2];

ll rec(ll x, ll y, ll c, ll cn)
{
    if(x > n)
        return 0;
    if(x == n && cn == t && y > 0)
        return 1;
    if(y <= 0 || y > 4)
        return 0;
    if(dp[x][y][cn][c] != -1)
        return dp[x][y][cn][c];
    ll k = 0;
    if(cn == t)
        k += rec(x+1, y-1, 0, t) + rec(x+1, y-2, 0, t) + rec(x+1, y-3, 0, t);
    else
    {
        if(c == 1)
        {
            k += rec(x+1, y+1, 1, cn) + rec(x+1, y+2, 1, cn) + rec(x+1, y+3, 1, cn);
            k += rec(x+1, y-1, 0, cn + 1) + rec(x+1, y-2, 0, cn + 1) + rec(x+1, y-3, 0, cn + 1);
        }
        else
        {
            k += rec(x+1, y-1, 0, cn) + rec(x+1, y-2, 0, cn) + rec(x+1, y-3, 0, cn);
            k += rec(x+1, y+1, 1, cn) + rec(x+1, y+2, 1, cn) + rec(x+1, y+3, 1, cn);
        }
    }
    return dp[x][y][cn][c] = k;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>t;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    ans += rec(2, 2, 1, 0);
    ans += 2 * rec(2, 3, 1, 0);
    ans += 3 * rec(2, 4, 1, 0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

