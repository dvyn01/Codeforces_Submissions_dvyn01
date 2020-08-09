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

ll ans[105][105], n, m;

// https://cp-algorithms.com/graph/dinic.html

struct FlowEdge
{
    ll v, u;
    long long cap, flow = 0;
    FlowEdge(ll v, ll u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic
{
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<ll>> adj;
    ll n, m = 0;
    ll s, t;
    vector<ll> level, ptr;
    queue<ll> q;

    Dinic(ll n, ll s, ll t) : n(n), s(s), t(t)
    {
        adj.clear();
        adj.resize(n);
        level.clear();
        level.resize(n);
        ptr.clear();
        ptr.resize(n);
    }

    void add_edge(ll v, ll u, long long cap)
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs()
    {
        while (!q.empty())
        {
            ll v = q.front();
            q.pop();
            for (ll id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(ll v, long long pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (ll &cid = ptr[v]; cid < (ll)adj[v].size(); cid++)
        {
            ll id = adj[v][cid];
            ll u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            ll vv = v, uu = u;
            bool OneSeTwo = false, TwoSeOne = false;
            if (vv > 0 && vv <= (n - 2) / 2 && uu > (n - 2) / 2 && uu < n - 1)
                OneSeTwo = true;
            if (uu > 0 && uu <= (n - 2) / 2 && vv > (n - 2) / 2 && vv < n - 1)
                TwoSeOne = true;
            if (vv > (n - 2) / 2)
                vv -= (n - 2) / 2;
            if (uu > (n - 2) / 2)
                uu -= (n - 2) / 2;
            if (OneSeTwo)
                ans[vv][uu] += tr;
            if (TwoSeOne)
                ans[uu][vv] -= tr;
            return tr;
        }
        return 0;
    }

    long long flow()
    {
        long long f = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k = 0, s1 = 0, s2 = 0;
    cin >> n >> m;
    ll a[n + 1], b[n + 1];
    f(1, n + 1) cin >> a[i], s1 += a[i];
    f(1, n + 1) cin >> b[i], s2 += b[i];
    if (s1 != s2)
    {
        cout << "NO";
        return 0;
    }
    Dinic d = Dinic(2 * n + 2, 0, 2 * n + 1);
    f(1, n + 1) d.add_edge(0, i, a[i]);
    f(1, n + 1) d.add_edge(n + i, 2 * n + 1, b[i]);
    f(1, n + 1) d.add_edge(i, n + i, 1000000);
    f(0, m)
    {
        ll x, y;
        cin >> x >> y;
        d.add_edge(x, y + n, 1000000);
        d.add_edge(y, x + n, 1000000);
    }
    k = d.flow();
    if (k != s1)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    f(1, n + 1)
    {
        fi(1, n + 1) cout << ans[i][j] << " ";
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}