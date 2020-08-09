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
pll ans;

void connect1(ll l, ll r)
{
    f(l, r) ans.pb({i, i + 1}), i++;
}

void connect2(ll l1, ll r1, ll l2, ll r2)
{
    f(l1, r1 + 1)
        fi(l2, r2 + 1) ans.pb({i, j});
}

void connect3(ll l, ll r, ll k)
{
    f(l, r + 1) ans.pb({i, k});
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;
    if (!(k & 1))
    {
        cout << "NO\n";
        return 0;
    }
    if (k == 1)
    {
        cout << "YES\n";
        cout << "2 1\n1 2\n";
        return 0;
    }
    cout << "YES\n";
    cout << 4 * k - 2 << ' ' << 2 * k * k - k << '\n';
    connect1(1, k - 1);
    connect2(1, k - 1, k, 2 * k - 2);
    connect3(k, 2 * k - 2, 2 * k - 1);
    ans.pb({2 * k - 1, 2 * k});
    connect3(2 * k + 1, 3 * k - 1, 2 * k);
    connect1(3 * k, 4 * k - 2);
    connect2(3 * k, 4 * k - 2, 2 * k + 1, 3 * k - 1);
    f(0, ans.size()) cout << ans[i].first << ' ' << ans[i].second << '\n';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}