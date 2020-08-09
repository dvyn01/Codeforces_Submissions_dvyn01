#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 998244353
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

inline ll mul(ll x, ll y, ll m)
{
    x %= mod;
    y %= mod;
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

ll dp[1050][20][2], dp1[1050][20][2], ans, n, k;
string s;

ll rec(ll mask, ll in, ll t)
{
    if (in == n)
        return __builtin_popcount(mask) <= k;
    if (dp[mask][in][t] != -1)
        return dp[mask][in][t];
    ll x = 9;
    if (t == 1)
        x = s[in] - '0';
    dp[mask][in][t] = 0;
    f(0, x + 1)
    {
        ll t1 = t;
        if (t == 1 && (i < (s[in] - '0')))
            t1 = 0;
        if (mask == 0 && i == 0)
        {
            ans = add(ans, dp1[mask][in + 1][t1], mod);
            dp[mask][in][t] = add(dp[mask][in][t], rec(mask, in + 1, t1), mod);
            dp1[mask][in][t] = add(dp1[mask][in][t], dp1[mask][in + 1][t], mod);
        }
        else
        {
            ans = add(ans, dp1[mask | (1LL << i)][in + 1][t1], mod);
            ll p = rec(mask | (1LL << i), in + 1, t1);
            ans = add(ans, mul(mul(i, pow(10, n - in - 1), mod), p, mod), mod);
            dp1[mask][in][t] = add(dp1[mask][in][t], dp1[mask | (1LL << i)][in + 1][t], mod);
            dp[mask][in][t] = add(dp[mask][in][t], p, mod);
            dp1[mask][in][t] = add(dp1[mask][in][t], mul(mul(i, pow(10, n - in - 1), mod), p, mod), mod);
        }
    }
    return dp[mask][in][t];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    cin >> l >> r >> k;
    l--;
    while (r)
        s.pb('0' + (r % 10)), r /= 10;
    reverse(s.begin(), s.end());
    n = s.length();
    memset(dp, -1, sizeof(dp));
    rec(0, 0, 1);
    ll ans1 = ans;
    ans = 0;
    s.clear();
    while (l)
        s.pb('0' + (l % 10)), l /= 10;
    reverse(s.begin(), s.end());
    n = s.length();
    memset(dp, -1, sizeof(dp));
    memset(dp1, 0, sizeof(dp1));
    rec(0, 0, 1);
    ans1 = sub(ans1, ans, mod);
    cout << ans1;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}