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

const ll N = 10005;

bool b[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, l = 0, n = 0, len = 0;
    cin >> k;
    if (k == 1)
    {
        cout << 2 << '\n';
        cout << "NY\nYN\n";
        return 0;
    }
    if (k == 2)
    {
        cout << 4 << '\n';
        cout << "NNYY\nNNYY\nYYNN\nYYNN\n";
        return 0;
    }
    ll cur = 3, last = 0;
    while (k)
    {
        ll x = 1, c = 3;
        while (x <= k)
            x *= c++;
        c--;
        x /= c;
        c--;
        if (x == 1)
            c = 2;
        k -= x;
        len = max(len, c);
        vll v;
        v.pb(1);
        ll cur1 = 3;
        f(2, c - 1)
        {
            vll v1;
            fi(0, v.size()) fii(0, i + 1) b[v[j]][cur1 + k] = 1, b[cur1 + k][v[j]] = 1;
            fi(0, i + 1) v1.pb(cur1 + j);
            cur1 += i + 1;
            v.clear();
            v = v1;
        }
        if (c != 2)
        {
            if (last == 0)
                last = cur1;
            vll v1;
            fi(0, v.size()) fii(0, c) b[v[j]][last + k] = 1, b[last + k][v[j]] = 1;
            fi(0, c) v1.pb(last + j);
            last += c;
            v.clear();
            v = v1;
        }
        while (c <= len)
        {
            if (c == len)
            {
                f(0, v.size())
                    b[v[i]][2] = 1,
                    b[2][v[i]] = 1;
                break;
            }
            f(0, v.size()) b[v[i]][last] = 1, b[last][v[i]] = 1;
            last++;
            v.clear();
            v.pb(last - 1);
            c++;
        }
    }
    last--;
    cout << last << '\n';
    f(1, last + 1)
    {
        fi(1, last + 1)
        {
            if (b[i][j])
                cout << 'Y';
            else
                cout << 'N';
        }
        cout << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}