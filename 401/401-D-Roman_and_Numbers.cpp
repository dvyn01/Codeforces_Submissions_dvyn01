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

int m, lim;
ll ans, dp[1LL << 18][100];
string n;

ll rec(ll mask, int currentMod)
{
    if (mask == (1LL << lim) - 1)
        return currentMod == 0;
    if (dp[mask][currentMod] != -1)
        return dp[mask][currentMod];
    ll k = 0;
    int used[10];
    memset(used, 0, sizeof(used));
    f(0, lim)
    {
        if (!((1LL << i) & mask))
        {
            if (mask == 0 && n[i] == '0')
                continue;
            if (used[n[i] - '0'])
                continue;
            int newMod = ((currentMod * 10) + (n[i] - '0')) % m;
            k += rec(mask ^ (1LL << i), newMod);
            used[n[i] - '0'] = 1;
        }
    }
    return dp[mask][currentMod] = k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if (n == "1000000000000000000")
    {
        if (1000000000000000000 % m == 0)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    lim = n.length();
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0, 0);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}