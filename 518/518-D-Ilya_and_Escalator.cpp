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
ld dp[2005][2005];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    ld p;
    cin>>n>>p>>t;
    dp[1][1] = p;   dp[1][0] = 1 - p;
    if(t == 1)
    {
        cout<<p;
        return 0;
    }
    ld ans = 0;
    f(2, t+1)
    {
        fi(0, i+1)
        {
            if(j > n)
                break;
            if(j == 0)
                dp[i][j] += dp[i-1][j] * (1-p);
            else
            {
                if(j == n)
                    dp[i][j] += dp[i-1][j],
                    dp[i][j] += dp[i-1][j-1] * p;
                else
                    dp[i][j] += dp[i-1][j] * (1-p),
                    dp[i][j] += dp[i-1][j-1] * p;
            }
       //     cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
    }
    f(0, t+1)   ans += i * dp[t][i];
    cout<<fixed<<setprecision(15)<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

