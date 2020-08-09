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

ll n, h, rem;

ll pos(ll mid)
{
    if (mid == 0)
        return -1;
    if (mid > 2 * rem / (mid + 1))
        return -1;
    ll k = rem - (mid * (mid + 1)) / 2;
    if (k == 0)
        return mid;
    if (k <= mid)
        return mid + 1;
    ll p = k / mid;
    ll ans = mid + p;
    k -= p * mid;
    if (k)
        ans++;
    return ans;
}

ll find(ll mid)
{
    if (mid > 2 * n / (mid + 1))
        return -1;
    ll l1 = mid, l = mid + 1, h = sqrt(2 * n + mid * (mid - 1)) - 1;
    rem = n;
    ll ans = pos(mid);
    while (l <= h)
    {
        ll mid1 = l + h >> 1;
        rem = n - mid1 * (mid1 + 1) / 2 + mid * (mid - 1) / 2;
        ll k1 = pos(mid1), k2 = pos(mid1 - 1);
        if (k1 == -1 && k2 == -1)
            h = mid1 - 1;
        else
        {
            if (k1 != -1)
                ans = min(ans, mid1 - l1 + 1 + k1);
            if (k2 != -1)
                ans = min(ans, mid1 - l1 + 1 + k2);
            l = mid1 + 1;
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;
    ll l = 1, r = min(n, h), ans = -1;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        ll p = find(mid);
        if (p == -1)
            r = mid - 1;
        else
            ans = p, l = mid + 1;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}