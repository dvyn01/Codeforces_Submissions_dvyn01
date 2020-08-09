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
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << "! " << 1 << " " << 1 << endl;
            continue;
        }
        vll km, zyada;
        f(0, n / 2)
        {
            cout << "? " << i + 1 << " " << n / 2 + i + 1 << endl;
            char c;
            cin >> c;
            if (c == '>' || c == '=')
                zyada.pb(i + 1), km.pb(n / 2 + i + 1);
            else
                zyada.pb(n / 2 + i + 1), km.pb(i + 1);
        }
        ll ansKm = -1, ansZyada = -1;
        if (km.size() == 1)
            ansKm = km[0];
        else
        {
            ansKm = km[0];
            f(1, km.size())
            {
                cout << "? " << ansKm << " " << km[i] << endl;
                char c;
                cin >> c;
                if (c == '>')
                    ansKm = km[i];
            }
        }
        if (zyada.size() == 1)
            ansZyada = zyada[0];
        else
        {
            ansZyada = zyada[0];
            f(1, zyada.size())
            {
                cout << "? " << ansZyada << " " << zyada[i] << endl;
                char c;
                cin >> c;
                if (c == '<')
                    ansZyada = zyada[i];
            }
        }
        if (n & 1)
        {
            cout << "? " << ansKm << " " << n << endl;
            char c;
            cin >> c;
            if (c == '>')
                ansKm = n;
            cout << "? " << ansZyada << " " << n << endl;
            cin >> c;
            if (c == '<')
                ansZyada = n;
        }
        cout << "! " << ansKm << " " << ansZyada << endl;
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}