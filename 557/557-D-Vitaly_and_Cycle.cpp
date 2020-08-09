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

ll n, m, vis[N], z, o, c[N];
bool cycle;
vll adj[N];

void dfs(ll x)
{
    if (cycle)
        return;
    f(0, adj[x].size())
    {
        if (c[adj[x][i]] == -1)
            c[adj[x][i]] = c[x] ^ 1, dfs(adj[x][i]);
        else if (c[adj[x][i]] == c[x])
        {
            cycle = true;
            return;
        }
    }
}

void dfs1(ll x, ll pr)
{
    vis[x] = true;
    if (c[x])
        o++;
    else
        z++;
    f(0, adj[x].size())
    {
        if (!vis[adj[x][i]])
            dfs1(adj[x][i], x);
    }
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
    f(0, m) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    if (m == 0)
    {
        cout << 3 << ' ' << ((n * (n - 1) * (n - 2)) / 6);
        return 0;
    }
    memset(c, -1, sizeof(c));
    f(1, n + 1) if (c[i] == -1) c[i] = 0, dfs(i);
    if (cycle)
    {
        cout << "0 1";
        return 0;
    }
    bool ok = false;
    f(1, n + 1) if (adj[i].size() > 1) ok = true;
    if (!ok)
    {
        cout << 2 << ' ' << m * (n - 2);
        return 0;
    }
    ll ans = 0;
    f(1, n + 1)
    {
        if (!vis[i])
        {
            z = 0, o = 0;
            dfs1(i, -1);
            ans += o * (o - 1) / 2 + z * (z - 1) / 2;
        }
    }
    cout << 1 << ' ' << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}