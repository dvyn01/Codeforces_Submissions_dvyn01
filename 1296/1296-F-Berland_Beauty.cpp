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

pll adj[5005];
ll n, m, c;
vector<pair<ll, pair<ll, ll>>> p;
ll wow[5005][5005];

bool dfs(ll x, ll pr, ll y)
{
    if (x == y)
        return true;
    bool k1 = false;
    f(0, adj[x].size())
    {
        if (adj[x][i].first != pr)
        {
            bool k = dfs(adj[x][i].first, x, y);
            k1 |= k;
            if (k)
                wow[x][adj[x][i].first] = c, wow[adj[x][i].first][x] = c;
        }
    }
    return k1;
}

bool check(ll x, ll pr, ll y)
{
    if (x == y)
        return true;
    bool k1 = false;
    f(0, adj[x].size())
    {
        if (adj[x][i].first != pr)
        {
            bool k = check(adj[x][i].first, x, y);
            k1 |= k;
            if (k)
                c = min(c, wow[x][adj[x][i].first]);
        }
    }
    return k1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, w;
    cin >> n;
    f(1, n + 1) fi(1, n + 1) wow[i][j] = 1000000;
    vll xx, yy;
    f(1, n) cin >> x >> y, adj[x].pb({y, 1e18}), adj[y].pb({x, 1e18}), xx.pb(x), yy.pb(y);
    cin >> m;
    f(0, m) cin >> x >> y >> w, p.pb({w, {x, y}});
    sort(p.begin(), p.end());
    f(0, p.size()) c = p[i].first, dfs(p[i].second.first, -1, p[i].second.second);
    f(0, p.size())
    {
        c = 1e18;
        check(p[i].second.first, -1, p[i].second.second);
        if (c != p[i].first)
        {
            cout << -1;
            return 0;
        }
    }
    f(0, n - 1)
        cout << wow[xx[i]][yy[i]] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}