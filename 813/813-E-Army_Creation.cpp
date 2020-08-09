/*
    * AUTHOR : Divyanshu *
*/

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

struct node
{
    node *left = NULL;
    node *right = NULL;
    ll v = 0;
};

ll a[1000050], n, k, q;
vll pre[1000050];
node *version[1000050], *root;

void create(node *current, ll start, ll end)
{
    if (start == end)
        return;
    ll mid = start + end >> 1;
    current->left = new node();
    current->right = new node();
    create(current->left, start, mid);
    create(current->right, mid + 1, end);
}

void update(node *current, node *prev, ll start, ll end, ll in, ll val)
{
    if (start == end)
    {
        current->v = val;
        return;
    }
    ll mid = start + end >> 1;
    if (in <= mid)
    {
        if (current->left == NULL)
            current->left = new node();
        if (current->right == NULL)
            current->right = prev->right;
        update(current->left, prev->left, start, mid, in, val);
    }
    else
    {
        if (current->right == NULL)
            current->right = new node();
        if (current->left == NULL)
            current->left = prev->left;
        update(current->right, prev->right, mid + 1, end, in, val);
    }
    current->v = current->left->v + current->right->v;
}

ll query(node *current, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l || start > end)
        return 0;
    if (start >= l && end <= r)
        return current->v;
    ll mid = start + end >> 1;
    return query(current->left, start, mid, l, r) + query(current->right, mid + 1, end, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    f(1, n + 1) cin >> a[i];
    root = new node();
    create(root, 1, n);
    version[0] = root;
    cin >> q;
    f(1, n + 1)
    {
        version[i] = new node();
        if (pre[a[i]].size() >= k)
            update(version[i], version[i - 1], 1, n, pre[a[i]][pre[a[i]].size() - k], 0);
        update(version[i], version[i - 1], 1, n, i, 1);
        pre[a[i]].pb(i);
    }
    ll ans = 0;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        x = (x + ans) % n + 1;
        y = (y + ans) % n + 1;
        if (x > y)
            swap(x, y);
        ans = query(version[y], 1, n, x, y);
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}