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

double dp[1LL << 18][18], m[18][18];
ll n;

double rec(ll mask, ll win)
{
    if (((1LL << 0) & mask) && (win != 0))
        return 0.0;
    if (mask == ((1LL << n) - 1))
        return 1.0;
    if (dp[mask][win] != -1.0)
        return dp[mask][win];
    double k = 0.0;
    f(0, n)
    {
        if (!((1LL << i) & mask))
        {
            if (((1LL << 0) & mask))
                k = max(k, m[0][i] * rec(mask | (1LL << i), 0));
            else if (i == 0)
                k = max(k, m[0][win] * rec(mask | (1LL << i), 0));
            else
                k = max(k, (m[win][i] * rec(mask | (1LL << i), win) + m[i][win] * rec(mask | (1LL << i), i)));
        }
    }
    return dp[mask][win] = k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    f(0, 1LL << n) fi(0, n) dp[i][j] = -1.0;
    f(0, n) fi(0, n) cin >> m[i][j];
    if (n == 1)
    {
        cout << fixed << setprecision(16) << 1.0;
        return 0;
    }
    double ans = 0;
    f(0, n)
    {
        fi(i + 1, n)
        {
            ll k = (1LL << i) + (1LL << j);
            ans = max(ans, m[i][j] * rec(k, i) + m[j][i] * rec(k, j));
        }
    }
    cout << fixed << setprecision(16) << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}