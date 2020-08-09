#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll int
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

ll n, m, d[101][101];
string s[101];
vll v, ans;

void dij(ll x)
{
    d[x][x] = 0;
    set<pair<ll, ll>> ss;
    ss.insert({0, x});
    while (!ss.empty())
    {
        ll c = ss.begin()->second, cd = ss.begin()->first;
        ss.erase(ss.begin());
        f(0, s[c].size())
        {
            if (s[c][i] == '0')
                continue;
            if (d[x][i] > cd + 1)
                d[x][i] = cd + 1, ss.insert({cd + 1, i});
        }
    }
}

void calc(ll in, ll last)
{
    if (in == m - 1)
    {
        ans.pb(v[in]);
        return;
    }
    ll c = in + 1 - last;
    if (d[v[last]][v[in + 1]] != c)
        ans.pb(v[in]), calc(in + 1, in);
    else
        calc(in + 1, last);
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
    f(0, n) fi(0, n) d[i][j] = 1e9;
    f(0, n) cin >> s[i];
    cin >> m;
    v.resize(m);
    f(0, m) cin >> v[i], v[i]--;
    f(0, n) dij(i);
    ans.pb(v[0]);
    calc(1, 0);
    cout << ans.size() << "\n";
    f(0, ans.size()) cout << ans[i] + 1 << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}