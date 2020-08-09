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

ll dp[100050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    dp[0] = 1;
    bool ok = true;
    if (s[0] == 'm' || s[0] == 'w')
        ok = false;
    f(1, s.length())
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            ok = false;
            break;
        }
        if (s[i] == 'n' && s[i - 1] == 'n')
        {
            if (i == 1)
                dp[i] = add(dp[i], 1, mod);
            dp[i] = add(dp[i], dp[i - 1], mod);
            dp[i] = add(dp[i], dp[i - 2], mod);
        }
        else if (s[i] == 'u' && s[i - 1] == 'u')
        {
            if (i == 1)
                dp[i] = add(dp[i], 1, mod);
            dp[i] = add(dp[i], dp[i - 1], mod);
            dp[i] = add(dp[i], dp[i - 2], mod);
        }
        else
        {
            dp[i] = add(dp[i], dp[i - 1], mod);
        }
    }
    if (!ok)
        cout << 0;
    else
        cout << dp[s.length() - 1];

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}