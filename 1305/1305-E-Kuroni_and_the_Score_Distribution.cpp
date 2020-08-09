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

    ll n, m, mx = 0;
    cin >> n >> m;
    f(3, n + 1) mx += (i - 1) / 2;
    if (m > mx)
    {
        cout << -1;
        return 0;
    }
    vll v;
    v.pb(1);
    v.pb(2);
    ll cs = 3;
    while (1)
    {
        if ((cs - 1) / 2 >= m)
        {
            ll k = 0;
            if ((cs - 1) & 1)
                k++;
            if (((cs - 1) / 2 - m - 1) * 2 + 1 > 0)
                k += ((cs - 1) / 2 - m - 1) * 2 + 1;
            v.pb(v.back() + v[k]);
            break;
        }
        else
        {
            m -= (cs - 1) / 2;
            v.pb(cs);
        }
        cs++;
    }
    ll x = v[v.size() - 1];
    if (v.size() < n)
        v.pb(v[v.size() - 1] + v[v.size() - 2] + 1);
    while (v.size() < n)
        v.pb(v[v.size() - 1] + x + 1);
    f(0, n) cout << v[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}