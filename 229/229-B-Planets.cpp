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

const ll N = 100005;

ll n;
pll adj[N];
vll v[N];

ll dij()
{
    ll d[n + 1];
    f(2, n + 1) d[i] = 1e18;
    set<pair<ll, ll>> s;
    s.insert({0, 1});
    d[1] = 0;
    while (!s.empty())
    {
        ll u = s.begin()->second, t = s.begin()->first;
        s.erase(s.begin());
        if (u == n)
            return t;
        ll k = lower_bound(v[u].begin(), v[u].end(), t) - v[u].begin();
        if (k != v[u].size() && v[u][k] == t)
        {
            s.insert({t + 1, u});
            continue;
        }
        f(0, adj[u].size()) if (d[adj[u][i].first] > t + adj[u][i].second)
            d[adj[u][i].first] = t + adj[u][i].second,
            s.insert({d[adj[u][i].first], adj[u][i].first});
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, x, y, w;
    cin >> n >> m;
    f(0, m) cin >> x >> y >> w, adj[x].pb({y, w}), adj[y].pb({x, w});
    f(1, n + 1)
    {
        cin >> x;
        fi(0, x) cin >> y, v[i].pb(y);
    }
    cout << dij();

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}