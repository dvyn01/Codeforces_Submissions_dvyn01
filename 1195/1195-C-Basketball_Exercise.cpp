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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n], b[n];
    f(0, n) cin >> a[i];
    f(0, n) cin >> b[i];
    ll dp[n + 5][2];
    memset(dp, 0, sizeof(dp));
    ll ans = 0;
    dp[n - 1][0] = a[n - 1];
    dp[n - 1][1] = b[n - 1];
    ll mx0 = dp[n - 1][0], mx1 = dp[n - 1][1];
    ans = max(mx0, mx1);
    fr(n - 2, 0)
    {
        dp[j][0] = a[j] + mx1;
        dp[j][1] = b[j] + mx0;
        mx0 = max(mx0, dp[j][0]);
        mx1 = max(mx1, dp[j][1]);
        ans = max(ans, max(dp[j][0], dp[j][1]));
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}