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
#define pl pair<ll, ll>
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

map<string, ll> m;

ll nc3(ll n)
{
    if (n < 3)
        return 0;
    return n * (n - 1) * (n - 2) / 6;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, kk;
    cin >> n >> kk;
    string s[n];
    f(0, n) cin >> s[i], m[s[i]]++;
    ll ans = 0;
    f(0, n)
    {
        fi(i + 1, n)
        {
            if (s[i] == s[j])
                continue;
            string r;
            fii(0, kk)
            {
                if (s[i][k] != s[j][k])
                {
                    bool b[3];
                    memset(b, false, sizeof(b));
                    if (s[i][k] == 'E' || s[j][k] == 'E')
                        b[0] = true;
                    if (s[i][k] == 'S' || s[j][k] == 'S')
                        b[1] = true;
                    if (s[i][k] == 'T' || s[j][k] == 'T')
                        b[2] = true;
                    if (!b[0])
                        r.pb('E');
                    else if (!b[1])
                        r.pb('S');
                    else
                        r.pb('T');
                }
                else
                    r.pb(s[i][k]);
            }
            if (m.find(r) != m.end())
                ans += m[r];
        }
    }
    ans /= 3;
    for (auto it : m)
        ans += nc3(it.second);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}