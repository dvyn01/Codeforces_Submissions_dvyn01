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

vll adj[200050];
ll n, t[2000050], a[500050], c, in[200050], out[200050], initial[200050], lazy[2000050];

void dfs(ll x)
{
    a[c] = initial[x];
    in[x] = c++;
    f(0, adj[x].size())
        dfs(adj[x][i]);
    a[c] = initial[x];
    out[x] = c++;
}

void create(ll node, ll start, ll end)
{
    if (start == end)
    {
        t[node] = a[start];
        return;
    }
    ll mid = start + end >> 1;
    create(node << 1, start, mid);
    create(node << 1 ^ 1, mid + 1, end);
    t[node] = t[node << 1] + t[node << 1 ^ 1];
}

void update(ll node, ll start, ll end, ll l, ll r)
{
    if (lazy[node] & 1)
    {
        t[node] = (end - start + 1) - t[node];
        if (start != end)
        {
            lazy[node << 1]++;
            lazy[node << 1 ^ 1]++;
        }
        lazy[node] = 0;
    }
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        t[node] = (end - start + 1) - t[node];
        if (start != end)
        {
            lazy[node << 1]++;
            lazy[node << 1 ^ 1]++;
        }
        lazy[node] = 0;
        return;
    }
    ll mid = start + end >> 1;
    update(node << 1, start, mid, l, r);
    update(node << 1 ^ 1, mid + 1, end, l, r);
    t[node] = t[node << 1] + t[node << 1 ^ 1];
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l)
        return 0;
    if (lazy[node] & 1)
    {
        t[node] = (end - start + 1) - t[node];
        if (start != end)
        {
            lazy[node << 1]++;
            lazy[node << 1 ^ 1]++;
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r)
        return t[node];
    ll mid = start + end >> 1;
    return query(node << 1, start, mid, l, r) + query(node << 1 ^ 1, mid + 1, end, l, r);
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
    f(2, n + 1) cin >> x, adj[x].pb(i);
    f(1, n + 1) cin >> initial[i];
    c = 1;
    dfs(1);
    create(1, 1, 2 * n);
    ll q;
    cin >> q;
    while (q--)
    {
        string s;
        ll v;
        cin >> s >> v;
        if (s == "get")
            cout << query(1, 1, 2 * n, in[v], out[v]) / 2 << "\n";
        else
            update(1, 1, 2 * n, in[v], out[v]);
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}