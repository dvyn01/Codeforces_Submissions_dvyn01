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

ll p[100005][18], level[100005], n;
vll adj[100005];

void dfs(ll x, ll pr)
{
    p[x][0] = pr;
    f(0, adj[x].size()) if (adj[x][i] != pr)
        level[adj[x][i]] = level[x] + 1,
        dfs(adj[x][i], x);
}

void pre()
{
    fi(1, 18)
        f(1, n + 1) if (p[i][j - 1] != -1)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

ll dist(ll u, ll v)
{
    ll c = 0;
    if (level[u] > level[v])
        swap(u, v);
    ll d = level[v] - level[u];
    while (d)
    {
        ll raise = log2(d);
        c += (1LL << raise);
        v = p[v][raise];
        d -= (1LL << raise);
    }
    if (u == v)
        return c;
    fr(17, 0) if (p[u][j] != p[v][j])
        u = p[u][j],
        v = p[v][j], c += (1LL << (j + 1));
    c += 2;
    return c;
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
    cin >> n;
    memset(p, -1, sizeof(p));
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    ll q;
    cin >> q;
    dfs(1, -1);
    pre();
    while (q--)
    {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        ll ab = dist(a, b), ax = dist(a, x), ay = dist(a, y), bx = dist(b, x), by = dist(b, y);
        if (k >= ab && (k & 1) == (ab & 1))
            cout << "YES\n";
        else if (k >= ax + by + 1 && ((ax + by + 1) & 1) == (k & 1))
            cout << "YES\n";
        else if (k >= ay + bx + 1 && ((ay + bx + 1) & 1) == (k & 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}