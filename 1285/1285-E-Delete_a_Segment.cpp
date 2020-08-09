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

pll p;
ll n;
map<pair<pair<ll, ll>, ll>, ll> dp;

ll rec(ll in, ll r, ll c)
{
    if (in >= n)
    {
        if (c == 0)
            return 0;
        return -1e9;
    }
    if (dp.find({{in, r}, c}) != dp.end())
        return dp[{{in, r}, c}];
    ll k = 0;
    if (p[in].first > r)
        k = max(k, 1 + rec(in + 1, p[in].second, c));
    else
        k = max(k, rec(in + 1, max(r, p[in].second), c));
    if (c == 1)
        k = max(k, rec(in + 1, r, 0));
    // cout << in << " " << r << " " << c << " " << k << "\n";
    return dp[{{in, r}, c}] = k;
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
        ll x, y;
        cin >> n;
        map<ll, ll> m;
        p.clear();
        dp.clear();
        p.resize(n);
        f(0, n) cin >> p[i].first >> p[i].second, m[p[i].first]++, m[p[i].second]++;
        ll c = 1;
        for (auto it : m)
            m[it.first] = c++;
        f(0, n) p[i].first = m[p[i].first], p[i].second = m[p[i].second];
        sort(p.begin(), p.end());
        ll ans = rec(0, -1, 1);
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}