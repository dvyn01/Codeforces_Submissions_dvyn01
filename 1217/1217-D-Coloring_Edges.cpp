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

ll n, m, ans[5005], t[5005];
pll adj[5005];
bool two;

void dfs(ll x)
{
    if (t[x] == -1)
        t[x] = 1;
    f(0, adj[x].size())
    {
        if (t[adj[x][i].first] == -1)
            ans[adj[x][i].second] = 1, dfs(adj[x][i].first);
        else if (t[adj[x][i].first] == 2)
            ans[adj[x][i].second] = 1;
        else
            ans[adj[x][i].second] = 2, two = true;
    }
    t[x] = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(ans, -1, sizeof(ans));
    memset(t, -1, sizeof(t));
    ll x, y;
    cin >> n >> m;
    f(0, m) cin >> x >> y, adj[x].pb({y, i + 1});
    f(1, n + 1) if (t[i] == -1)
        dfs(i);
    if (two)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";
    f(1, m + 1) cout << ans[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}