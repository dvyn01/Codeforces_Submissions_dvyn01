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

ll ncr[21][21];

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
    ncr[0][0] = 1;
    f(1, 21)
    {
        fi(0, i + 1)
        {
            if (j == 0)
                ncr[i][j] = 1;
            else if (j == 1)
                ncr[i][j] = i;
            else
                ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
    while (t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> m;
        ll c = 2, tot = 0;
        while (n)
            m[n % c]++, n /= c, c++, tot++;
        ll ans = 1, done = 0;
        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            ll last = tot - it->first + 1 - done;
            if (it->first == 0)
                last--;
            ans *= ncr[last][it->second];
            done += it->second;
        }
        if (m.find(0) != m.end())
        {
            ll ans1 = 1;
            m[0]--;
            if (m[0] == 0)
                m.erase(0);
            done = 0;
            tot--;
            for (auto it = m.rbegin(); it != m.rend(); it++)
            {
                ll last = tot - it->first + 1 - done;
                if (it->first == 0)
                    last--;
                ans1 *= ncr[last][it->second];
                done += it->second;
            }
            ans -= ans1;
        }
        cout << ans - 1 << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}