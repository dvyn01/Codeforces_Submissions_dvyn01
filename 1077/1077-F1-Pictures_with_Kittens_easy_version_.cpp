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
ll n, k, x, a[210];
ll dp[205][205][205];

ll rec(ll i, ll pc, ll r)
{
//    cout<<i<<" "<<pc<<" "<<r<<"\n";
    if(r == 0 && n-i+1 <= k-1)
        return 0;
    if(r == 0)
        return -1e18;
    if(i > n && r > 0)
        return -1e18;
    if(i > n)
        return 0;
    if(dp[i][r][pc] != -1)
        return dp[i][r][pc];
    ll p = -1e18;
    p = rec(i+1, 0, r-1) + a[i];
    if(pc < k-1 && (n - i) >= r)
        p = max(p, rec(i+1, pc+1, r));
    return dp[i][r][pc] = p;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>x;
    memset(dp, -1, sizeof(dp));
    f(1, n+1)       cin>>a[i];
    if(k == 1)
    {
        if(x < n)
        {
            cout<<-1;
            return 0;
        }
        ll s = 0;
        f(1, n+1)   s += a[i];
        cout<<s;
        return 0;
    }
    ll ans = rec(1, 0, x);
    if(ans < 0)
        cout<<-1;
    else
        cout<<ans<<"\n";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
