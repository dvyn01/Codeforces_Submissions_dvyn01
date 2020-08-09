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

    ll n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    vll a, b;
    f(0, s.length())
    {
        if (s[i] == 'A')
            a.pb(i);
        else
            b.pb(i);
    }
    f(0, s.length() - 1)
    {
        if (s[i] != s[i + 1])
        {
            if (s[i] == 'A')
            {
                ll k = upper_bound(a.begin(), a.end(), i) - a.begin();
                if (k == a.size())
                    continue;
                ans += n - a[k];
            }
            else
            {
                ll k = upper_bound(b.begin(), b.end(), i) - b.begin();
                if (k == b.size())
                    continue;
                ans += n - b[k];
            }
        }
        else
        {
            if (s[i] == 'A')
            {
                ll k = lower_bound(b.begin(), b.end(), i) - b.begin();
                if (k == b.size())
                    ans += n - i - 1;
                else
                    ans += n - i - 2;
            }
            else
            {
                ll k = lower_bound(a.begin(), a.end(), i) - a.begin();
                if (k == a.size())
                    ans += n - i - 1;
                else
                    ans += n - i - 2;
            }
        }
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}