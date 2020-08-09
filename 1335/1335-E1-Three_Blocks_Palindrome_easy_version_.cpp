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

const ll N = 200001;
ll m[N][201];
vll v[201];

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
        ll n, ans = 0;
        cin >> n;
        f(1, n + 1) fi(0, 201) m[i][j] = 0;
        f(1, 201) v[i].clear();
        ll a[n + 1];
        f(1, n + 1) cin >> a[i], m[i][a[i]]++, v[a[i]].pb(i);
        fi(1, 201) f(1, n + 1) m[i][j] += m[i - 1][j];
        f(1, 201) ans = max(ans, m[n][i]);
        // cout << ans << '\n';
        f(1, 201)
        {
            fi(1, 100005)
            {
                if (v[i].size() < 2 * j)
                    break;
                // cout << i << ' ' << j << " -> ";
                ll k1 = v[i][j - 1], k2 = v[i][v[i].size() - j];
                // cout << k1 << ' ' << k2 << " = ";
                ll p = 0;
                fii(1, 201)
                {
                    if (k == i)
                        continue;
                    p = max(p, m[k2][k] - m[k1][k]);
                }
                // cout << p << " -> ";
                p += 2 * j;
                // cout << p << '\n';
                if (p > ans)
                    ans = p;
            }
        }
        cout << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}