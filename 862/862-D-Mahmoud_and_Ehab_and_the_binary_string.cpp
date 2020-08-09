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
ll n, z, o, zero, one;
string s;

ll ask(string s)
{
    cout << "? " << s << endl;
    ll x;
    cin >> x;
    return x;
}

void findOne(ll l, ll r, ll pr, ll turn)
{
    if (l == r)
    {
        one = l;
        return;
    }
    ll mid = l + r >> 1;
    f(l, mid + 1) s[i] = '0';
    f(mid + 1, r + 1) s[i] = '1';
    ll k = ask(s);
    if (turn == 0) // 000000000
    {
        if (k == pr + r - mid)
            return findOne(l, mid, k, 0);
        return findOne(mid + 1, r, k, 1);
    }
    else // 111111111
    {
        if (k == pr - (mid - l + 1))
            return findOne(mid + 1, r, k, 1);
        return findOne(l, mid, k, 0);
    }
}

void findZero(ll l, ll r, ll pr, ll turn)
{
    if (l == r)
    {
        zero = l;
        return;
    }
    ll mid = l + r >> 1;
    f(l, mid + 1) s[i] = '1';
    f(mid + 1, r + 1) s[i] = '0';
    ll k = ask(s);
    if (turn == 0) // 11111111
    {
        if (k == pr + r - mid)
            return findZero(l, mid, k, 0);
        return findZero(mid + 1, r, k, 1);
    }
    else // 000000
    {
        if (k == pr - (mid - l + 1))
            return findZero(mid + 1, r, k, 1);
        return findZero(l, mid, k, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    zero = -1, one = -1;
    cin >> n;
    f(0, n) s.pb('0');
    o = ask(s);
    z = n - o;
    s[0] = '1';
    ll y = ask(s);
    if (y > o)
        zero = 0;
    else
        one = 0;
    s[0] = '0';
    if (zero == -1)
    {
        f(0, n) s[i] = '1';
        findZero(0, n - 1, z, 0);
    }
    else
        findOne(0, n - 1, o, 0);
    cout << "! " << zero + 1 << ' ' << one + 1 << endl;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
