/*
    * AUTHOR : Divyanshu *
*/

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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

ll dp[100005][4], n, ans;   // 0: Nothing, 1: a[i] > b[i], 2: a[i] < b[i], 4: both
string a, b;

ll powmod(ll x, ll y)
{
    ll r = 1;
    while (y)
    {
        if (y & 1)
            r = mul(r, x, mod);
        y >>= 1;
        x = mul(x, x, mod);
    }
    return r;
}

// Don't forget MOD

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> a >> b;
    if(a[0] != '?' && b[0] != '?')
    {
        if(a[0] > b[0])
            dp[0][1] = 1;
        else if(b[0] > a[0])
            dp[0][2] = 1;
        else dp[0][0] = 1;
    }
    else
    {
        if(a[0] == '?' && b[0] == '?')
            dp[0][0] = 10, dp[0][1] = 45, dp[0][2] = 45;
        else if(a[0] == '?')
            dp[0][0] = 1, dp[0][1] = '9' - b[0], dp[0][2] = b[0] - '0';
        else if(b[0] == '?')
            dp[0][0] = 1, dp[0][2] = '9' - a[0], dp[0][1] = a[0] - '0';
    }
    // cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<" "<<dp[0][3]<<'\n';
    f(1, n)
    {
        if(a[i] == '?' and b[i] == '?')
        {
            if(dp[i-1][0] != 0)
                dp[i][0] += mul(dp[i-1][0], 10, mod), dp[i][1] += mul(dp[i-1][0], 45, mod), dp[i][2] += mul(dp[i-1][0], 45, mod);
            if(dp[i-1][1] != 0)
                dp[i][1] += mul(dp[i-1][1], 55, mod), dp[i][3] += mul(dp[i-1][1], 45, mod);
            if(dp[i-1][2] != 0)
                dp[i][2] += mul(dp[i-1][2], 55, mod), dp[i][3] += mul(dp[i-1][2], 45, mod);
            if(dp[i-1][3] != 0)
                dp[i][3] += mul(dp[i-1][3], 100, mod);
        }
        else if(a[i] == '?')
        {
            if(dp[i-1][0] != 0)
                dp[i][0] += mul(dp[i-1][0], 1, mod), dp[i][1] += mul(dp[i-1][0], '9' - b[i], mod), dp[i][2] += mul(dp[i-1][0], b[i] - '0', mod);
            if(dp[i-1][1] != 0)
                dp[i][1] += mul(dp[i-1][1], '9' - b[i] + 1, mod), dp[i][3] += mul(dp[i-1][1], b[i] - '0', mod);
            if(dp[i-1][2] != 0)
                dp[i][2] += mul(dp[i-1][2], b[i] - '0' + 1, mod), dp[i][3] += mul(dp[i-1][2], '9' - b[i], mod);
            if(dp[i-1][3] != 0)
                dp[i][3] += mul(dp[i-1][3], 10, mod);
        }
        else if(b[i] == '?')
        {
            if(dp[i-1][0] != 0)
                dp[i][0] += mul(dp[i-1][0], 1, mod), dp[i][1] += mul(dp[i-1][0], a[i] - '0', mod), dp[i][2] += mul(dp[i-1][0], '9' - a[i], mod);
            if(dp[i-1][1] != 0)
                dp[i][1] += mul(dp[i-1][1], a[i] - '0' + 1, mod), dp[i][3] += mul(dp[i-1][1], '9' - a[i], mod);
            if(dp[i-1][2] != 0)
                dp[i][2] += mul(dp[i-1][2], '9' - a[i] + 1, mod), dp[i][3] += mul(dp[i-1][2], a[i] - '0', mod);
            if(dp[i-1][3] != 0)
                dp[i][3] += mul(dp[i-1][3], 10, mod);
        }
        else
        {
            if(a[i] == b[i])
                fi(0, 4)    dp[i][j] += dp[i-1][j];
            else if(a[i] > b[i])
                dp[i][1] += dp[i-1][1], dp[i][1] += dp[i-1][0], dp[i][3] += dp[i-1][3], dp[i][3] += dp[i-1][2];
            else
                dp[i][2] += dp[i-1][2], dp[i][2] += dp[i-1][0], dp[i][3] += dp[i-1][3], dp[i][3] += dp[i-1][1];
        }
        dp[i][0] %= mod, dp[i][1] %= mod, dp[i][2] %= mod, dp[i][3] %= mod;
    }
    // cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<" "<<dp[n-1][2]<<" "<<dp[n-1][3]<<'\n';
    cout<<dp[n-1][3];

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}