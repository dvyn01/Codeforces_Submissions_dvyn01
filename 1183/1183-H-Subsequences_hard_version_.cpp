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

ll dp1[105][105], dp2[105][105], dp3[105];

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
    string s;
    cin >> s;
    f(1, n + 1)
    {
        bool b[26];
        memset(b, false, sizeof(b));
        fi(0, n - i + 1)
        {
            if (i == 1)
            {
                dp1[j][i] = 1;
                if (!b[s[j] - 'a'])
                    dp2[j][i] = 1;
                b[s[j] - 'a'] = true;
            }
            else
            {
                bool c[26];
                memset(c, false, sizeof(c));
                fii(j + 1, n - i + 2)
                {
                    if (c[s[k] - 'a'])
                        continue;
                    c[s[k] - 'a'] = true;
                    dp1[j][i] += dp1[k][i - 1];
                }
                if (!b[s[j] - 'a'])
                    dp2[j][i] = dp1[j][i];
                b[s[j] - 'a'] = true;
            }
            // cout << j << " " << i << " " << dp1[j][i] << " " << dp2[j][i] << "\n";
        }
    }
    f(1, n + 1)
        fi(0, n) dp3[i] += dp2[j][i];
    dp3[0] = 1;
    ll ans = 0, i = n;
    while (k > 0)
    {
        if(i < 0)
        {
            cout<<-1;
            return 0;
        }
        if (dp3[i] >= k)
        {
            ans += (n - i) * k;
            break;
        }
        else
            ans += (n - i) * dp3[i], k -= dp3[i];
        i--;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}