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
ll n, l, r;
vll v, ans;

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
        cin >> n >> l >> r;
        v.clear();
        ans.clear();
        v.pb(0);
        v.pb(1);
        f(2, n)
            v.pb(i),
            v.pb(1);
        v.pb(n);
        vll ans;
        if (l < v.size())
        {
            ll k = r;
            if (k > v.size() - 1)
                k = v.size() - 1;
            f(l, k + 1)
                ans.pb(v[i]);
        }
        ll d = r - l + 1;
        d -= ans.size();
        ll c = 2, leave = 0;
        ll k = (n - 2) * 2 + 2;
        if (ans.size() == 0)
        {
            while (k < l && c < n)
            {
                k += 2 + (n - c - 1) * 2;
                c++;
            }
            c--;
            k -= 2 + (n - c - 1) * 2;
            leave = k;
            leave = l - leave - 1;
            d += leave;
        }
        f(0, ans.size()) cout << ans[i] << ' ';
        ans.clear();
        while (d)
        {
            if (c == n)
            {
                ans.pb(1);
                d--;
                break;
            }
            ans.pb(c);
            d--;
            if (d == 0)
                break;
            ll p = c + 1;
            f(0, n - c - 1)
            {
                ans.pb(p);
                d--;
                if (d == 0)
                    break;
                ans.pb(c);
                d--;
                p++;
                if (d == 0)
                    break;
            }
            if (d == 0)
                break;
            ans.pb(n);
            d--;
            c++;
        }
        f(leave, ans.size()) cout << ans[i] << ' ';
        cout << '\n';
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}