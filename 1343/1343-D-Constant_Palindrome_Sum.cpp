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

const ll N = 200005;
ll fr[N << 1], a[N];

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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        f(0, 2 * k + 5) fr[i] = 0;
        f(1, n + 1) cin >> a[i];
        f(1, n / 2 + 1)
        {
            ll k1 = a[i], k2 = a[n - i + 1];
            ll mn = min(k1, k2), mx = max(k1, k2), s = k1 + k2;
            fr[s - mx + 1]++;
            fr[s]--;
            fr[s + k - mn + 1]--;
            fr[s + 1]++;
            if (s - mx + 1 > 2)
                fr[2] += 2, fr[s - mx + 1] -= 2;
            if (s + k - mn < 2 * k)
                fr[s + k - mn + 1] += 2, fr[2 * k + 1] -= 2;
        }
        ll ans = 1e18;
        f(1, 2 * k + 2) fr[i] += fr[i - 1];
        f(2, 2 * k + 1) ans = min(ans, fr[i]);
        cout << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}