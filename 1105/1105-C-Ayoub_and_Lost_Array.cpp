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
ll n, l, r, oc, tc, thc, dp[200050][3];

ll rec(ll in, ll cm)
{
    if(in == n && cm == 0)
        return 1;
    if(in >= n)
        return 0;
    if(dp[in][cm] != -1)
        return dp[in][cm];
    ll k = 0;
    if(oc != 0)     k = (k + (oc * rec(in + 1, (cm + 1) % 3)) % mod) % mod;
    if(tc != 0)     k = (k + (tc * rec(in + 1, (cm + 2) % 3)) % mod) % mod;
    if(thc != 0)    k = (k + (thc * rec(in + 1, cm)) % mod) % mod;
    return dp[in][cm] = k;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l>>r;
    ll x = r-l+1;
    oc += x/3;  tc += x/3;  thc += x/3;
    memset(dp, -1, sizeof(dp));
    if(x % 3 != 0)
    {
        if(x % 3 == 1)
        {
            if(l % 3 == 1)
                oc++;
            else if(l % 3 == 2)
                tc++;
            else thc++;
        }
        else
        {
            if(l % 3 == 1)
            {
                oc++;   tc++;
            }
            else if(l % 3 == 2)
            {
                tc++;   thc++;
            }
            else    { thc++;    oc++;   }
        }
    }
    ll ans = rec(0, 0);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

