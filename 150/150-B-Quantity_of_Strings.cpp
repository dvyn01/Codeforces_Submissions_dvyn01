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

ll a[2005];

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

ll root(ll i)
{
    while (i != a[i])
        i = a[i];
    return i;
}

void merge(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return;
    a[xr] = yr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    f(1, 2005) a[i] = i;
    if (k > n || k == 1)
    {
        ll ans = powmod(m, n);
        cout << ans;
        return 0;
    }
    ll b[n + 1];
    memset(b, 0, sizeof(b));
    f(1, k / 2 + 1)
        b[i] = i;
    if (k & 1)
        b[k / 2 + 1] = k / 2 + 1;
    ll p = k / 2 + 1;
    if (k & 1)
        p++;
    ll l = k / 2;
    while (l > 0)
        b[p++] = a[l--];
    f(p, n + 1)
        b[i] = b[i - k + 1];
    ll cl = 1, cr = k;
    while (cr <= n)
    {
        ll l = cl, r = cr;
        while (l <= r)
            merge(b[l++], b[r--]);
        cl++;
        cr++;
    }
    p = k / 2;
    if (k & 1)
        p++;
    ll ans = 0;
    f(1, p + 1) if (a[i] == i) ans++;
    ans = powmod(m, ans);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}