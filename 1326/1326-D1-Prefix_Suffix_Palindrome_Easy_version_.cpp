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

bool pal[5005][5005], c[5005][5005], done[5005];
ll ii[5005], jj[5005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tt;
    cin >> tt;
    while (tt--)
    {
        string s, t;
        cin >> s;
        ll n = s.length();
        f(0, n + 2) ii[i] = 0, jj[i] = 0, done[i] = false;
        f(0, n + 1) fi(0, n + 1) pal[i][j] = false, c[i][j] = false;
        f(0, n) pal[i][i] = true;
        f(0, n - 1) if (s[i] == s[i + 1]) pal[i][i + 1] = true;
        fi(3, n + 1)
        {
            f(0, n - j + 1)
            {
                if (s[i] == s[i + j - 1] && pal[i + 1][i + j - 2])
                    pal[i][i + j - 1] = true;
            }
        }
        if (pal[0][n - 1])
        {
            cout << s << "\n";
            continue;
        }
        ll l = 0, r = n - 1;
        while (l <= r)
        {
            if (s[l] == s[r])
                c[l][r] = true, l++, r--;
            else
                break;
        }
        f(0, n)
        {
            fi(i + 1, n)
            {
                ll len = i + 1 + n - j;
                if (i >= n - j - 1)
                {
                    if (c[n - j - 1][j])
                    {
                        ll k1 = n - j;
                        if (k1 > i || (k1 <= i && pal[k1][i]))
                        {
                            done[len] = true;
                            ii[len] = i, jj[len] = j;
                        }
                    }
                }
                else
                {
                    if (c[i][n - i - 1])
                    {
                        ll k1 = n - i - 2;
                        if (j > k1 || (j <= k1 && pal[j][k1]))
                        {
                            done[len] = true;
                            ii[len] = i, jj[len] = j;
                        }
                    }
                }
            }
        }
        f(0, n)
        {
            if (pal[0][i])
            {

                done[i + 1] = true;
                ii[i + 1] = i, jj[i + 1] = 1e18;
            }
        }
        f(0, n)
        {
            if (pal[i][n - 1])
            {
                done[n - i] = true;
                ii[n - i] = -1, jj[n - i] = i;
            }
        }
        fr(n, 0)
        {
            if (done[j])
            {
                f(0, ii[j] + 1)
                        cout
                    << s[i];
                f(jj[j], n)
                        cout
                    << s[i];
                cout << "\n";
                break;
            }
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}