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

const ll N = 100005;

ll n, p, l[N], r[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    long double ans = 0;
    f(1, n + 1)
    {
        cin >> l[i] >> r[i];
        ll in = r[i] / p - l[i] / p;
        if (l[i] % p == 0)
            in++;
        ans += 4000.0 * (in * 1.0 / (r[i] - l[i] + 1) * 1.0);
    }
    f(1, n + 1)
    {
        ll in, in1, ne;
        in = r[i] / p - l[i] / p;
        if (l[i] % p == 0)
            in++;
        if (i < n)
            ne = i + 1;
        else
            ne = 1;
        in1 = r[ne] / p - l[ne] / p;
        if (l[ne] % p == 0)
            in1++;
        ans -= 2000.0 * (in * 1.0 / (r[i] - l[i] + 1) * 1.0) * (in1 * 1.0 / (r[ne] - l[ne] + 1) * 1.0);
    }
    cout << fixed << setprecision(16) << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}