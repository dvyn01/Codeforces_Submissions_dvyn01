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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll l[n + 1], r[n + 1], u[n + 1], d[n + 1];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(l));
        memset(u, 0, sizeof(l));
        memset(d, 0, sizeof(l));
        f(1, n + 1)
        {
            if (s[i - 1] == 'L')
                l[i]++;
            else if (s[i - 1] == 'R')
                r[i]++;
            else if (s[i - 1] == 'U')
                u[i]++;
            else if (s[i - 1] == 'D')
                d[i]++;
        }
        f(1, n + 1) l[i] += l[i - 1], r[i] += r[i - 1], u[i] += u[i - 1], d[i] += d[i - 1];
        map<pair<ll, ll>, ll> m;
        bool ok = false;
        vector<pair<ll, pair<ll, ll>>> ans;
        f(0, n + 1)
        {
            ll k1 = l[i] - r[i], k2 = d[i] - u[i];
            if (m.find({k1, k2}) != m.end())
                ans.pb({i - m[{k1, k2}], {m[{k1, k2}], i}});
            m[{k1, k2}] = i;
        }
        sort(ans.begin(), ans.end());

        if (ans.size() == 0)
            cout << "-1\n";
        else
            cout << ans[0].second.first + 1 << " " << ans[0].second.second << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}