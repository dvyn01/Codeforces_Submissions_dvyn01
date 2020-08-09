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

const ll N = 200005;
ll a[N], s[N], c[N];
vll v[N];

void init(ll n)
{
    f(1, n + 1) a[i] = i, s[i] = 1;
}

ll root(ll i)
{
    while (i != a[i])
        i = a[a[i]];
    return i;
}

void merge(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return;
    if (s[xr] >= s[yr])
        s[xr] += s[yr], a[yr] = xr;
    else
        s[yr] += s[xr], a[xr] = yr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    init(n);
    f(1, n + 1) cin >> c[i], v[c[i]].pb(i);
    f(1, N) fi(1, v[i].size()) merge(v[i][j - 1], v[i][j]);
    ll last = 0, mx = 0, ans = 0, pr = 0;
    f(1, n + 1)
    {
        last = max(last, v[c[i]].back());
        if (root(i) == i)
            mx = max(mx, s[i]);
        if (last == i)
            ans += last - pr - mx, pr = last, mx = 0;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}