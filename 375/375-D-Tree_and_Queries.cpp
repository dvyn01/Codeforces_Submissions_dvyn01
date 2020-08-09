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

ll n, blockSize, q, a[100050], in[100050], out[100050], c, ans[100050], freq[100050], seg[200050], b[200050];
vll adj[100050];

vector<pair<pair<ll, ll>, pair<ll, ll>>> query;

void dfs(ll x, ll pr)
{
    in[x] = ++c;
    f(0, adj[x].size()) if (adj[x][i] != pr) dfs(adj[x][i], x);
    out[x] = ++c;
}

bool compare(pair<pair<ll, ll>, pair<ll, ll>> &a, pair<pair<ll, ll>, pair<ll, ll>> &b)
{
    if (a.first.first / blockSize == b.first.first / blockSize)
        return a.first.second < b.first.second;
    return a.first.first / blockSize < b.first.first / blockSize;
}

void add(ll k)
{
    freq[k]++;
    seg[freq[k]]++;
}

void remove(ll k)
{
    seg[freq[k]]--;
    freq[k]--;
}

void MoS()
{
    ll currentLeft = 1, currentRight = 0;
    f(0, q)
    {
        ll left = query[i].first.first, right = query[i].first.second, k = query[i].second.first, in = query[i].second.second;
        while (currentLeft < left)
            remove(b[currentLeft++]);
        while (currentLeft > left)
            add(b[--currentLeft]);
        while (currentRight < right)
            add(b[++currentRight]);
        while (currentRight > right)
            remove(b[currentRight--]);
        ans[in] = seg[2 * k];
    }
    f(1, q + 1) cout << ans[i] << "\n";
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
    cin >> n >> q;
    f(1, n + 1) cin >> a[i];
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    dfs(1, -1);
    f(0, q) cin >> x >> y, query.pb({{in[x], out[x]}, {y, i + 1}});
    blockSize = sqrt(n);
    sort(query.begin(), query.end(), compare);
    f(1, n + 1) b[in[i]] = a[i], b[out[i]] = a[i];
    MoS();

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}