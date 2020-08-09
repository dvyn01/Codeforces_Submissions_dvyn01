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

inline ll mul(ll x, ll y, ll m)
{
    x %= mod;
    y %= mod;
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    x %= mod;
    y %= mod;
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

ll powmod(ll x, ll y)
{
    ll r = 1;
    while (y)
    {
        if (y & 1)
            r = mul(r, x, mod);
        y >>= 1;
        x = mul(x, x, mod);
    }
    return r;
}

ll n, m, k, a[500050], ans, r[500050], s[500050];
vll adj[500050];
set<ll> st;
bool vis[500050];
multimap<ll, pair<ll, ll>> same;
map<ll, map<ll, map<ll, ll>>> m2;

void init()
{
    for (auto it = st.begin(); it != st.end(); it++)
        r[*it] = *it, s[*it] = 1;
}

ll root(ll i)
{
    while (r[i] != i)
        i = r[r[r[r[i]]]];
    return i;
}

void merge(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return;
    if (s[xr] >= s[yr])
        s[xr] += s[yr], r[yr] = xr;
    else
        s[yr] += s[xr], r[xr] = yr;
    st.insert(x);
    st.insert(y);
}

void dfs(ll x)
{
    vis[x] = true;
    f(0, adj[x].size())
    {
        if (m2[a[x] ^ a[adj[x][i]]][min(x, adj[x][i])][max(x, adj[x][i])] == 0)
            same.insert({a[x] ^ a[adj[x][i]], {min(x, adj[x][i]), max(x, adj[x][i])}});
        m2[a[x] ^ a[adj[x][i]]][min(x, adj[x][i])][max(x, adj[x][i])] = 1;
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
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

    ll x, y, c = 0;
    cin >> n >> m >> k;
    f(1, n + 1) cin >> a[i];
    f(0, m) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    f(1, n + 1) st.insert(i);
    init();
    f(1, n + 1) if (!vis[i]) dfs(i);
    for (auto it = same.begin(); it != same.end(); it++)
    {
        ll sudo = 1;
        if (it->first >= (1LL << k))
            break;
        init();
        st.clear();
        ll val = it->first;
        auto it1 = it;
        for (; it1 != same.end() && it1->first == val; it1++)
            merge(it1->second.first, it1->second.second);
        for (auto it2 = st.begin(); it2 != st.end(); it2++)
            if (r[*it2] == *it2)
                sudo = mul(sudo, 2, mod);
        c++;
        sudo = mul(sudo, powmod(2, n - st.size()), mod);
        ans = add(ans, sudo, mod);
        if (it1 == same.end())
            break;
        it = --it1;
    }
    k = (1LL << k) - c;
    ans = add(ans, mul(k, powmod(2, n), mod), mod);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}