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

ll n, m, s, b, k, h, sx[1005], sf[1005], sa[1005], bx[1005], bd[1005];
vll adj[105], inb[105];
bool vis[105];

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
        adj.resize(n);
        level.resize(n);
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
} d(2002, 0, 2001);

void bfs(ll v, ll in)
{
    queue<pair<ll, ll>> q;
    q.push({v, 0});
    memset(vis, false, sizeof(vis));
    vis[v] = true;
    while (!q.empty())
    {
        ll x = q.front().first, dd = q.front().second;
        if (dd > sf[in])
            break;
        q.pop();
        f(0, inb[x].size())
        {
            ll bin = inb[x][i];
            if (sa[in] >= bd[bin])
                d.add_edge(in, 1000 + bin, 1);
        }
        f(0, adj[x].size()) if (!vis[adj[x][i]])
            vis[adj[x][i]] = true,
            q.push({adj[x][i], dd + 1});
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
    cin >> s >> b >> k >> h;
    f(1, s + 1) cin >> sx[i] >> sa[i] >> sf[i];
    f(1, b + 1) cin >> bx[i] >> bd[i], inb[bx[i]].pb(i);
    f(1, s + 1) d.add_edge(0, i, 1);
    f(1, s + 1) bfs(sx[i], i);
    f(1, b + 1) d.add_edge(1000 + i, 2001, 1);
    ll p = d.flow();
    ll ans = p * k;
    ans = min(ans, s * h);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}