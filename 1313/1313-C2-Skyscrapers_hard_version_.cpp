#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

ll a[500050], b[500050], c[500050], s1[500050], s2[500050];

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
    f(0, n) cin >> a[i];
    vll ans;
    vll v;
    stack<pair<ll, ll>> s;
    f(0, n)
    {
        while (!s.empty() && s.top().first > a[i])
            s.pop();
        if (s.empty())
            b[i] = -1;
        else
            b[i] = s.top().second;
        s.push({a[i], i});
    }
    while (!s.empty())
        s.pop();
    reverse(a, a + n);
    f(0, n)
    {
        while (!s.empty() && s.top().first > a[i])
            s.pop();
        if (s.empty())
            c[i] = -1;
        else
            c[i] = s.top().second;
        s.push({a[i], i});
    }
    reverse(a, a + n);
    f(0, n)
    {
        if (b[i] == -1)
            s1[i] = (i + 1) * a[i];
        else
            s1[i] = (i - b[i]) * a[i] + s1[b[i]];
    }
    reverse(a, a + n);
    f(0, n)
    {
        if (c[i] == -1)
            s2[i] = (i + 1) * a[i];
        else
            s2[i] = (i - c[i]) * a[i] + s2[c[i]];
    }
    reverse(a, a + n);
    // f(0, n) cout << s1[i] << " ";
    // cout << "\n";
    // f(0, n) cout << s2[i] << " ";
    // cout << "\n";
    ll mx = 0, in = -1;
    f(0, n)
    {
        if (i == n - 1)
        {
            if (s1[i] > mx)
            {
                mx = s1[i];
                in = i;
            }
            continue;
        }
        // cout << i << " " << n - i - 2 << " " << s1[i] << " " << s2[n - i - 2] << "\n";
        if (s1[i] + s2[n - i - 2] > mx)
        {
            mx = s1[i] + s2[n - i - 2];
            in = i;
        }
    }
    vll v1, v2;
    ll cc = 1e18;
    fr(in, 0)
    {
        if (cc > a[j])
            cc = a[j];
        v1.pb(cc);
    }
    cc = 1e18;
    // cout << in << "\n";
    fi(in + 1, n)
    {
        if (cc > a[j])
            cc = a[j];
        v2.pb(cc);
    }
    fr(v1.size() - 1, 0)
            cout
        << v1[j] << " ";
    f(0, v2.size()) cout << v2[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}