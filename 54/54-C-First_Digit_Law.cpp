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

ld dp[1050][1050];
ll l[1050], r[1050];

ll countOnes(ll l, ll r)
{
    ll c = 0;
    while (l <= r)
    {
        ll x = log10(l);
        x = pow(10, x);
        ll y = min(r, 2 * x - 1);
        if (y >= l)
            c += (y - l + 1);
        if(l == 1e18)
            break;
        l = pow(10, long(log10(l)) + 1);
    }
    return c;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n;
    f(1, n + 1) cin >> l[i] >> r[i];
    cin >> k;
    dp[1][1] = countOnes(l[1], r[1]) * 1.0 / (r[1] - l[1] + 1) * 1.0;
    dp[1][0] = 1.0 - dp[1][1];
    f(2, n + 1)
    {
        ld ones = countOnes(l[i], r[i]) * 1.0, total = (r[i] - l[i] + 1) * 1.0;
        fi(0, i + 1)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][0] * (total - ones) * 1.0 / total * 1.0;
            else
                dp[i][j] = dp[i - 1][j] * (total - ones) * 1.0 / total * 1.0 + dp[i - 1][j - 1] * ones * 1.0 / total * 1.0;
        }
    }
    ld p = k * n * 1.0 / 100 * 1.0;
    ll s = p;
    if (p != s)
        s++;
    ld ans = 0;
    f(s, n + 1)
        ans += dp[n][i];
    cout << fixed << setprecision(15) << ans;
    // f(0, n+1)   cout<<dp[1][i]<<" "<<dp[2][i]<<"\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}