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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll mn[n + 5];
        f(0, n + 5) mn[i] = 10;
        fr(n - 1, 0)
        {
            mn[j] = mn[j + 1];
            if (s[j] - '0' < mn[j])
                mn[j] = s[j] - '0';
        }
        string ans;
        f(0, n) ans += '0';
        ll mx = 10;
        f(0, n)
        {
            ll k = s[i] - '0';
            if (mn[i] < k)
                ans[i] = '2';
            else
            {
                if (mx < s[i] - '0')
                    ans[i] = '2';
                else
                    ans[i] = '1';
            }
            if (ans[i] == '2' && s[i] - '0' < mx)
                mx = s[i] - '0';
        }
        string z = "";
        f(0, n) if (ans[i] == '1') z += s[i];
        f(0, n) if (ans[i] == '2') z += s[i];
        bool ok = true;
        mx = -1;
        f(0, n)
        {
            if (mx > z[i] - '0')
            {
                ok = false;
                break;
            }
            if (z[i] - '0' > mx)
                mx = z[i] - '0';
        }
        // cout<<ans<<" ";
        if (ok)
            cout << ans << "\n";
        else
            cout << "-\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}