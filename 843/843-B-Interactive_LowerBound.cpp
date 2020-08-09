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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    ll n, start, x, p, q, ans = -1, query = 1;
    cin >> n >> start >> x;
    set<pair<ll, ll>> s;
    cout << "? " << start << endl;
    cin >> p >> q;
    s.insert({p, q});
    map<ll, ll> m;
    if (p >= x)
    {
        cout << "! " << p << endl;
        return 0;
    }
    m[start]++;
    while (query < min(300LL, n))
    {
        ll k = mt() % n + 1;
        if (m.find(k) != m.end())
            continue;
        m[k]++;
        cout << "? " << k << endl;
        cin >> p >> q;
        s.insert({p, q});
        query++;
    }
    if (query == n)
    {
        auto it = s.lower_bound({x, -1});
        if (it == s.end())
        {
            cout << "! " << -1 << endl;
            return 0;
        }
        cout << "! " << it->first << endl;
        return 0;
    }
    while (query < 1999)
    {
        auto it = s.upper_bound({x, -1});
        it--;
        if (it->second == -1)
        {
            if (it->first >= x)
                cout << "! " << it->first << endl;
            else
                cout << "! " << -1 << endl;
            return 0;
        }
        cout << "? " << it->second << endl;
        cin >> p >> q;
        if (p >= x)
        {
            cout << "! " << p << endl;
            return 0;
        }
        if (q == -1)
        {
            cout << "! " << -1 << endl;
            return 0;
        }
        s.insert({p, q});
        query++;
    }
    cout << "! " << -1 << endl;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
