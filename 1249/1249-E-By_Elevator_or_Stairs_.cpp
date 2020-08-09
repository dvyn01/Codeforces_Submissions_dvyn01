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
 
ll n, c, a[200050], b[200050], dp[200050][2]; //  stairs, elevator
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> c;
    f(2, n + 1) cin >> a[i];
    f(2, n + 1) cin >> b[i];
    dp[2][0] = a[2], dp[2][1] = b[2] + c;
    f(3, n + 1)
    {
        dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        dp[i][1] = min(dp[i - 1][1] + b[i], dp[i - 1][0] + c + b[i]);
    }
    f(1, n + 1) cout << min(dp[i][0], dp[i][1]) << " ";
 
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}