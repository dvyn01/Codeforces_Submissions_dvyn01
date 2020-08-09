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

ll mn[1000050], mx[1000050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y = 1, ans = 0;
    cin >> n >> x;
    ll a[n];
    set<ll> s;
    f(1, x+5)   mn[i] = 1e18, mx[i] = -1;
    f(0, n)
        cin>>a[i];
    fr(n-1, 0)
    {
        if(!s.empty() && *s.begin() < a[j])
            mn[a[j]] = min(mn[a[j]], *s.begin());
        auto it = s.lower_bound(a[j]);
        if(it != s.begin())
            --it, mx[a[j]] = max(mx[a[j]], *it);
        s.insert(a[j]);
    }
    while(mn[y] == 1e18 && y < x)
        y++;
    fr(x-1, 1)    mn[j] = min(mn[j], mn[j+1]), mx[j] = max(mx[j], mx[j+1]);
    // f(1, x+2)   cout<<mn[i]<<" ";   cout<<"\n";
    ll lp = 1, rp = 1;
    while(lp <= y)
    {
        while(mn[rp+1] < lp || mx[rp+1] > rp)
            rp++;
        // cout<<lp<<" "<<rp<<"\n";
        ans += x - rp + 1;
        lp++;
        if(rp < lp)
            rp = lp;
    }
    cout<<ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}