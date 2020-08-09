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

ll fact[100005], inv[100005];

ll ncr(ll n, ll r)
{
    if (n == 0 && r == 0)
        return 1;
    if (r > n || n == 0 || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(inv[r], inv[n - r], mod), mod);
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

    fact[0] = 1, inv[0] = 1;
    f(1, 100005) fact[i] = mul(fact[i - 1], i, mod), inv[i] = powmod(fact[i], mod - 2);
    ll f, w, h, ans = 0, tot = 0;
    cin >> f >> w >> h;
    if (f == 0 || w == 0)
    {
        if (w > h || w == 0)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    f(1, min(w, f) + 2)
    {
        tot = add(tot, mul(2, mul(ncr(w - 1, i - 1), ncr(f - 1, i - 1), mod), mod), mod);
        tot = add(tot, mul(ncr(w - 1, i - 1), ncr(f - 1, i - 2), mod), mod);
        tot = add(tot, mul(ncr(f - 1, i - 1), ncr(w - 1, i - 2), mod), mod);
        ll k = w - (i * h);
        if (k < i)
            continue;
        k = ncr(k - 1, i - 1);
        ans = add(ans, mul(k, ncr(f - 1, i - 2), mod), mod);
        ans = add(ans, mul(2, mul(k, ncr(f - 1, i - 1), mod), mod), mod);
        ans = add(ans, mul(k, ncr(f - 1, i), mod), mod);
    }
    ans = mul(ans, powmod(tot, mod - 2), mod);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}