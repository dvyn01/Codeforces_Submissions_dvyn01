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

pll p[17000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vll v1, v2;
    ll k1 = 0, k2 = 0;
    fr(13, 7) k1 += (1LL << j);
    fr(6, 0) k2 += (1LL << j);
    f(0, 100) v1.pb(k1 + i);
    f(0, 100) v2.pb((i << 7) + k2);
    cout << "? ";
    f(0, 100) cout << v1[i] << " ";
    cout << endl;
    cin >> k1;
    cout << "? ";
    f(0, 100) cout << v2[i] << " ";
    cout << endl;
    cin >> k2;
    ll ans = 0;
    fr(13, 0)
    {
        if (j >= 7)
        {
            if (!(k1 & (1LL << j)))
                ans += 1LL << j;
        }
        else
        {
            if (!(k2 & (1LL << j)))
                ans += 1LL << j;
        }
    }
    cout << "! " << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
