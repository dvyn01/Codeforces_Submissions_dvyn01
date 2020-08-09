#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ld dp[10005][1005];                                          // Day, Number of different orbs

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin>>k;
    dp[1][1] = 1;
    f(2, 10005)
    {
        fi(1, 1005)
        {
            if(j > i || j > k)
                break;
            if(dp[i-1][j] > 0)
                dp[i][j] += dp[i-1][j] * double(j * 1.0 / k * 1.0);
            if(dp[i-1][j-1] > 0)
                dp[i][j] += dp[i-1][j-1] * double((k - j + 1) * 1.0 / k * 1.0) * 1.0;
         }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ld p;
        cin>>p;
        p -= 0.0000007;
        p /= 2000 * 1.0;
        // cout<<p<<"\n";
        f(1, 10005)
        {
            // cout<<i<<" "<<dp[i][k]<<"\n";
            if(dp[i][k] >= p)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}