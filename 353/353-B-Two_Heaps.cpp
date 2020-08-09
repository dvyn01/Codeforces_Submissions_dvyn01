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

ll a[101];

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
    ll o = 0, t = 0;
    vll ans;
    pll p;
    ans.resize(2 * n);
    p.resize(2 * n);
    f(0, 2 * n) cin >> p[i].first, p[i].second = i;
    vll st;
    sort(p.begin(), p.end());
    f(0, 2 * n)
    {
        ll x = p[i].first, in = p[i].second;
        if (a[x] != 0)
        {
            if (a[x] == 3)
                continue;
            if (a[x] == 1)
                ans[in] = 2, t++;
            else
                ans[in] = 1, o++;
            a[x] = 3;
        }
        else
        {
            if (o <= t)
                ans[in] = 1, o++, a[x] = 1;
            else
                ans[in] = 2, t++, a[x] = 2;
        }
    }
    cout << o * t << '\n';
    f(0, 2 * n)
    {
        if (ans[i] == 0)
        {
            if (o <= t)
                ans[i] = 1, o++;
            else
                ans[i] = 2, t++;
        }
    }
    f(0, ans.size()) cout << ans[i] << ' ';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}