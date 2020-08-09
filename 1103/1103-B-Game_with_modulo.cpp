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

int main()
{

    string s;
    char c;
    while (1)
    {
        cin >> s;
        if (s == "end" || s == "mistake")
            break;
        string k;
        cout << "? 1 2" << endl;
        cin >> c;
        k.pb(c);
        if (c == 'x')
        {
            cout << "? 2 3" << endl;
            cin >> c;
            if (c == 'e')
                return 0;
            k.pb(c);
            if (k == "xx")
            {
                cout << "! 1" << endl;
                continue;
            }
            if (k == "xy")
            {
                cout << "! 2" << endl;
                continue;
            }
        }
        ll l = 2, h = 4, ans;
        while (1)
        {
            cout << "? " << l << " " << h << endl;
            cin >> c;
            if (c == 'e')
                return 0;
            if (c == 'x')
                break;
            l <<= 1;
            h <<= 1;
        }
        cout << "? " << l << " " << h - 1 << endl;
        cin >> c;
        if (c == 'e')
            return 0;
        if (c == 'y')
        {
            cout << "! " << h << endl;
            continue;
        }
        h--;
        ll lastL = -1, lastH = -1;
        while (l + 1 < h)
        {
            ll mid = l + h >> 1;
            cout << "? " << l << " " << mid << endl;
            lastL = l, lastH = mid;
            cin >> c;
            if (c == 'e')
                return 0;
            if (c == 'x')
                h = mid;
            else
                l = mid;
        }
        if (l == h)
            cout << "! " << l << endl;
        else
        {
            if (!(l == lastL && h == lastH))
                c = 'x';
            if (c == 'e')
                return 0;
            if (c == 'x')
                cout << "! " << h << endl;
            else
                cout << "! " << l << endl;
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
