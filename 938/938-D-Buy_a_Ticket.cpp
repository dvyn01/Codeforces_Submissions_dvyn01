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
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll n, m, a[200050], d[200050];
pll adj[200050];
bool vis[200050];

void dij()
{
    set<pair<ll, ll>> s;
    f(1, n + 1) d[i] = a[i], s.insert({a[i], i});
    while (!s.empty())
    {
        ll u = s.begin() -> second;
        s.erase(s.begin());
        if (vis[u])
            continue;
        vis[u] = true;
        f(0, adj[u].size())
        {
            ll v = adj[u][i].first, w = adj[u][i].second;
            if (d[v] > d[u] + 2 * w)
                d[v] = d[u] + 2 * w, s.insert({d[v], v});
        }
    }
    f(1, n + 1) cout << d[i] << " ";
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
    cin >> n >> m;
    f(0, m) cin >> x >> y >> w, adj[x].pb({y, w}), adj[y].pb({x, w});
    f(1, n + 1) cin >> a[i];
    dij();

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}