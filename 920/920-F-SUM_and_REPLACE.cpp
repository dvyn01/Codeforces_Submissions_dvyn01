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

ll n, m, t[2000500], a[1000050], b[1000050], p[300050];

void create(ll node, ll start, ll end)
{
    if (start == end)
    {
        t[node] = p[start];
        return;
    }
    ll mid = start + end >> 1;
    create(node << 1, start, mid);
    create(node << 1 ^ 1, mid + 1, end);
    t[node] = t[node << 1] + t[node << 1 ^ 1];
}

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
    t[node] = t[node << 1] + t[node << 1 ^ 1];
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return t[node];
    ll mid = start + end >> 1;
    return query(node << 1, start, mid, l, r) + query(node << 1 ^ 1, mid + 1, end, l, r);
}

void sieve()
{
    f(1, 1000050) b[i] = i;
    f(2, 1000050)
    {
        if (b[i] == i)
        {
            fi(2 * i, 1000050)
            {
                if (b[j] == j)
                    b[j] = i;
                j += i - 1;
            }
        }
    }
}

ll factors(ll n)
{
    ll p = 1;
    while (n != 1)
    {
        ll x = b[n], c = 0;
        while (n % x == 0)
            n /= x, c++;
        p *= c + 1;
    }
    return p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll q;
    f(2, 1000001) a[i] = factors(i);
    cin >> n >> q;
    f(1, n + 1) cin >> p[i];
    create(1, 1, n);
    set<ll> s; // not one
    f(1, n + 1) if (p[i] > 2) s.insert(i);
    while (q--)
    {
        ll c, l, r;
        cin >> c >> l >> r;
        if (c == 1)
        {
            auto it = s.lower_bound(l);
            vll e;
            for (; it != s.end() && *it <= r; it++)
            {
                update(1, 1, n, *it, a[p[*it]]), p[*it] = a[p[*it]];
                if (p[*it] <= 2)
                    e.pb(*it);
            }
            f(0, e.size()) s.erase(s.find(e[i]));
        }
        else
        {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}