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
pll ans;

void rec(vll v, ll p1, ll p2)
{
    if (v.size() == 0)
    {
        // cout << p1 << " " << p2 << "\n";
        ans.pb({max(p1, p2), min(p1, p2)});
        return;
    }
    ll k = v.back();
    v.pop_back();
    rec(v, p1 * k, p2);
    rec(v, p1, p2 * k);
}

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
    if (n == 1)
    {
        cout << "1 1";
        return 0;
    }
    vll v;
    ans.pb({n, 1});
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll c = 0;
            while (n % i == 0)
                n /= i, c++;
            v.pb(pow(i, c));
        }
    }
    if (n > 1)
        v.pb(n);
    sort(v.begin(), v.end());
    // cout << v << "\n";
    rec(v, 1, 1);
    sort(ans.begin(), ans.end());
    cout << ans[0].second << " " << ans[0].first << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}