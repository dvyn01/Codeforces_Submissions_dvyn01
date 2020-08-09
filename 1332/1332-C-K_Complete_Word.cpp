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

ll a[200005], sz[200001], b[200005][26];
string s;

void init(ll n)
{
    f(0, n) fi(0, 26) b[i][j] = 0;
    f(0, n) a[i] = i, sz[i] = 1, b[i][s[i] - 'a'] = 1;
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
    if (sz[xr] >= sz[yr])
    {
        f(0, 26) b[xr][i] += b[yr][i];
        sz[xr] += sz[yr];
        a[yr] = xr;
    }
    else
    {
        f(0, 26) b[yr][i] += b[xr][i];
        sz[yr] += sz[xr];
        a[xr] = yr;
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cin >> s;
        init(n);
        f(0, k)
        {
            ll j = i;
            while (j + k < n)
                merge(j, j + k), j += k;
        }
        ll l = n / 2 - 1, r = n / 2;
        if (n & 1)
            r++;
        while (l > 0)
            merge(l, r), l--, r++;
        ll ans = 0;
        f(0, n)
        {
            if (a[i] == i)
            {
                ll mx = 0, s = 0;
                fi(0, 26)
                {
                    s += b[i][j];
                    if (b[i][j] > mx)
                        mx = b[i][j];
                }
                ans += s - mx;
            }
        }
        cout << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}