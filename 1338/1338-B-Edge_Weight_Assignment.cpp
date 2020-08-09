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

const ll N = 100005;
vll adj[N];
ll dp[N][2], mx;
bool odd;

void dfs(ll x, ll pr)
{
    bool done = false;
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr)
        {
            done = true;
            dfs(adj[x][i], x);
            dp[x][0] += dp[adj[x][i]][1];
            dp[x][1] += dp[adj[x][i]][0];
        }
    }
    if (!done)
        dp[x][0] = 1;
}

void dfs2(ll x, ll pr)
{
    if (odd)
        return;
    if (dp[x][0] != 0 && dp[x][1] != 0)
    {
        odd = true;
        return;
    }
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr)
        {
            dp[adj[x][i]][0] += dp[x][1] - dp[adj[x][i]][0];
            dp[adj[x][i]][1] += dp[x][0] - dp[adj[x][i]][1];
            dfs2(adj[x][i], x);
        }
    }
}

ll dfs3(ll x, ll pr)
{
    ll k = 0;
    bool done = false;
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr)
            done = true, k += dfs3(adj[x][i], x);
    }
    if (k > 0)
        mx -= k - 1;
    if (!done)
        return 1;
    return 0;
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
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    f(1, n + 1)
    {
        if (adj[i].size() > 1)
        {
            dfs(i, -1);
            break;
        }
    }
    f(1, n + 1)
    {
        if (adj[i].size() > 1)
        {
            dfs2(i, -1);
            break;
        }
    }
    mx = n - 1;
    f(1, n + 1)
    {
        if (adj[i].size() > 1)
        {
            dfs3(i, -1);
            break;
        }
    }
    if (odd)
        cout << 3 << ' ' << mx << '\n';
    else
        cout << 1 << ' ' << mx << '\n';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}