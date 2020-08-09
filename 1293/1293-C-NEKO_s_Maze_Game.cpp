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

set<pair<ll, ll>> s1, s2;
ll b[100005][2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    while (q--)
    {
        ll r, c;
        cin >> r >> c;
        if (b[c][r])
        {
            ll x;
            if (r == 1)
                x = 2;
            else
                x = 1;
            if (b[c][x])
            {
                s1.erase({c, c});
                s2.erase({c, c});
            }
            if (b[c - 1][x])
            {
                if (r == 1)
                {
                    s1.erase({c, c - 1});
                    s2.erase({c - 1, c});
                }
                else
                {
                    s2.erase({c, c - 1});
                    s1.erase({c - 1, c});
                }
            }
            if (b[c + 1][x])
            {
                if (r == 1)
                {
                    s1.erase({c, c + 1});
                    s2.erase({c + 1, c});
                }
                else
                {
                    s2.erase({c, c + 1});
                    s1.erase({c + 1, c});
                }
            }
        }
        else
        {
            ll x;
            if (r == 1)
                x = 2;
            else
                x = 1;
            if (b[c][x])
            {
                s1.insert({c, c});
                s2.insert({c, c});
            }
            if (b[c - 1][x])
            {
                if (r == 1)
                {
                    s1.insert({c, c - 1});
                    s2.insert({c - 1, c});
                }
                else
                {
                    s2.insert({c, c - 1});
                    s1.insert({c - 1, c});
                }
            }
            if (b[c + 1][x])
            {
                if (r == 1)
                {
                    s1.insert({c, c + 1});
                    s2.insert({c + 1, c});
                }
                else
                {
                    s2.insert({c, c + 1});
                    s1.insert({c + 1, c});
                }
            }
        }
        b[c][r] ^= 1;
        if (s1.size() != 0 || s2.size() != 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}