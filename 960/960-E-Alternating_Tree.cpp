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

inline ll mul(ll x, ll y, ll m)
{
    if (x < 0)
        x += mod;
    if (y < 0)
        y += mod;
    x %= mod;
    y %= mod;
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    if (x < 0)
        x += mod;
    if (y < 0)
        y += mod;
    x %= mod;
    y %= mod;
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    if (x < 0)
        x += mod;
    if (y < 0)
        y += mod;
    x %= mod;
    y %= mod;
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

vll adj[200005];
ll a[200005], ans, even[200005], odd[200005], dp[200005][2]; // odd, even

void dfs(ll x, ll pr)
{
    ll tot = 0, tot1 = 0;
    pll p, p1;
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr)
        {
            dfs(adj[x][i], x);
            ans = add(ans, mul(2, add(dp[adj[x][i]][1], mul(even[adj[x][i]], a[x], mod), mod), mod), mod);
            p.pb({dp[adj[x][i]][0], odd[adj[x][i]]});
            if (even[adj[x][i]])
                p1.pb({dp[adj[x][i]][1], even[adj[x][i]]});
            even[x] += odd[adj[x][i]];
            odd[x] += even[adj[x][i]];
            dp[x][0] = add(dp[x][0], add(mul(even[adj[x][i]], a[x], mod), dp[adj[x][i]][1], mod), mod);
            dp[x][1] = add(dp[x][1], sub(dp[adj[x][i]][0], mul(odd[adj[x][i]], a[x], mod), mod), mod);
            tot += odd[adj[x][i]];
            tot1 += even[adj[x][i]];
        }
    }
    f(0, p.size())
    {
        ans = add(ans, mul(mul(2, p[i].first, mod), tot - p[i].second, mod), mod);
        ans = sub(ans, mul(mul(p[i].second, tot - p[i].second, mod), a[x], mod), mod);
    }
    f(0, p1.size())
    {
        ans = add(ans, mul(mul(2, p1[i].first, mod), tot1 - p1[i].second, mod), mod);
        ans = add(ans, mul(mul(p1[i].second, tot1 - p1[i].second, mod), a[x], mod), mod);
    }
    ans = add(ans, a[x], mod);
    dp[x][0] = add(dp[x][0], a[x], mod);
    odd[x]++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n;
    f(1, n + 1) cin >> a[i];
    f(1, n) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    dfs(1, -1);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}