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

ll n, a[200005], c[200005], cc[200005];

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
        cin >> n;
        f(1, n + 1) cin >> a[i];
        f(1, n + 1)
        {
            ll k = 1;
            if (c[i - 1] == 1)
                k = 2;
            ll j = i;
            while (j <= n && a[j] == a[i])
                c[j] = k, j++;
            i = j - 1;
        }
        if (c[1] == c[n] && a[1] != a[n])
        {
            bool ok = false;
            f(1, n)
            {
                if (c[i] == c[i + 1])
                {
                    fi(i + 1, n + 1)
                    {
                        if (c[j] == 1)
                            c[j] = 2;
                        else
                            c[j] = 1;
                    }
                    ok = true;
                    break;
                }
            }
            if (!ok)
                c[n] = 3;
        }
        ll mx = 0;
        f(1, n + 1) mx = max(mx, c[i]);
        cout << mx << '\n';
        f(1, n + 1) cout << c[i] << " ";
        cout << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}