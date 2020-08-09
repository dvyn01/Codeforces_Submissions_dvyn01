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

vll adj[200];
bool vis[200];
ll ans, n;

void bfs(ll x)
{
    queue<ll> q;
    q.push(x);
    vis[x] = true;
    ll par[n + 5], size[n + 5];
    memset(size, 0, sizeof(size));
    memset(par, -1, sizeof(par));
    size[x] = 1;
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        f(0, adj[v].size())
        {
            if (vis[adj[v][i]] && adj[v][i] != par[v])
            {
                // cout << v << " " << adj[v][i] << " " << x << " " << size[v] << " " << size[adj[v][i]] << "\n";
                if (ans == -1)
                    ans = size[v] + size[adj[v][i]] - 1;
                else if (size[v] + size[adj[v][i]] - 1 < ans)
                    ans = size[v] + size[adj[v][i]] - 1;
                return;
            }
            else if (!vis[adj[v][i]])
                par[adj[v][i]] = v, vis[adj[v][i]] = true, size[adj[v][i]] = size[v] + 1, q.push(adj[v][i]);
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

    ll x;
    cin >> n;
    ll m = n;
    n = 0;
    ll a[m];
    f(0, m)
    {
        cin >> x;
        if (x)
            a[n++] = x;
    }
    if (n >= 121)
    {
        cout << 3;
        return 0;
    }
    f(0, n)
        fi(i + 1, n) 
            if ((a[i] & a[j]) != 0) 
                adj[i + 1].pb(j + 1), adj[j + 1].pb(i + 1);
    ans = -1;
    f(1, n + 1)
        memset(vis, false, sizeof(vis)),
        bfs(i);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}