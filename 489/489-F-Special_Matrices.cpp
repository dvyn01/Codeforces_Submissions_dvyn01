#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
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

ll n, m, mod, c[501];
map<pair<ll, pair<ll, ll>>, ll> dp;

ll rec(ll in, ll o, ll t)
{
    if (in == n + 1)
        return 1;
    if (dp.find({in, {o, t}}) != dp.end())
        return dp[{in, {o, t}}];
    ll k = 0;
    if (t > 1)
        k = add(k, mul((t * (t - 1) / 2) % mod, rec(in + 1, o + 2, t - 2), mod), mod);
    if (o > 1)
        k = add(k, mul((o * (o - 1) / 2) % mod, rec(in + 1, o - 2, t), mod), mod);
    if (o > 0 && t > 0)
        k = add(k, mul((o * t) % mod, rec(in + 1, o, t - 1), mod), mod);
    return dp[{in, {o, t}}] = k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> mod;
    f(0, m)
    {
        string s;
        cin >> s;
        fi(0, s.length()) if (s[j] == '1')
            c[j + 1]++;
    }
    ll o = 0, t = 0;
    f(1, n + 1)
    {
        if (c[i] == 1)
            o++;
        else if (c[i] == 0)
            t++;
    }
    ll ans = rec(m + 1, o, t);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}