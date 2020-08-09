#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll int
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

pll p[260];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vll v[n];
    f(0, n)
    {
        v[i].resize(m);
        fi(0, m) cin >> v[i][j];
    }
    f(1, (1LL << m) + 4) p[i].pb({0, 0}), p[i].pb({0, 0});
    f(0, n)
    {
        fi(1, 1LL << m)
        {
            ll mx = 1e9;
            fii(0, m) if (j & (1LL << k)) mx = min(mx, v[i][k]);
            if (mx >= p[j][0].first)
                p[j][1].first = p[j][0].first, p[j][1].second = p[j][0].second, p[j][0].first = mx, p[j][0].second = i;
            else if (mx > p[j][1].first)
                p[j][1].first = mx, p[j][1].second = i;
        }
    }
    ll ans = 0, l = 0, r = 0;
    fi(1, 1LL << m)
    {
        ll k = (1LL << m) - 1;
        k ^= j;
        // cout << j << " " << k << " ";
        // cout << p[j] << " " << p[k] << "\n";
        if (k == 0)
        {
            if (p[j][0].first > ans)
                ans = p[j][0].first, l = p[j][0].second, r = p[j][1].second;
            continue;
        }
        if (p[j][0].second == p[k][0].second)
        {
            if (min(p[j][0].first, p[k][1].first) >= min(p[j][1].first, p[k][0].first))
            {
                if (min(p[j][0].first, p[k][1].first) > ans)
                    ans = min(p[j][0].first, p[k][1].first), l = p[j][0].second, r = p[k][1].second;
            }
            else
            {
                if (min(p[j][1].first, p[k][0].first) > ans)
                    ans = min(p[j][1].first, p[k][0].first), l = p[j][1].second, r = p[k][0].second;
            }
        }
        else
        {
            if (min(p[j][0].first, p[k][0].first) > ans)
                ans = min(p[j][0].first, p[k][0].first), l = p[j][0].second, r = p[k][0].second;
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}