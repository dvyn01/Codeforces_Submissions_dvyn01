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
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll a[400050], b[400050], ans[400050];
pl t[8000050];

void create(ll node, ll start, ll end)
{
    if (start == end)
    {
        t[node].first = a[start];
        t[node].second = start;
        return;
    }
    ll mid = start + end >> 1;
    create(node << 1, start, mid);
    create(node << 1 ^ 1, mid + 1, end);
    t[node].first = min(t[node << 1].first, t[node << 1 ^ 1].first);
    if (t[node].first == t[node << 1].first)
        t[node].second = t[node << 1].second;
    else
        t[node].second = t[node << 1 ^ 1].second;
}

pl query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l || l > r)
        return {1e18, -1};
    if (start >= l && end <= r)
        return t[node];
    ll mid = start + end >> 1;
    pl p1 = query(node << 1, start, mid, l, r), p2 = query(node << 1 ^ 1, mid + 1, end, l, r);
    if (p1.first <= p2.first)
        return p1;
    else
        return p2;
}

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
    f(1, n + 1) cin >> a[i], a[i + n] = a[i];
    n *= 2;
    create(1, 1, n);
    f(0, n + 10) ans[i] = 1e18;
    f(1, n / 2 + 1)
    {
        ll l = i + 1, r = n, l1 = i + 1;
        if (l > r)
            continue;
        pl p = query(1, 1, n, l, r);
        if (2 * p.first > a[i])
            continue;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            pl p = query(1, 1, n, l1, mid);
            ll val = p.first, in = p.second;
            if (2 * val < a[i])
            {
                ans[i] = min(ans[i], in);
                r = in - 1;
            }
            else
                l = mid + 1;
        }
    }
    f(1, n / 2 + 1) if (ans[i] < 1e9) ans[i] = ans[i] - i;
    f(1, n / 2 + 1) ans[i + n / 2] = ans[i];
    ll mn = 1e18, in = -1;
    fr(n, 1)
    {
        if (mn + in - j < ans[j])
            ans[j] = mn + in - j;
        if (ans[j] <= mn + in - j)
            mn = ans[j], in = j;
        if (ans[j] >= 1e9)
            ans[j] = -1;
    }
    f(1, n / 2 + 1) cout << ans[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}