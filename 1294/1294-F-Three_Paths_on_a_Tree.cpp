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

ll mx, nd, k1, k2, k3, n, d1;
vll adj[200050];
bool b[200050];

void dfs1(ll x, ll pr, ll d)
{
    if (d > mx)
        mx = d, nd = x;
    f(0, adj[x].size()) if (adj[x][i] != pr) dfs1(adj[x][i], x, d + 1);
}

bool dfs2(ll x, ll pr)
{
    if (x == k2)
    {
        b[x] = true;
        return true;
    }
    bool k = false;
    f(0, adj[x].size()) if (adj[x][i] != pr) k |= dfs2(adj[x][i], x);
    if (k)
        d1++;
    return b[x] = k;
}

void dfs3(ll x, ll pr, ll d)
{
    if (d > mx)
        mx = d, nd = x;
    f(0, adj[x].size()) if (adj[x][i] != pr && !b[adj[x][i]]) dfs3(adj[x][i], x, d + 1);
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
    mx = -1;
    dfs1(1, -1, 0);
    mx = -1;
    k1 = nd;
    dfs1(nd, -1, 0);
    k2 = nd;
    dfs2(k1, -1);
    ll km = -1;
    f(1, n + 1)
    {
        if (i != k1 && i != k2 && b[i])
        {
            mx = -1;
            dfs3(i, -1, 0);
            if (mx > km)
            {
                km = mx;
                k3 = nd;
            }
        }
    }
    cout << d1 + km << "\n";
    cout << k1 << " " << k2 << " " << k3 << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}