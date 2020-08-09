#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll int
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

unordered_map<ll, ll> adj[500050], s;
vector<ll> ans;
ll c;

void dfs(ll x)
{
    vll v;
    for (auto it : s)
        if (adj[x].count(it.first) == 0)
            v.pb(it.first), ans[c]++;
    for (auto it : v)
        s.erase(it);
    for (auto it : v)
        dfs(it);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, x, y;
    cin >> n >> m;
    f(0, m) cin >> x >> y, adj[x][y] = 1, adj[y][x] = 1;
    f(1, n + 1) s[i] = 1;
    f(1, n + 1)
    {
        if (s.count(i) != 0)
        {
            s.erase(i);
            ans.pb(1);
            dfs(i);
            c++;
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    f(0, ans.size()) cout << ans[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}