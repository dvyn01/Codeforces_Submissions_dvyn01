#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

ll a[200005], p[200005], s[200005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    f(0, n) cin >> a[i], m[a[i]]++;
    for (auto it : m)
    {
        if (it.second >= k)
        {
            cout << 0;
            return 0;
        }
    }
    sort(a, a + n);
    ll ans = 1e18, ca = 0;
    f(0, k)
    {
        if (a[i] == a[k - 1])
            break;
        ca += a[k - 1] - a[i] - 1;
    }
    ans = min(ans, ca + k - m[a[k - 1]]);
    ca = 0;
    fr(n - 1, n - k)
    {
        if (a[j] == a[n - k])
            break;
        ca += a[j] - a[n - k] - 1;
    }
    ans = min(ans, ca + k - m[a[n - k]]);
    p[0] = a[0], s[n - 1] = a[n - 1];
    f(1, n) p[i] = p[i - 1] + a[i];
    fr(n - 2, 0) s[j] = s[j + 1] + a[j];
    f(0, n)
    {
        if (i != 0 && a[i] == a[i - 1])
            continue;
        ll k1 = 0, k2 = 0;
        ll j = i + m[a[i]];
        if (i > 0)
            k1 += (a[i] - 1) * i - p[i - 1];
        if (j < n)
            k2 += s[j] - (n - j) * (a[i] + 1);
        ans = min(ans, k1 + k2 + k - m[a[i]]);
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}