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
#define print(x) cout << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vll adj[1000050], *v[1000050];
ll n, cnt[1000050], level[1000050], ans[1000050], sub[1000050];

void getSize(ll x, ll pr)
{
    sub[x] = 1;
    f(0, adj[x].size()) if (adj[x][i] != pr) level[adj[x][i]] = level[x] + 1, getSize(adj[x][i], x), sub[x] += sub[adj[x][i]];
}

void dfs(ll x, ll pr, bool keep)
{
    ll heavy = -1, mx = -1;
    f(0, adj[x].size()) if (adj[x][i] != pr && sub[adj[x][i]] > mx) mx = sub[adj[x][i]], heavy = adj[x][i];
    f(0, adj[x].size()) if (adj[x][i] != pr && adj[x][i] != heavy) dfs(adj[x][i], x, 0);
    if (heavy != -1)
        dfs(heavy, x, 1), v[x] = v[heavy], ans[x] = ans[heavy];
    else
        v[x] = new vector<ll>();
    cnt[level[x]]++;
    v[x]->pb(x);
    if (cnt[level[x]] >= cnt[ans[x]])
        ans[x] = level[x];
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr && adj[x][i] != heavy)
        {
            for (auto it : *v[adj[x][i]])
            {
                v[x]->pb(it);
                cnt[level[it]]++;
                if (cnt[level[it]] > cnt[ans[x]])
                    ans[x] = level[it];
                else if (cnt[level[it]] == cnt[ans[x]])
                    ans[x] = min(ans[x], level[it]);
            }
        }
    }
    if (keep == 0)
        for (auto it : *v[x])
            cnt[level[it]]--;
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
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    getSize(1, -1);
    dfs(1, -1, 1);
    f(1, n + 1) cout << ans[i] - level[i] << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}