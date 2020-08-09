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

    ll a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    ll k = a1 * (k1 - 1) + a2 * (k2 - 1);
    ll mn = -1, mx = -1;
    if (k >= n)
        mn = 0;
    else
    {
        k = n - k;
        mn = min(a1 + a2, k);
    }
    if (k1 <= k2)
    {
        ll k = n / k1;
        if (k >= a1)
        {
            n -= a1 * k1;
            mx = a1;
            mx += min(a2, n / k2);
        }
        else
            mx = n / k1;
    }
    else
    {
        ll k = n / k2;
        if (k >= a2)
        {
            n -= a2 * k2;
            mx = a2;
            mx += min(a1, n / k1);
        }
        else
            mx = n / k2;
    }
    cout << mn << " " << mx;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}