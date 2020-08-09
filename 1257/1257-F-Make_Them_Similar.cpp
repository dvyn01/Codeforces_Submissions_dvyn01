#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
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

map<vll, ll> m1, m2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n];
    f(0, n) cin >> a[i];
    f(0, 1LL << 15)
    {
        vll v, v1;
        fi(0, n) v.pb(__builtin_popcount((a[j] & ((1LL << 15) - 1)) ^ i));
        fi(0, v.size() - 1) v1.pb(v[j + 1] - v[j]);
        if (m1.find(v1) == m1.end())
            m1[v1] = i;
    }
    f(0, n) a[i] >>= 15;
    f(0, 1LL << 15)
    {
        vll v, v1;
        fi(0, n) v.pb(__builtin_popcount(a[j] ^ i));
        fi(0, v.size() - 1) v1.pb(v[j + 1] - v[j]);
        if (m2.find(v1) == m2.end())
            m2[v1] = i << 15;
    }
    // cout << m1 << "\n"
    //      << m2 << "\n";
    for (auto it : m1)
    {
        vll v, v1 = it.first;
        fi(0, v1.size()) v.pb(-1 * v1[j]);
        if (m2.find(v) != m2.end())
        {
            cout << (it.second | m2[v]);
            return 0;
        }
    }
    cout << -1;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}