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

vll fw[26], rv[26];
ll bf[100050], br[100050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    f(0, a.length()) fw[a[i] - 'a'].pb(i);
    fr(a.length() - 1, 0) rv[a[j] - 'a'].pb(a.length() - 1 - j);
    memset(bf, -1, sizeof(bf));
    memset(br, -1, sizeof(br));
    f(0, b.length())
    {
        ll x = bf[i];
        ll k = upper_bound(fw[b[i] - 'a'].begin(), fw[b[i] - 'a'].end(), x) - fw[b[i] - 'a'].begin();
        if (k == fw[b[i] - 'a'].size())
            break;
        bf[i + 1] = fw[b[i] - 'a'][k];
    }
    fr(b.length() - 1, 0)
    {
        ll x = br[j + 2];
        ll k = upper_bound(rv[b[j] - 'a'].begin(), rv[b[j] - 'a'].end(), x) - rv[b[j] - 'a'].begin();
        if (k == rv[b[j] - 'a'].size())
            break;
        br[j + 1] = rv[b[j] - 'a'][k];
    }
    f(1, b.length() + 1) if (br[i] != -1)
        br[i] = a.length() - br[i] - 1;
    // f(1, b.size() + 1)  cout<<bf[i]<<" ";   cout<<"\n";
    // f(1, b.size() + 1)  cout<<br[i]<<" ";   cout<<"\n";
    ll lp = 1, rp = 1, mn = 1e18, l = -1, r = -1;
    ll k1 = 0, k2 = 0;
    f(1, b.length() + 1)
    {
        if (bf[i] == -1)
            break;
        k1++;
    }
    fr(b.length(), 1)
    {
        if (br[j] == -1)
            break;
        k2++;
    }
    if(k1 == b.length() || k2 == b.length())
    {
        cout<<b;
        return 0;
    }
    while (lp <= b.length() && rp <= b.length())
    {
        if (bf[lp] == -1)
            break;
        while (rp <= b.length() && br[rp] < bf[lp])
            rp++;
        if (bf[lp] == br[rp] && lp != rp)
            rp++;
        // cout<<lp<<" "<<rp<<" "<<bf[lp]<<" "<<br[rp]<<"\n";
        if (rp > b.length())
            break;
        ll k = rp - lp;
        if (k < mn)
        {
            mn = k;
            l = lp - 1;
            r = rp - 1;
        }
        lp++;
    }
    // cout<<l<<" "<<r<<"\n";
    if(k1 != 0 && b.length() - k1 < mn)
        mn = b.length() - k1, l = k1 - 1, r = 1e18;
    if(k2 != 0 && b.length() - k2 < mn)
        mn = b.length() - k2, l = -1, r = b.length() - k2;
    if (l == -1 && r == -1)
    {
        cout << "-";
        return 0;
    }
    if(l == r)
        r++;
    // cout<<k1<<" "<<k2<<" "<<mn<<" "<<l<<" "<<r<<"\n";
    f(0, l + 1) cout << b[i];
    f(r, b.length()) cout << b[i];

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}