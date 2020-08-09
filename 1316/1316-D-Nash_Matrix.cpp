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

ll n, x[1005][1005], y[1005][1005];
map<pair<ll, ll>, ll> X;
char ans[1005][1005];

bool safe(ll x, ll y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}

void dfs(ll cx, ll cy, ll dx, ll dy)
{
    if (safe(cx - 1, cy) && x[cx - 1][cy] == dx && y[cx - 1][cy] == dy && ans[cx - 1][cy] == '*')
        ans[cx - 1][cy] = 'D', dfs(cx - 1, cy, dx, dy);
    if (safe(cx + 1, cy) && x[cx + 1][cy] == dx && y[cx + 1][cy] == dy && ans[cx + 1][cy] == '*')
        ans[cx + 1][cy] = 'U', dfs(cx + 1, cy, dx, dy);
    if (safe(cx, cy - 1) && x[cx][cy - 1] == dx && y[cx][cy - 1] == dy && ans[cx][cy - 1] == '*')
        ans[cx][cy - 1] = 'R', dfs(cx, cy - 1, dx, dy);
    if (safe(cx, cy + 1) && x[cx][cy + 1] == dx && y[cx][cy + 1] == dy && ans[cx][cy + 1] == '*')
        ans[cx][cy + 1] = 'L', dfs(cx, cy + 1, dx, dy);
}

void dfs2(ll cx, ll cy)
{
    if (safe(cx - 1, cy) && x[cx - 1][cy] == -1 && y[cx - 1][cy] == -1 && ans[cx - 1][cy] == '*')
        ans[cx - 1][cy] = 'D', dfs2(cx - 1, cy);
    if (safe(cx + 1, cy) && x[cx + 1][cy] == -1 && y[cx + 1][cy] == -1 && ans[cx + 1][cy] == '*')
        ans[cx + 1][cy] = 'U', dfs2(cx + 1, cy);
    if (safe(cx, cy + 1) && x[cx][cy + 1] == -1 && y[cx][cy + 1] == -1 && ans[cx][cy + 1] == '*')
        ans[cx][cy + 1] = 'L', dfs2(cx, cy + 1);
    if (safe(cx, cy - 1) && x[cx][cy - 1] == -1 && y[cx][cy - 1] == -1 && ans[cx][cy - 1] == '*')
        ans[cx][cy - 1] = 'R', dfs2(cx, cy - 1);
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
    f(0, n + 1) fi(0, n + 1) ans[i][j] = '*';
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            cin >> x[i][j] >> y[i][j];
            if (x[i][j] != -1 && y[i][j] != -1)
                X[{x[i][j], y[i][j]}] = 1;
        }
    }
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            if (x[i][j] == -1 && y[i][j] == -1)
                continue;
            if (x[x[i][j]][y[i][j]] != x[i][j] || y[x[i][j]][y[i][j]] != y[i][j])
            {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    for (auto it : X)
        ans[it.first.first][it.first.second] = 'X', dfs(it.first.first, it.first.second, it.first.first, it.first.second);
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            if (x[i][j] == -1 && y[i][j] == -1 && ans[i][j] == '*')
            {
                if (safe(i + 1, j) && ans[i + 1][j] == '*' && x[i + 1][j] == -1 && y[i + 1][j] == -1)
                    ans[i][j] = 'D', ans[i + 1][j] = 'U', dfs2(i, j), dfs2(i + 1, j);
                if (safe(i - 1, j) && ans[i - 1][j] == '*' && x[i - 1][j] == -1 && y[i - 1][j] == -1)
                    ans[i][j] = 'U', ans[i - 1][j] = 'D', dfs2(i, j), dfs2(i - 1, j);
                if (safe(i, j + 1) && ans[i][j + 1] == '*' && x[i][j + 1] == -1 && y[i][j + 1] == -1)
                    ans[i][j] = 'R', ans[i][j + 1] = 'L', dfs2(i, j), dfs2(i, j + 1);
                if (safe(i, j - 1) && ans[i][j - 1] == '*' && x[i][j - 1] == -1 && y[i][j - 1] == -1)
                    ans[i][j] = 'L', ans[i][j - 1] = 'R', dfs2(i, j), dfs2(i, j - 1);
            }
        }
    }
    f(1, n + 1)
    {
        fi(1, n + 1)
        {
            if (ans[i][j] == '*')
            {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    f(1, n + 1)
    {
        fi(1, n + 1) cout << ans[i][j];
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}