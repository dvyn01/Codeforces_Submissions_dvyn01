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

    ll n, k;
    cin >> n >> k;
    if (k < n * (n + 1) / 2)
    {
        cout << -1;
        return 0;
    }
    vll v1, v2;
    v1.pb(0);
    v2.pb(0);
    f(1, n + 1) v1.pb(i), v2.pb(i);
    k -= n * (n + 1) / 2;
    ll lp = 1, rp = n;
    while (lp <= rp && k > 0)
    {
        ll diff = v2[rp] - v2[lp];
        // cout << lp << " " << rp << " " << diff << " " << k << "\n";
        if (diff <= k)
        {
            k -= diff;
            swap(v2[lp], v2[rp]);
            lp++;
            rp--;
        }
        else
        {
            while (lp <= rp)
            {
                if (v2[rp] - v2[lp] <= k)
                    break;
                rp--;
            }
            // cout<<lp<<" "<<rp<<" --- \n";
            if (rp >= lp)
            {
                swap(v2[lp], v2[rp]);
                break;
            }
        }
    }
    ll ans = 0;
    f(1, n + 1) ans += max(v1[i], v2[i]);
    cout << ans << "\n";
    f(1, n + 1) cout << v1[i] << " ";
    cout << "\n";
    f(1, n + 1) cout << v2[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}