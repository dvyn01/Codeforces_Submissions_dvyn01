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

const ll N = 200005;
ll n, k, a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    f(1, k + 1) cin >> a[i];
    set<ll> s;
    f(1, n + 1) s.insert(i);
    ll c = 1;
    stack<ll> st;
    f(1, k + 1)
    {
        while (!st.empty() && st.top() == c)
            c++, st.pop();
        if (a[i] == c)
        {
            s.erase(s.find(c));
            c++;
            continue;
        }
        s.erase(s.find(a[i]));
        st.push(a[i]);
    }
    while (!st.empty() && st.top() == c)
        c++, st.pop();
    ll cp = k + 1;
    while (cp <= n)
    {
        if (st.empty())
        {
            for (auto it = s.rbegin(); it != s.rend(); it++)
                a[cp++] = *it;
            break;
        }
        if (c == st.top())
        {
            c++;
            st.pop();
        }
        else
        {
            if (*s.begin() != c)
            {
                cout << -1;
                return 0;
            }
            auto it = s.lower_bound(st.top());
            if (it != s.end() && *it == c)
            {
                cout << -1;
                return 0;
            }
            vll v;
            for (auto it1 = s.begin(); it1 != it; it1++)
                v.pb(*it1);
            f(0, v.size())
                s.erase(s.find(v[i]));
            fr(v.size() - 1, 0) a[cp++] = v[j];
            c = v.back() + 1;
        }
    }
    while (!st.empty() && st.top() == c)
        c++, st.pop();
    if (st.size() > 0)
        cout << -1;
    else
        f(1, n + 1) cout << a[i] << ' ';

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}