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
        ll n;
        cin >> n;
        ll b[n];
        f(0, n) cin >> b[i];
        ll ans[2 * n];
        memset(ans, 0, sizeof(ans));
        set<ll> s;
        f(1, 2 * n + 1) s.insert(i);
        bool ok = true;
        f(0, n)
        {
            auto it = s.lower_bound(b[i]);
            if (it == s.end() || *it != b[i])
            {
                ok = false;
                break;
            }
            s.erase(it);
            ans[2 * i] = b[i];
        }
        if (!ok)
        {
            cout << "-1\n";
            continue;
        }
        f(0, n)
        {
            ll k1 = ans[2 * i];
            auto it = s.lower_bound(k1);
            if (it == s.end())
            {
                ok = false;
                break;
            }
            ll k2 = *it;
            s.erase(it);
            ans[2 * i] = min(k1, k2);
            ans[2 * i + 1] = max(k1, k2);
        }
        if (!ok)
        {
            cout << "-1\n";
            continue;
        }
        f(0, 2 * n) cout << ans[i] << " ";
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}