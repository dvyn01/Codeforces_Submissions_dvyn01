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

vll primes;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f(2, 30)
    {
        bool ok = true;
        fi(2, i)
        {
            if (i % j == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            primes.pb(i);
    }
    ll n;
    cin >> n;
    vll v;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll c = 0;
            while (n % i == 0)
                v.pb(i - 1), n /= i;
        }
    }
    if (n > 1)
        v.pb(n - 1);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ans = 1, current = 1;
    f(0, v.size())
    {
        if (i == 0)
        {
            current *= v[i] + 1;
            ans *= pow(primes[i], v[i]);
            continue;
        }
        if (i == 1)
        {
            current *= v[i] + 1;
            ans *= pow(primes[i], v[i]);
            continue;
        }
        ll k1 = pow(primes[i], v[i]);
        ll tot = (current * (v[i] + 1)) / (current / (v[0] + 1)) - 1;
        if (pow(2, tot - v[0]) < k1)
            ans *= pow(2, tot - v[0]), v[0] = tot;
        else
            ans *= k1;
        current *= v[i] + 1;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}