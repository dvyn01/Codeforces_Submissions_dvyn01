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

ll d[10], fact[20], ans;
map<pair<pair<ll, ll>, vll>, ll> dp; // zc, in, v

ll rec(ll zc, ll in, vll v)
{
    if (in >= 10)
    {
        if (zc + v.size() == 0)
            return 0;
        ll k = zc;
        f(0, v.size()) k += v[i];
        k = fact[k];
        f(0, v.size())
            k /= fact[v[i]];
        k /= fact[zc];
        if (zc == 0)
            return k;
        ll k1 = zc - 1;
        f(0, v.size()) k1 += v[i];
        k1 = fact[k1];
        f(0, v.size())
            k1 /= fact[v[i]];
        k1 /= fact[zc - 1];
        return k - k1;
    }
    // if (dp.find({{zc, in}, v}) != dp.end())
    //     return dp[{{zc, in}, v}];
    if (d[in] == 0)
        return rec(zc, in + 1, v);
    ll k = 0;
    f(1, d[in] + 1)
    {
        if (in == 0)
            k += rec(i, in + 1, v);
        else
        {
            vll v1 = v;
            if (i != 0)
                v1.pb(i), sort(v1.begin(), v1.end());
            k += rec(zc, in + 1, v1);
        }
    }
    return k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    f(1, 20) fact[i] = fact[i - 1] * i;
    ll n;
    cin >> n;
    ll k = n;
    while (k)
    {
        d[k % 10]++;
        k /= 10;
    }
    vll v;
    ll ans = rec(0, 0, v);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}