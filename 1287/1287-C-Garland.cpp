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

    ll o = 0, e = 0;
    ll n, ans = 0;
    cin >> n;
    e = n / 2;
    o = n / 2;
    if (n & 1)
        o++;
    ll a[n];
    vll v;
    f(0, n)
    {
        cin >> a[i];
        if (a[i] == 0)
            continue;
        if (a[i] & 1)
            o--;
        else
            e--;
        v.pb(i);
    }
    vll oo, oe, ee;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    if (v.size() == 0)
    {
        cout << 1;
        return 0;
    }
    f(0, v.size() - 1)
    {
        ll k1 = v[i], k2 = v[i + 1];
        if ((a[k1] & 1) && (a[k2] & 1))
            oo.pb(k2 - k1 - 1);
        else if (!(a[k1] & 1) && !(a[k2] & 1))
            ee.pb(k2 - k1 - 1);
        else
            oe.pb(k2 - k1 - 1);
    }
    sort(oo.begin(), oo.end());
    sort(ee.begin(), ee.end());
    // sort(oe.begin(), oe.end());
    // cout << oo << " " << ee << "\n";
    f(0, oo.size())
    {
        ll k = oo[i];
        if (k <= o)
        {
            o -= k;
            continue;
        }
        else
            ans += 2;
    }
    f(0, ee.size())
    {
        ll k = ee[i];
        if (k <= e)
        {
            e -= k;
            continue;
        }
        else
            ans += 2;
    }
    ans += oe.size();
    oo.clear();
    ee.clear();
    if (v[0] != 0)
    {
        if (a[v[0]] & 1)
        {
            oo.pb(v[0]);
        }
        else
        {
            ee.pb(v[0]);
        }
    }
    if (v[v.size() - 1] != n - 1)
    {
        if (a[v[v.size() - 1]] & 1)
        {
            oo.pb(n - 1 - v[v.size() - 1]);
        }
        else
        {
            ee.pb(n - 1 - v[v.size() - 1]);
        }
    }
    sort(oo.begin(), oo.end());
    sort(ee.begin(), ee.end());
    // cout<<oo<<" "<<ee<<"\n";
    f(0, oo.size())
    {
        if (o >= oo[i])
            o -= oo[i];
        else
            ans++;
    }
    f(0, ee.size())
    {
        if (e >= ee[i])
            e -= ee[i];
        else
            ans++;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}