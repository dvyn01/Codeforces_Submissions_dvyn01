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

ll n, a[100050], ans;

void rec(vll v, ll cb, ll cn)
{
    if (cb == -1)
    {
        f(0, v.size())
            ans = min(ans, v[i] ^ cn);
        return;
    }
    if (v.size() == 1)
    {
        ll k = v[0] ^ cn;
        fr(cb, 0) k &= ~(1LL << j);
        ans = min(ans, k);
        return;
    }
    ll c = 0;
    f(0, v.size()) if ((1LL << cb) & v[i]) c++;
    if (c == v.size())
    {
        cn |= (1LL << cb);
        rec(v, cb - 1, cn);
    }
    else if (c == 0)
    {
        rec(v, cb - 1, cn);
    }
    else
    {
        vll v1, v2;
        f(0, v.size())
        {
            if ((1LL << cb) & v[i])
                v1.pb(v[i]);
            else
                v2.pb(v[i]);
        }
        rec(v2, cb - 1, cn | (1LL << cb));
        rec(v1, cb - 1, cn);
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

    ll x;
    cin >> n;
    vll v;
    f(1, n + 1) cin >> x, v.pb(x);
    ans = 1e18;
    rec(v, 30, 0);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}