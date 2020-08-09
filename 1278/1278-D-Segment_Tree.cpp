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

ll a[500050], s[500050];

void init(ll n)
{
    f(0, n + 5) a[i] = i, s[i] = 1;
}

ll root(ll i)
{
    while (i != a[i])
        i = a[a[i]];
    return i;
}

bool merge(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return false;
    if (s[xr] >= s[yr])
        s[xr] += s[yr], a[yr] = xr;
    else
        s[yr] += s[xr], a[xr] = yr;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n;
    init(n);
    vector<pair<pair<ll, ll>, ll>> p;
    f(0, n) cin >> x >> y, p.pb({{y, x}, i + 1});
    if (n == 1)
    {
        cout << "YES";
        return 0;
    }
    sort(p.begin(), p.end());
    set<pair<ll, ll>> s;
    s.insert({p[n - 1].first.second, p[n - 1].second});
    fr(p.size() - 2, 0)
    {
        auto it = s.lower_bound({p[j].first.second, -1});
        auto it1 = s.upper_bound({p[j].first.first, -1});
        for (; it != it1; it++)
        {
            if (!merge(p[j].second, it->second))
            {
                cout << "NO";
                return 0;
            }
        }
        s.insert({p[j].first.second, p[j].second});
    }
    ll r = root(1);
    f(1, n + 1)
    {
        if (root(i) != r)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}