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

ll n, m, a[100050];
vll adj[200050], v[100050];
bool vis[200050];

void dfs(ll x)
{
    vis[x] = true;
    f(0, adj[x].size())
    {
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
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

    cin >> n >> m;
    f(1, n + 1) cin >> a[i];
    f(1, m + 1)
    {
        ll x, y;
        cin >> x;
        fi(0, x) cin >> y, v[y].pb(i);
    }
    f(1, n + 1)
    {
        ll v1 = v[i][0], v2 = v[i][1];
        if (a[i])
        {
            adj[v1 << 1].pb(v2 << 1);
            adj[v2 << 1].pb(v1 << 1);
            adj[v1 << 1 ^ 1].pb(v2 << 1 ^ 1);
            adj[v2 << 1 ^ 1].pb(v1 << 1 ^ 1);
        }
        else
        {
            adj[v1 << 1].pb(v2 << 1 ^ 1);
            adj[v2 << 1 ^ 1].pb(v1 << 1);
            adj[v1 << 1 ^ 1].pb(v2 << 1);
            adj[v2 << 1].pb(v1 << 1 ^ 1);
        }
    }
    f(2, 2 * m + 1)
    {
        if (!vis[i] && !vis[i ^ 1])
            dfs(i);
        i++;
    }
    bool ok = true;
    f(2, 2 * m + 1)
    {
        ll x = 0;
        if (vis[i])
            x++;
        if (vis[i ^ 1])
            x++;
        if (x != 1)
        {
            ok = false;
            break;
        }
        i++;
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}