#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 998244353
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

ll reverse(ll n)
{
    ll r = 0;
    while (n)
    {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

ll numberOfDigits(ll n)
{
    ll r = 0;
    while (n)
    {
        r++;
        n /= 10;
    }
    return r;
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

ll bada(ll n, ll k)
{
    ll r = 1;
    ll lead = 0, temp = n;
    while (temp)
    {
        if (temp % 10)
            break;
        lead++;
        temp /= 10;
    }
    if (k <= lead)
        return mul(n, powmod(10, k), mod);
    k -= lead;
    n = reverse(n);
    bool done = false;
    ll y = 0;
    ll dd = numberOfDigits(n);
    while (n)
    {
        if (!done)
        {
            ll x = n % 10;
            done = true;
            r = 10 * x;
        }
        else
        {
            ll x = n % 10;
            if (y > dd - k)
                r = mul(r, 100, mod);
            else
                r = mul(r, 10, mod);
            r = add(r, x * 10, mod);
        }
        y++;
        n /= 10;
    }
    r = mul(r, powmod(10, 2 * lead), mod);
    return r;
}

ll chota(ll n, ll k)
{
    ll r = 0;
    ll lead = 0, temp = n;
    while (temp)
    {
        if (temp % 10)
            break;
        lead++;
        temp /= 10;
    }
    if (k <= lead)
        return mul(n, powmod(10, k), mod);
    k -= lead;
    n = reverse(n);
    ll y = 0;
    ll dd = numberOfDigits(n);
    while (n)
    {
        ll x = n % 10;
        if (y >= dd - k)
            r = mul(r, 100, mod);
        else
            r = mul(r, 10, mod);
        r = add(r, x, mod);
        n /= 10;
        y++;
    }
    r = mul(r, powmod(10, 2 * lead), mod);
    return r;
}

// ll bada(ll n)
// {
//     ll r = 1;
//     ll lead = 0, temp = n;
//     while (temp)
//     {
//         if (temp % 10)
//             break;
//         lead++;
//         temp /= 10;
//     }
//     n = reverse(n);
//     bool done = false;
//     while (n)
//     {
//         if (!done)
//         {
//             ll x = n % 10;
//             done = true;
//             r = 10 * x;
//         }
//         else
//         {
//             ll x = n % 10;
//             r = mul(r, 100, mod);
//             r = add(r, x * 10, mod);
//         }
//         n /= 10;
//     }
//     r = mul(r, powmod(10, 2 * lead), mod);
//     return r;
// }

// ll chota(ll n)
// {
//     ll r = 0;
//     ll lead = 0, temp = n;
//     while (temp)
//     {
//         if (temp % 10)
//             break;
//         lead++;
//         temp /= 10;
//     }
//     n = reverse(n);
//     while (n)
//     {
//         ll x = n % 10;
//         r = mul(r, 100, mod);
//         r = add(r, x, mod);
//         n /= 10;
//     }
//     r = mul(r, powmod(10, 2 * lead), mod);
//     return r;
// }


ll d[11];

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
    vll a;
    a.resize(n);
    f(0, n) cin >> a[i], d[numberOfDigits(a[i])]++;
    ll ans = 0;
    f(0, n)
    {
        ll x = numberOfDigits(a[i]);
        fi(1, 11)
        {
            if (j <= x - 1)
            {
                ans = add(ans, mul(d[j], chota(a[i], j), mod), mod);
                // cout << a[i] << " " << j << " " << chota(a[i], j) << "\n";
                ans = add(ans, mul(d[j], bada(a[i], j), mod), mod);
                // cout << a[i] << " " << j << " " << bada(a[i], j) << "\n";
            }
            else
            {
                ans = add(ans, mul(d[j], chota(a[i], x), mod), mod);
                // cout << a[i] << " " << j << " " << chota(a[i], x) << "\n";
                ans = add(ans, mul(d[j], bada(a[i], x), mod), mod);
                // cout << a[i] << " " << j << " " << bada(a[i], x) << "\n";
            }
        }
        // cout << ans << "\n";
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}