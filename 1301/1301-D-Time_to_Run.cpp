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

    ll n, m, k;
    cin >> n >> m >> k;
    ll x = 4 * n * m - 2 * n - 2 * m;
    if (k > x)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<ll, string>> ans;
    ll p = m - 1, ci = 1;
    while (k > 0 && ci < n)
    {
        if (m > 1)
        {
            if (k > m - 1)
                ans.pb({m - 1, "R"});
            else
                break;
            k -= m - 1;
            if (k > m - 1)
                ans.pb({m - 1, "L"});
            else
                break;
            k -= m - 1;
        }
        if (k > 0)
            k--, ans.pb({1, "D"});
        else
            break;
        ci++;
    }
    if (k > 0)
    {
        if (ci == n)
        {
            if (m > 1 && k > m - 1)
                k -= m - 1, ans.pb({m - 1, "R"});
            else if (k <= m - 1)
                ans.pb({k, "R"}), k = 0;
        }
        else
        {
            ll x = ans.size() % 3;
            if (x == 0)
                ans.pb({k, "R"});
            else if (x == 1)
                ans.pb({k, "L"});
            else
                ans.pb({k, "D"});
            k = 0;
        }
    }
    ci = m;
    while (k > 0 && ci > 1)
    {
        if (n > 1)
        {
            if (k > n - 1)
                ans.pb({n - 1, "U"});
            else
                break;
            k -= n - 1;
            if (k > n - 1)
                ans.pb({n - 1, "D"});
            else
                break;
            k -= n - 1;
        }
        if (k > 0)
            k--, ans.pb({1, "L"});
        else
            break;
        ci--;
    }
    if (k > 0)
    {
        if (ci == 1)
            ans.pb({k, "U"}), k = 0;
        else
        {
            ll x = (ans.size() - 1) % 3;
            if (x == 0)
                ans.pb({k, "U"});
            else if (x == 1)
                ans.pb({k, "D"});
            else
                ans.pb({k, "L"});
            k = 0;
        }
    }
    cout << ans.size() << "\n";
    f(0, ans.size()) cout << ans[i].first << " " << ans[i].second << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}