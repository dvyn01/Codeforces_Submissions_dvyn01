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

ll dp[500050][2], n, k;
pll adj[500050];

ll dfs(ll x, ll pr, ll s)
{
    if (dp[x][s] != -1)
        return dp[x][s];
    dp[x][s] = 0;
    vll v;
    f(0, adj[x].size())
    {
        if (adj[x][i].first != pr)
        {
            ll k1 = dfs(adj[x][i].first, x, 0);
            ll k2 = dfs(adj[x][i].first, x, 1);
            dp[x][s] += k1;
            if (adj[x][i].second + k2 > k1)
                v.pb(adj[x][i].second + k2 - k1);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    f(0, v.size())
    {
        if (i >= k - s)
            break;
        dp[x][s] += v[i];
    }
    return dp[x][s];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, w;
        cin >> n >> k;
        f(1, n + 5) adj[i].clear(), dp[i][0] = -1, dp[i][1] = -1;
        f(0, n - 1) cin >> x >> y >> w, adj[x].pb({y, w}), adj[y].pb({x, w});
        ll ans = dfs(1, -1, 0);
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}