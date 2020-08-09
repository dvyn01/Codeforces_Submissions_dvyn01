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
    x %= mod;
    y %= mod;
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    x %= mod;
    y %= mod;
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    if (l == r)
    {
        cout << 1;
        return 0;
    }
    ll k = n * m;
    if (k & 1)
    {
        ll ans = powmod((r - l + 1), k);
        cout << ans;
    }
    else
    {
        ll even = (r - l + 1) / 2, odd = (r - l + 1) / 2;
        if ((r - l + 1) & 1)
        {
            if (l & 1)
                odd++;
            else
                even++;
        }
        ll k1 = powmod(add(even, odd, mod), k);
        ll k2 = powmod(sub(even, odd, mod), k);
        k1 = add(k1, k2, mod);
        k1 = mul(k1, powmod(2, mod - 2), mod);
        cout << k1;
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}