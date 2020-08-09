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

ll calculate(vll v, ll n)
{
    ll r = 0;
    f(1, 1LL << v.size())
    {
        ll p = 1, x = 0;
        fi(0, v.size()) if ((1LL << j) & i) p *= v[j], x ^= 1;
        if (x)
            r += n / p;
        else
            r -= n / p;
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

    ll t;
    cin >> t;
    while (t--)
    {
        vll v;
        ll x, p, k, lx = 0, ans = 0;
        cin >> x >> p >> k;
        ll pp = p;
        for (ll i = 2; i * i <= p; i++)
        {
            if (p % i == 0)
            {
                v.pb(i);
                while (p % i == 0)
                    p /= i;
            }
        }
        if (p > 1)
            v.pb(p);
        p = pp;
        lx = calculate(v, x);
        ll l = x + 1, r = 10000000;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (mid - x - calculate(v, mid) + lx >= k)
            {
                if (__gcd(mid, p) == 1)
                    ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}