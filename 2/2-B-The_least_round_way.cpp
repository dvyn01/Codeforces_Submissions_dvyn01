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

const ll N = 1005;
ll x, t[N][N], f[N][N], n, zx, zy;
pair<ll, ll> dp1[N][N], dp2[N][N]; // min2, min5
string ans;
bool two;

bool safe(ll x, ll y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}

void recover(ll i, ll j)
{
    if (i == 1 && j == 1)
        return;
    if (two)
    {
        if (safe(i - 1, j) && dp1[i - 1][j].first + t[i][j] == dp1[i][j].first && dp1[i - 1][j].second + f[i][j] == dp1[i][j].second)
        {
            ans.pb('D');
            return recover(i - 1, j);
        }
        if (safe(i, j - 1) && dp1[i][j - 1].first + t[i][j] == dp1[i][j].first && dp1[i][j - 1].second + f[i][j] == dp1[i][j].second)
        {
            ans.pb('R');
            return recover(i, j - 1);
        }
    }
    else
    {
        if (safe(i - 1, j) && dp2[i - 1][j].first + t[i][j] == dp2[i][j].first && dp2[i - 1][j].second + f[i][j] == dp2[i][j].second)
        {
            ans.pb('D');
            return recover(i - 1, j);
        }
        if (safe(i, j - 1) && dp2[i][j - 1].first + t[i][j] == dp2[i][j].first && dp2[i][j - 1].second + f[i][j] == dp2[i][j].second)
        {
            ans.pb('R');
            return recover(i, j - 1);
        }
    }
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
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            cin >> x;
            if (x == 0)
            {
                zx = i;
                zy = j;
                continue;
            }
            while (x % 2 == 0)
                t[i][j]++, x /= 2;
            while (x % 5 == 0)
                f[i][j]++, x /= 5;
        }
    }
    f(1, n + 1) fi(1, n + 1) dp1[i][j] = {-1e18, -1e18}, dp2[i][j] = {-1e18, -1e18};
    dp1[1][1] = {t[1][1], f[1][1]}, dp2[1][1] = {t[1][1], f[1][1]};
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            if (i == 1 && j == 1)
                continue;
            if (safe(i - 1, j))
                dp1[i][j] = dp1[i - 1][j], dp2[i][j] = dp2[i - 1][j];
            if (safe(i, j - 1))
            {
                if (dp1[i][j].first == -1e18)
                    dp1[i][j] = dp1[i][j - 1], dp2[i][j] = dp2[i][j - 1];
                if (dp1[i][j].first != -1e18 && dp1[i][j - 1].first < dp1[i][j].first)
                    dp1[i][j] = dp1[i][j - 1];
                if (dp2[i][j].first != -1e18 && dp2[i][j - 1].second < dp2[i][j].second)
                    dp2[i][j] = dp2[i][j - 1];
            }
            dp1[i][j].first += t[i][j], dp1[i][j].second += f[i][j];
            dp2[i][j].first += t[i][j], dp2[i][j].second += f[i][j];
            // cout << i << ' ' << j << ' ' << dp1[i][j] << ' ' << dp2[i][j] << ' ' << t[i][j] << ' ' << f[i][j] << '\n';
        }
    }
    ll ansVal = min(dp1[n][n].first, dp2[n][n].second);
    if (ansVal > 1 && zx != 0 && zy != 0)
    {
        cout << 1 << '\n';
        ll cx = 1, cy = 1;
        while (cx < zx)
            cx++, ans.pb('D');
        while (cy < zy)
            cy++, ans.pb('R');
        while (cx < n)
            cx++, ans.pb('D');
        while (cy < n)
            cy++, ans.pb('R');
        cout << ans;
        return 0;
    }
    if (dp1[n][n].first <= dp2[n][n].second)
        two = true;
    recover(n, n);
    reverse(ans.begin(), ans.end());
    cout << ansVal << '\n';
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}