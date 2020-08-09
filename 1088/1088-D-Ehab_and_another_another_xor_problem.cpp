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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "? 0 0" << endl;
    bool a = false, b = false, e = false;
    ll an = 0, bn = 0;
    ll c;
    cin >> c;
    if (c == 1)
        a = true;
    else if (c == -1)
        b = true;
    else
        e = true;
    fr(29, 0)
    {
        if (a)
        {
            cout << "? " << (an + (1LL << j)) << " " << (bn + (1LL << j)) << endl;
            cin >> c;
            if (c == 1)
            {
                cout << "? " << an << " " << (bn + (1LL << j)) << endl;
                cin >> c;
                if (c == 1)
                    bn += (1LL << j), an += (1LL << j);
            }
            else
            {
                an += (1LL << j);
                cout << "? " << an << " " << bn << endl;
                cin >> c;
                if (c == 1)
                    a = true, b = false, e = false;
                else if (c == -1)
                    b = true, a = false, e = false;
                else
                    a = false, b = false, e = true;
            }
        }
        else if (b)
        {
            cout << "? " << (an + (1LL << j)) << " " << (bn + (1LL << j)) << endl;
            cin >> c;
            if (c == -1)
            {
                cout << "? " << (an + (1LL << j)) << " " << bn << endl;
                cin >> c;
                if (c == -1)
                    an += (1LL << j), bn += (1LL << j);
            }
            else
            {
                bn += (1LL << j);
                cout << "? " << an << " " << bn << endl;
                cin >> c;
                if (c == 1)
                    a = true, b = false, e = false;
                else if (c == -1)
                    b = true, a = false, e = false;
                else
                    e = true, a = false, b = false;
            }
        }
        else
        {
            cout << "? " << (an + (1LL << j)) << " " << bn << endl;
            cin >> c;
            if (c == -1)
                an += (1LL << j), bn += (1LL << j);
        }
    }
    cout << "! " << an << " " << bn << endl;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
