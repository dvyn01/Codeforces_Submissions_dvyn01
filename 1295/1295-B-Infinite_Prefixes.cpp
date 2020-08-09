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
ostream &operator<<(ostream &os, unordered_map<L, R> M)
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
        ll n, x, ans = 0;
        cin >> n >> x;
        string s;
        cin >> s;
        ll a[n + 1], c = 0;
        map<ll, ll> m;
        f(0, n)
        {
            if (s[i] == '0')
                c++;
            else
                c--;
            m[c]++;
        }
        if (m.find(x) != m.end() && c == 0)
        {
            cout << "-1\n";
            continue;
        }
        if (m.find(x) == m.end() && c == 0)
        {
            cout << "0\n";
            continue;
        }
        if (x == 0)
            ans++;
        if (c > 0)
        {
            if (x > n)
            {
                ll k = x - n;
                k /= c;
                x -= k * c;
                if (x != n)
                    x -= c;
            }
        }
        else
        {
            if (x < -1 * n)
            {
                ll k = abs(-1 * n - x);
                k /= abs(c);
                x += k * abs(c);
                if (x != -1 * n)
                    x += abs(c);
            }
        }
        while (abs(x) <= n)
        {
            if (m.find(x) != m.end())
                ans += m[x];
            x -= c;
        }
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}