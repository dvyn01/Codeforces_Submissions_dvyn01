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

int main()
{

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    ll n;
    cin >> n;
    ll l = 0, r = 1000000000, mx = 0, q = 60;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        q--;
        cout << "> " << mid << endl;
        ll k;
        cin >> k;
        if (k == 0)
            mx = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    vll v;
    v.pb(mx);
    ll d = 0;
    while (q--)
    {
        cout << "? " << (mt() % n) + 1 << endl;
        ll k;
        cin >> k;
        v.pb(k);
        f(0, v.size() - 1) d = __gcd(d, abs(v[i] - v[v.size() - 1]));
    }
    mx = mx - (n - 1) * d;
    cout << "! " << mx << " " << d << "\n";

    return 0;
}
