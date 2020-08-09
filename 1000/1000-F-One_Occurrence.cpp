#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll int
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

vector<pair<pair<ll, ll>, ll>> queries;
ll n, a[500001], blockSize, moLeft, moRight, ans[500001], fr[500001];
vll v;
bool present[500001];

void add(ll val)
{
    fr[val]++;
    if (fr[val] == 1 && !present[val])
        present[val] = true, v.pb(val);
}

void remove(ll val)
{
    fr[val]--;
    if (fr[val] == 1 && !present[val])
        present[val] = true, v.pb(val);
}

ll query(ll l, ll r)
{
    if (moLeft == -1 && moRight == -1)
    {
        moLeft = l;
        f(l, r + 1)
            add(a[i]);
        moRight = r;
    }
    while (moLeft < l)
        remove(a[moLeft++]);
    while (moLeft > l)
        add(a[--moLeft]);
    while (moRight < r)
        add(a[++moRight]);
    while (moRight > r)
        remove(a[moRight--]);
    while (fr[v.back()] != 1)
        present[v.back()] = false, v.pop_back();
    return v.back();
}

bool compare(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first / blockSize == b.first.first / blockSize)
    {
        if ((a.first.first / blockSize) & 1)
            return a.first.second < b.first.second;
        return a.first.second > b.first.second;
    }
    return a.first.first / blockSize < b.first.first / blockSize;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v.pb(0);
    fr[0] = 1;
    ll l, r;
    cin >> n;
    f(1, n + 1) cin >> a[i];
    blockSize = sqrt(n);
    ll q;
    cin >> q;
    f(0, q) cin >> l >> r, queries.pb({{l, r}, i});
    sort(queries.begin(), queries.end(), compare);
    moLeft = -1, moRight = -1;
    f(0, q)
        ans[queries[i].second] = query(queries[i].first.first, queries[i].first.second);
    f(0, q) cout << ans[i] << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}