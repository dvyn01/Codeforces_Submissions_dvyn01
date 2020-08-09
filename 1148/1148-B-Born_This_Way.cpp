/*
    * AUTHOR : Divyanshu *
*/

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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    ll a[n], b[m];
    f(0, n) cin >> a[i], a[i] += ta;
    f(0, m) cin >> b[i];
    if (n <= k || m <= k)
    {
        cout << -1;
        return 0;
    }
    sort(a, a + n);
    sort(b, b + m);
    ll cp = 0;
    if (lower_bound(b, b + m, a[k]) - b == m)
    {
        cout << -1;
        return 0;
    }
    if (a[0] > b[m - 1 - k])
    {
        cout << -1;
        return 0;
    }
    // while (k-- && cp < n)
    // {
    //     if (cp == n - 1)
    //     {
    //         ll k1 = lower_bound(b, b + m, a[cp]) - b;
    //         if (m - k1 <= k + 1)
    //         {
    //             cout << -1;
    //             return 0;
    //         }
    //         k1 += k + 1;
    //         cout << b[k1] + tb;
    //         return 0;
    //     }
    //     else
    //     {
    //         ll k1 = lower_bound(b, b + m, a[cp]) - b;
    //         ll k2 = lower_bound(b, b + m, a[cp + 1]) - b;
    //         cout<<cp<<" "<<k<<" "<<k1<<" "<<k2<<"\n";
    //         if (k1 == k2)
    //         {
    //             k++;
    //             if (k1 == m)
    //             {
    //                 cout << -1;
    //                 return 0;
    //             }
    //         }
    //     }
    //     cp++;
    // }
    // ll k1 = lower_bound(b, b + m, a[cp]) - b;
    // if (k1 == m)
    //     cout << -1;
    // else
    //     cout << b[k1] + tb;
    // ll p1 = 0, p2 = 0, c = 0;
    // while (p2 < m && b[p2] < a[p1])
    //     p2++;
    // while (k-- && p1 < n && p2 < m)
    // {
    //     while (p2 < m && b[p2] < a[p1])
    //         p2++;
    //     cout<<p1<<" "<<p2<<" "<<k<<" "<<c<<"\n";
    //     if (p2 == m)
    //     {
    //         cout << -1;
    //         return 0;
    //     }
    //     if (p1 != n - 1 && b[p2] >= a[p1] && b[p2] >= a[p1 + 1])
    //     {
    //         p1++;
    //         k++;
    //         c++;
    //     }
    //     else if (p1 == n - 1)
    //     {
    //         if (m - p2 <= k + 1)
    //         {
    //             cout << -1;
    //             return 0;
    //         }
    //         p2 += k + 1;
    //         cout << b[p2] + tb;
    //         return 0;
    //     }
    //     else if (p1 != n - 1 && b[p2] >= a[p1] && b[p2] < a[p1 + 1])
    //     {

    //     }
    //     cout<<p1<<" "<<p2<<" "<<k<<"\n";
    // }
    // while (p2 < m && b[p2] < a[p1])
    //     p2++;
    // if(k < 0)
    //     k = 0;
    // cout<<p1<<" "<<p2<<" "<<k<<"\n";
    // if (p2 == m)
    // {
    //     cout << -1;
    //     return 0;
    // }
    // if (p2 + k >= m)
    //     cout << -1;
    // else
    //     cout << b[p2 + k] + tb;
    ll ans = 0;
    f(0, m)
    {
        if(i > k)
            break;
        ll k1 = lower_bound(b, b + m, a[i]) - b;
        k1 += k - i;
        if(k1 >= m)
        {
            cout<<-1;
            return 0;
        }
        ans = max(ans, b[k1] + tb);
    }
    cout<<ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}