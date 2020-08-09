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

ll calc(ll x, ll y, ll z)
{
    ll ans = (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
    return ans;
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
        ll x, y, z;
        cin >> x >> y >> z;
        ll a[x], b[y], c[z];
        f(0, x) cin >> a[i];
        f(0, y) cin >> b[i];
        f(0, z) cin >> c[i];
        sort(a, a + x);
        sort(b, b + y);
        sort(c, c + z);
        ll ans = 3e18;
        f(0, x)
        {
            // Y
            ll j = lower_bound(b, b + y, a[i]) - b;
            if (j != y)
            {
                ll mid = a[i] + b[j] >> 1;
                ll k = lower_bound(c, c + z, mid) - c;
                if (k != z)
                    ans = min(ans, calc(a[i], b[j], c[k]));
                if (k != 0)
                {
                    k--;
                    ans = min(ans, calc(a[i], b[j], c[k]));
                }
            }
            if (j != 0)
            {
                j--;
                ll mid = a[i] + b[j] >> 1;
                ll k = lower_bound(c, c + z, mid) - c;
                if (k != z)
                    ans = min(ans, calc(a[i], b[j], c[k]));
                if (k != 0)
                {
                    k--;
                    ans = min(ans, calc(a[i], b[j], c[k]));
                }
            }
            // Z
            ll k = lower_bound(c, c + z, a[i]) - c;
            if (k != z)
            {
                ll mid = a[i] + c[k] >> 1;
                ll j = lower_bound(b, b + y, mid) - b;
                if (j != y)
                    ans = min(ans, calc(a[i], b[j], c[k]));
                if (j != 0)
                {
                    j--;
                    ans = min(ans, calc(a[i], b[j], c[k]));
                }
            }
            if (k != 0)
            {
                k--;
                ll mid = a[i] + c[k] >> 1;
                ll j = lower_bound(b, b + y, mid) - b;
                if (j != y)
                    ans = min(ans, calc(a[i], b[j], c[k]));
                if (j != 0)
                {
                    j--;
                    ans = min(ans, calc(a[i], b[j], c[k]));
                }
            }
        }
        cout << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}