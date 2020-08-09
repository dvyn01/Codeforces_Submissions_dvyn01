#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll unsigned long long
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

ll n, sub[100005], w[100005];
pll adj[100005];

ll dfs(ll x, ll pr)
{
    ll k = 1;
    f(0, adj[x].size())
    {
        if (adj[x][i].first != pr)
        {
            ll k1 = dfs(adj[x][i].first, x);
            sub[adj[x][i].second] = k1;
            k += k1;
        }
    }
    return k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll x, y;
    f(0, n - 1) cin >> x >> y >> w[i + 1], adj[x].pb({y, i + 1}), adj[y].pb({x, i + 1});
    dfs(1, -1);
    long double tot = 0;
    f(1, n)
    {
        ll k1 = sub[i], k2 = n - sub[i];
        ll x = k1 * k2;
        x *= (k1 + k2 - 2);
        tot += x * w[i]  * 6.0 / (n * (n - 1) * (n - 2));
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll i, nw;
        cin >> i >> nw;
        ll k1 = sub[i], k2 = n - sub[i];
        ll x = k1 * k2;
        x *= (k1 + k2 - 2);
        tot -= x * w[i] * 6.0 / (n * (n - 1) * (n - 2));
        w[i] = nw;
        tot += x * w[i] * 6.0 / (n * (n - 1) * (n - 2));
        long double ans = tot * 1.0;
        // ans /= (n * (n - 1) * (n - 2)) / 6.0;
        cout << fixed << setprecision(16) << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}