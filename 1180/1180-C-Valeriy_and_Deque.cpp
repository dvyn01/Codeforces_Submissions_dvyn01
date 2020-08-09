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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    ll a[n];
    f(0, n) cin >> a[i];
    pl ans[n];
    ll mx = -1;
    ans[1].first = a[0], ans[1].second = a[1];
    mx = max(a[0], a[1]);
    f(2, n)
    {
        ans[i].first = mx, ans[i].second = a[i];
        mx = max(mx, a[i]);
    }
    ans[n].first = mx, ans[n].second = min(a[0], a[1]);
    sort(a, a + n);
    while (q--)
    {
        ll m;
        cin >> m;
        if (m < n)
            cout << ans[m].first << " " << ans[m].second << "\n";
        else
        {
            cout << mx << " ";
            m -= n;
            m %= n - 1;
            // cout<<m+1<<" ";
            cout << min(ans[m + 1].first, ans[m + 1].second) << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}