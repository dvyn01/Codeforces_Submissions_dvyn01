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

ll p[1050];

void sieve()
{
    p[0] = true;
    p[1] = true;
    f(2, 1050) if (!p[i])
        fi(2 * i, 1050)
            p[j] = true,
            j += i - 1;
    p[2] = true;
}

// void breakk(ll n)
// {
//     if (!p[n])
//     {
//         v.pb(n);
//         return;
//     }
//     breakk(a[n]);
//     breakk(b[n]);
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool pos[1005];
    sieve();
    ll n;
    cin >> n;
    pll ans;
    f(1, n) ans.pb({i, i + 1});
    ans.pb({n, 1});
    ll cl = 1, cr = 3;
    while (p[ans.size()])
    {
        ans.pb({cl, cr});
        if (cl % 2 == 0)
        {
            cl += 3;
            cr += 3;
        }
        else
        {
            cl++;
            cr++;
        }
    }
    cout << ans.size() << "\n";
    f(0, ans.size()) cout << ans[i].first << " " << ans[i].second << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}