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

const ll N = 100005;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll b[n];
    f(0, n) cin >> b[i];
    string ans[n];
    while (b[0] >= 9)
        b[0] -= 9, ans[0].pb('9');
    if (b[0])
        ans[0].pb('0' + b[0]);
    reverse(ans[0].begin(), ans[0].end());
    f(1, n)
    {
        if (9 * ans[i - 1].length() < b[i] || b[i] <= (ans[i - 1][0] - '0'))
        {
            b[i]--;
            while (b[i] >= 9)
                b[i] -= 9, ans[i].pb('9');
            if (b[i])
                ans[i].pb('0' + b[i]);
            while (ans[i].size() < ans[i - 1].size())
                ans[i].pb('0');
            ans[i].pb('1');
            reverse(ans[i].begin(), ans[i].end());
        }
        else
        {
            ll tot = 0;
            fi(0, ans[i - 1].length()) tot += ans[i - 1][j] - '0';
            bool pos = false;
            fr(ans[i - 1].length() - 1, 0)
            {
                tot -= ans[i - 1][j] - '0';
                if (ans[i - 1][j] == '9')
                    continue;
                fii(ans[i - 1][j] - '0', 10)
                {
                    ll rem = (ans[i - 1].length() - j - 1) * 9;
                    if (rem + tot + k >= b[i] && tot + k <= b[i])
                    {
                        ll p = b[i];
                        ans[i].clear();
                        // cout << i << ' ' << j << ' ' << k << ' ' << tot << '\n';
                        for (ll l = 0; l < j; l++)
                            ans[i].pb(ans[i - 1][l]);
                        ans[i].pb('0' + k);
                        b[i] -= tot + k;
                        string x;
                        while (b[i] >= 9)
                            b[i] -= 9, x.pb('9');
                        if (b[i])
                            x.pb('0' + b[i]);
                        while (x.length() < ans[i - 1].length() - j - 1)
                            x.pb('0');
                        reverse(x.begin(), x.end());
                        ans[i] += x;
                        // cout << ans[i] << '\n';
                        b[i] = p;
                        if (ans[i] > ans[i - 1])
                        {
                            pos = true;
                            break;
                        }
                    }
                }
                if (pos)
                    break;
            }
            if (!pos)
            {
                ans[i].clear();
                b[i]--;
                while (b[i] >= 9)
                    b[i] -= 9, ans[i].pb('9');
                if (b[i])
                    ans[i].pb('0' + b[i]);
                while (ans[i].size() < ans[i - 1].size())
                    ans[i].pb('0');
                ans[i].pb('1');
                reverse(ans[i].begin(), ans[i].end());
            }
        }
    }
    f(0, n) cout << ans[i] << '\n';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}