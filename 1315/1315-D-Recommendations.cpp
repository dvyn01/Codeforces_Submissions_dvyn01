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
ostream &operator<<(ostream &os, multiset<T> S)
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

ll a[200005], t[200005];
map<ll, vll> m;

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
    f(1, n + 1) cin >> a[i];
    f(1, n + 1) cin >> t[i];
    f(1, n + 1)
    {
        if (m.find(a[i]) == m.end())
        {
            vll v;
            m[a[i]] = v;
        }
        m[a[i]].pb(t[i]);
    }
    ll ans = 0, sum = 0;
    // cout << m << "\n";
    multiset<ll> s;
    for (auto it : m)
    {
        ll in = it.first;
        vll v = it.second;
        fi(0, v.size()) s.insert(v[j]), sum += v[j];
        // cout << s << "\n";
        if (s.size() == 1)
        {
            sum = 0;
            s.clear();
            continue;
        }
        sum -= *(--s.end());
        s.erase(--s.end());
        in++;
        while (s.size() > 0 && m.find(in) == m.end())
        {
            // cout << s << "\n";
            ans += sum;
            // cout << ans << "\n";
            sum -= *(--s.end());
            s.erase(--s.end());
            // cout << s << "\n";
            in++;
        }
        if (s.size() > 0)
            ans += sum;
        // cout << ans << "\n";
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}