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

bool vis[100];

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    pll p;
    p.pb({xs, ys});
    p.pb({x0, y0});
    f(2, 100)
    {
        if (p[i - 1].first > 20000000000000000 - bx / ax || p[i - 1].second > 20000000000000000 - by / ay)
            break;
        ll xn = p[i - 1].first * ax, yn = p[i - 1].second * ay;
        if (xn > 20000000000000000 || yn > 20000000000000000)
            break;
        xn += bx, yn += by;
        if (xn <= 20000000000000000 && yn <= 20000000000000000)
            p.pb({xn, yn});
        else
            break;
    }
    ll s = 1;
    ll ans = 0;
    // cout << p << '\n';
    while (s < p.size())
    {
        ll k = dist(p[0].first, p[0].second, p[s].first, p[s].second), k1 = s;
        if (k > t)
        {
            s++;
            continue;
        }
        k1++;
        while (k1 < p.size())
        {
            k += dist(p[k1].first, p[k1].second, p[k1 - 1].first, p[k1 - 1].second);
            if (k > t)
                break;
            k1++;
        }
        // cout << s << " " << k1 << "\n";
        ans = max(ans, k1 - s);
        k1 = s - 1;
        k = dist(p[0].first, p[0].second, p[s].first, p[s].second);
        while (k1 >= 1)
        {
            k += dist(p[k1].first, p[k1].second, p[k1 + 1].first, p[k1 + 1].second);
            if (k > t)
                break;
            k1--;
        }
        ans = max(ans, s - k1);
        // cout << s << " " << k1 << "\n";
        s++;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}