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
        ll n;
        cin >> n;
        ll a[n];
        f(0, n) cin >> a[i];
        ll mx = -1, mn = 1e18;
        f(0, n)
        {
            if (a[i] == -1)
            {
                if (i > 0 && a[i - 1] != -1)
                    mx = max(mx, a[i - 1]), mn = min(mn, a[i - 1]);
                if (i < n - 1 && a[i + 1] != -1)
                    mx = max(mx, a[i + 1]), mn = min(mn, a[i + 1]);
            }
        }
        ll m = 1e18, k = -1;
        if (mx == -1)
        {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        ll x = (mx + mn) / 2;
        fi(max(0LL, x - 10), min(1000000000LL, x + 10))
        {
            ll b[n];
            f(0, n) b[i] = a[i];
            f(0, n) if (b[i] == -1) b[i] = j;
            ll s1 = 0;
            f(0, n - 1) s1 = max(s1, abs(b[i + 1] - b[i]));
            if (s1 < m)
                m = s1, k = j;
        }
        cout << m << " " << k << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}