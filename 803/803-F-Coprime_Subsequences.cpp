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

const ll N = 100005;
ll b[N];

void sieve()
{
    f(1, N) b[i] = i;
    f(2, N)
    {
        if (b[i] == i)
        {
            fi(i * i, N)
            {
                if (b[j] == j)
                    b[j] = i;
                j += i - 1;
            }
        }
    }
}

unordered_map<ll, ll> m[10];

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

    sieve();
    ll n;
    cin >> n;
    ll a[n];
    f(0, n) cin >> a[i];
    f(0, n)
    {
        vll v;
        while (a[i] != 1)
        {
            ll x = b[a[i]];
            while (a[i] % x == 0)
                a[i] /= x;
            v.pb(x);
        }
        fi(1, 1LL << v.size())
        {
            ll c = 1;
            fii(0, v.size()) if (j & (1LL << k)) c *= v[k];
            m[__builtin_popcount(j)][c]++;
        }
    }
    ll ans = 0;
    f(1, 7)
    {
        for (auto it : m[i])
        {
            if (i & 1)
                ans = add(ans, sub(powmod(2, it.second), 1, mod), mod);
            else
                ans = sub(ans, sub(powmod(2, it.second), 1, mod), mod);
        }
    }
    ans = sub(sub(powmod(2, n), 1, mod), ans, mod);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}