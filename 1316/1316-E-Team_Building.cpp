#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
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

ll n, p, k, dp[100005][128];

struct datata
{
    ll a;
    vll v;
} d[100005];

bool compare(datata x, datata y)
{
    return x.a < y.a;
}

ll rec(ll in, ll mask)
{
    if (in > n)
        return 0;
    if (dp[in][mask] != -1)
        return dp[in][mask];
    ll x = 0;
    f(0, p) if (!(mask & (1LL << i)))
        x = max(x, d[in].v[i] + rec(in + 1, mask | (1LL << i)));
    if (in - __builtin_popcount(mask) <= k)
        x = max(x, d[in].a + rec(in + 1, mask));
    else
        x = max(x, rec(in + 1, mask));
    return dp[in][mask] = x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> k;
    f(1, n + 1) cin >> d[i].a;
    f(1, n + 1)
    {
        fi(0, p)
        {
            ll x;
            cin >> x;
            d[i].v.pb(x);
        }
    }
    sort(d + 1, d + n + 1, compare);
    reverse(d + 1, d + n + 1);
    ll ans = rec(1, 0);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}