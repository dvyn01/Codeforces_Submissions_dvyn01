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

ll s[200005], e[200005], a[200005], t[8000005];
vector<pair<ll, pair<ll, ll>>> p;

void update(ll node, ll start, ll end, ll in, ll val)
{
    if (start == end)
    {
        t[node] = val;
        return;
    }
    ll mid = start + end >> 1;
    if (in <= mid)
        update(node << 1, start, mid, in, val);
    else
        update(node << 1 ^ 1, mid + 1, end, in, val);
    t[node] = min(t[node << 1], t[node << 1 ^ 1]);
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l)
        return 1e18;
    if (start >= l && end <= r)
        return t[node];
    ll mid = start + end >> 1;
    return min(query(node << 1, start, mid, l, r), query(node << 1 ^ 1, mid + 1, end, l, r));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    bool done = false;
    cin >> n >> q;
    set<ll> x;
    f(1, n + 1)
    {
        cin >> a[i];
        if (a[i] == q)
            done = true;
        if (a[i] != 0)
            update(1, 1, n, i, a[i]);
        else
            x.insert(i), update(1, 1, n, i, 1e18);
    }
    if (!done)
    {
        f(1, n + 1)
        {
            if (a[i] == 0)
            {
                a[i] = q, done = true;
                update(1, 1, n, i, q);
                break;
            }
        }
        if (!done)
        {
            cout << "NO";
            return 0;
        }
    }
    f(0, q + 1) s[i] = 1e18;
    f(1, n + 1) s[a[i]] = min(s[a[i]], i), e[a[i]] = max(e[a[i]], i);
    f(1, q + 1) if (s[i] != 1e18) p.pb({i, {s[i], e[i]}});
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    f(0, p.size())
    {
        ll val = p[i].first, l = p[i].second.first, r = p[i].second.second;
        ll k = query(1, 1, n, l, r);
        if (k < val)
        {
            cout << "NO";
            return 0;
        }
        while (!x.empty())
        {
            auto it = x.lower_bound(l);
            if (it == x.end() || *it > r)
                break;
            a[*it] = val;
            update(1, 1, n, *it, val);
            x.erase(it);
        }
    }
    f(2, n + 1) if (a[i] == 0) a[i] = a[i - 1];
    fr(n - 1, 0) if (a[j] == 0) a[j] = a[j + 1];
    cout << "YES\n";
    f(1, n + 1) cout << a[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}