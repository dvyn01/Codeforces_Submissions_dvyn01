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

ll n, m, level[200005], p[200005][20];
vll adj[200005];

void dfs(ll x, ll pr)
{
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr)
        {
            level[adj[x][i]] = level[x] + 1;
            p[adj[x][i]][0] = x;
            dfs(adj[x][i], x);
        }
    }
}

void pre()
{
    fi(1, 20)
        f(1, n + 1) if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
}

ll lca(ll u, ll v)
{
    if (level[u] > level[v])
        swap(u, v);
    ll d = level[v] - level[u];
    while (d)
    {
        ll raise = log2(d);
        d -= 1LL << raise;
        v = p[v][raise];
    }
    if (u == v)
        return u;
    fr(19, 0) if (p[u][j] != p[v][j]) u = p[u][j], v = p[v][j];
    return p[u][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    dfs(1, -1);
    pre();
    while (m--)
    {
        ll k;
        cin >> k;
        ll x = 0, cl = 0;
        vll v;
        v.resize(k);
        f(0, k)
        {
            cin >> v[i];
            if (level[v[i]] > cl)
                cl = level[v[i]], x = v[i];
        }
        bool ok = true;
        f(0, k)
        {
            if (v[i] == x)
                continue;
            ll l = lca(v[i], x);
            if (!((l == v[i]) || (l == p[v[i]][0])))
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}