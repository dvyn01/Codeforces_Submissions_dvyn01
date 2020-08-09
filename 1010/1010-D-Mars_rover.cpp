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

ll val[1000005], n;
string s[1000005];
vll adj[1000005];
bool change[1000005], finalllllll[1000005];

ll dfs(ll x)
{
    if (s[x] == "IN")
        return val[x];
    if (s[x] == "NOT")
    {
        ll k = dfs(adj[x][0]);
        change[adj[x][0]] = true;
        val[x] = !k;
        return val[x];
    }
    ll k1 = dfs(adj[x][0]), k2 = dfs(adj[x][1]);
    if (s[x] == "AND")
    {
        val[x] = k1 & k2;
        if (val[x] == 0)
        {
            if (k1 == 0 && k2 != 0)
                change[adj[x][0]] = true;
            else if (k1 != 0 && k2 == 0)
                change[adj[x][1]] = true;
        }
        else
        {
            change[adj[x][0]] = true;
            change[adj[x][1]] = true;
        }
    }
    else if (s[x] == "XOR")
    {
        val[x] = k1 ^ k2;
        change[adj[x][0]] = true;
        change[adj[x][1]] = true;
    }
    else if (s[x] == "OR")
    {
        val[x] = k1 | k2;
        if (val[x] == 0)
        {
            change[adj[x][0]] = true;
            change[adj[x][1]] = true;
        }
        else
        {
            if (k1 == 0 && k2 != 0)
                change[adj[x][1]] = true;
            else if (k1 != 0 && k2 == 0)
                change[adj[x][0]] = true;
        }
    }
    return val[x];
}

void dfs1(ll x, bool b)
{
    b &= change[x];
    finalllllll[x] = b;
    f(0, adj[x].size())
        dfs1(adj[x][i], b);
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
    f(1, n + 1)
    {
        cin >> s[i];
        if (s[i] == "IN")
            cin >> val[i];
        else
        {
            if (s[i] == "NOT")
            {
                ll x;
                cin >> x;
                adj[i].pb(x);
                continue;
            }
            ll x, y;
            cin >> x >> y;
            adj[i].pb(x);
            adj[i].pb(y);
        }
    }
    string ans;
    dfs(1);
    f(0, adj[1].size()) dfs1(adj[1][i], 1);
    f(1, n + 1)
    {
        if (s[i] == "IN")
        {
            if (finalllllll[i])
                ans.pb('0' + !val[1]);
            else
                ans.pb('0' + val[1]);
        }
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}