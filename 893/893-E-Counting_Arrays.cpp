/*
    * AUTHOR : Divyanshu *
*/

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

ll fact[2000005], inv[2000005], b[1000005];
vll v[1000005];

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

ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;
    return mul(fact[n], mul(inv[r], inv[n - r], mod), mod);
}

void sieve()
{
    f(1, 1000005) b[i] = i;
    f(2, 1000005)
    {
        if(b[i] != i)
            continue;
        fi(2 * i, 1000005)
        {
            if (b[j] == j)
                b[j] = i;
            j += i - 1;
        }
    }
}

vll factors(ll n)
{
    vll v;
    while (n != 1)
    {
        ll x = b[n], c = 0;
        while (n % x == 0)
            n /= x, c++;
        v.pb(c);
    }
    return v;
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
    fact[0] = 1;
    inv[0] = 1;
    f(1, 2000005)
        fact[i] = mul(fact[i - 1], i, mod),
        inv[i] = powmod(fact[i], mod - 2);
    f(1, 1000005)
        v[i] = factors(i);
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll ans = powmod(2, y - 1);
        // cout<<ans<<" ";
        f(0, v[x].size())
            ans = mul(ans, ncr(y + v[x][i] - 1, v[x][i]), mod);
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}