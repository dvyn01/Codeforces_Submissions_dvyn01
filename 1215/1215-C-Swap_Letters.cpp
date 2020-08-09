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

    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll c = 0;
    f(0, n) if (s[i] == 'a') c++;
    f(0, n) if (t[i] == 'a') c++;
    if (c & 1)
    {
        cout << "-1";
        return 0;
    }
    vll ab, ba;
    f(0, n)
    {
        if (s[i] == 'a' && t[i] == 'b')
            ab.pb(i);
        else if (s[i] == 'b' && t[i] == 'a')
            ba.pb(i);
    }
    pll ans;
    while (ab.size() > 1)
    {
        ans.pb({ab[ab.size() - 1], ab[ab.size() - 2]});
        ab.pop_back();
        ab.pop_back();
    }
    while (ba.size() > 1)
    {
        ans.pb({ba[ba.size() - 1], ba[ba.size() - 2]});
        ba.pop_back();
        ba.pop_back();
    }
    if (ab.size() == 1 && ba.size() == 1)
    {
        ans.pb({ab[0], ab[0]});
        ans.pb({ab[0], ba[0]});
    }
    cout << ans.size() << "\n";
    f(0, ans.size()) cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}