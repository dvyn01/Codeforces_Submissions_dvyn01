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

ll n, m, k, a[200005], d1[200005], d2[200005];
vll adj[200005];
bool ok;

void bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    if (s == 1)
        d1[s] = 0;
    else
        d2[s] = 0;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        f(0, adj[x].size())
        {
            if (s == 1)
            {
                if (d1[adj[x][i]] == -1)
                    d1[adj[x][i]] = d1[x] + 1, q.push(adj[x][i]);
            }
            else
            {
                if (d2[adj[x][i]] == -1)
                    d2[adj[x][i]] = d2[x] + 1, q.push(adj[x][i]);
            }
        }
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

    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    ll x, y;
    cin >> n >> m >> k;
    f(0, k) cin >> x, a[x]++;
    f(0, m)
    {
        cin >> x >> y;
        if (a[x] & a[y])
            ok = true;
        adj[x].pb(y), adj[y].pb(x);
    }
    bfs(1);
    bfs(n);
    if (ok)
    {
        cout << d1[n];
        return 0;
    }
    vector<pair<ll, pair<ll, ll>>> p;
    f(1, n + 1) if (a[i] & 1)
        p.pb({d1[i] - d2[i], {d1[i], d2[i]}});
    sort(p.begin(), p.end());
    ll ans1 = -1, mx = -1;
    fr(p.size() - 1, 0)
    {
        ll x = p[j].second.first, y = p[j].second.second;
        if (mx != -1)
            ans1 = max(ans1, x + mx);
        mx = max(mx, y);
    }
    ans1 = min(ans1 + 1, d1[n]);
    cout << ans1;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}