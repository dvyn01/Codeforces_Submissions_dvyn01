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
ostream &operator<<(ostream &os, unordered_map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

vll adj[200005];
ll a[200005], ans[200005];

unordered_map<ll, ll> dfs(ll x, ll pr)
{
    unordered_map<ll, ll> r;
    r[a[x]]++;
    ans[a[x]]++;
    f(0, adj[x].size()) if (adj[x][i] != pr)
    {
        unordered_map<ll, ll> r1 = dfs(adj[x][i], x);
        for (auto it : r)
            for (auto it1 : r1)
                ans[__gcd(it.first, it1.first)] += it.second * it1.second;
        for (auto it : r1)
            r[__gcd(it.first, a[x])] += it.second;
    }
    return r;
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
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    dfs(1, -1);
    f(1, 200005) if (ans[i] != 0) cout << i << " " << ans[i] << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}