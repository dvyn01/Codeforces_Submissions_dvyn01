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
        bool b[n + 1], done[n + 1];
        memset(b, false, sizeof(b));
        memset(done, false, sizeof(done));
        vll v[n + 1];
        f(1, n + 1)
        {
            ll k;
            cin >> k;
            v[i].resize(k);
            fi(0, k) cin >> v[i][j];
        }
        f(1, n + 1)
        {
            fi(0, v[i].size())
            {
                if (!b[v[i][j]])
                {
                    b[v[i][j]] = true;
                    done[i] = true;
                    break;
                }
            }
        }
        bool ok = false;
        f(1, n + 1)
        {
            if (!done[i])
            {
                fi(1, n + 1)
                {
                    if (!b[j])
                    {
                        ok = true;
                        cout << "IMPROVE\n";
                        cout << i << " " << j << "\n";
                        break;
                    }
                }
                break;
            }
        }
        if (!ok)
            cout << "OPTIMAL\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}