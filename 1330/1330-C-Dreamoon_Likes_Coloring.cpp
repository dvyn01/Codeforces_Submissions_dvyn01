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

ll a[100005], ans[100005];
bool b[100005];

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
    f(1, m + 1) cin >> a[i];
    bool ok = true;
    ll la = n;
    f(1, m + 1)
    {
        ll k = la - a[i] + 1;
        if (k < 1)
        {
            ok = false;
            break;
        }
        ans[i] = k;
        la--;
    }
    if (!ok)
    {
        cout << -1;
        return 0;
    }
    ll cp = 1;
    fr(m, 1)
    {
        if (ans[j] > cp)
        {
            ans[j] = cp;
            cp = cp + a[j];
        }
        else
            cp = ans[j] + a[j];
    }
    ll mx = 0;
    f(1, m + 1)
    {
        bool done = false;
        fi(mx + 1, ans[i] + a[i])
        {
            b[j] = true,
            mx = j;
            if (j == n)
            {
                done = true;
                break;
            }
        }
        if (done)
            break;
    }
    if (mx < n)
    {
        cout << -1;
        return 0;
    }
    f(1, m + 1) cout << ans[i] << ' ';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}