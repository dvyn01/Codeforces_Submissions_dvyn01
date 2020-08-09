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
#define print(x) cout << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

set<ll> s;
map<ll, ll> m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n];
    f(0, n) cin >> a[i];
    vll ans;
    bool ok = true;
    ans.pb(0);
    f(0, n)
    {
        if (a[i] > 0 && m.find(a[i]) == m.end())
        {
            m[a[i]] = 1;
            s.insert(a[i]);
        }
        else if (a[i] > 0 && m.find(a[i]) != m.end())
        {
            ok = false;
            break;
        }
        if (a[i] < 0)
        {
            if (m.find(abs(a[i])) == m.end())
            {
                ok = false;
                break;
            }
            if (s.find(abs(a[i])) == s.end())
            {
                ok = false;
                break;
            }
            s.erase(s.find(abs(a[i])));
        }
        if (s.empty())
        {
            ans.pb(i + 1);
            m.clear();
        }
        // cout << i << " " << s.size() << "\n";
    }
    if(!s.empty())
        ok = false;
    if (!ok)
        cout << -1;
    else
    {
        cout << ans.size() - 1 << "\n";
        f(1, ans.size()) cout << ans[i] - ans[i - 1] << " ";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}