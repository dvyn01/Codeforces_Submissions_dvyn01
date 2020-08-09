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

set<ll> s1[30], s2[30];
ll freq[30];
pll ans;

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
        string s, t;
        cin >> s >> t;
        f(0, 27) s1[i].clear(), s2[i].clear();
        memset(freq, 0, sizeof(freq));
        f(0, n) freq[s[i] - 'a']++, freq[t[i] - 'a']++;
        bool ok = true;
        ans.clear();
        f(0, 26)
        {
            if (freq[i] & 1)
            {
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;
        cout << "Yes\n";
        f(0, n) s1[s[i] - 'a'].insert(i), s2[t[i] - 'a'].insert(i);
        f(0, n)
        {
            if (s[i] != t[i])
            {
                ll k1 = s[i] - 'a', k2 = t[i] - 'a';
                if (s2[k2].size() > 1)
                {
                    ll x1 = *s2[k2].begin(), x2 = *(++s2[k2].begin());
                    // cout << k1 << " " << k2 << " " << x1 << " " << x2 << "\n";
                    ans.pb({x1, x2});
                    swap(s[x1], t[x2]);
                    s2[k2].erase(s2[k2].begin());
                    s2[k2].erase(s2[k2].begin());
                    s1[k1].erase(s1[k1].begin());
                    s2[k1].insert(x2);
                }
                else if (s1[k1].size() > 1)
                {
                    ll x1 = *s1[k1].begin(), x2 = *(++s1[k1].begin());
                    // cout<<k1<<" "<<k2<<" "<<x1<<" "<<x2<<" "<<s1[k1].size()<<" "<<s2[k2].size()<<"\n";
                    ans.pb({x2, x1});
                    swap(s[x2], t[x1]);
                    s1[k1].erase(s1[k1].begin());
                    s1[k1].erase(s1[k1].begin());
                    s2[k2].erase(s2[k2].begin());
                    s1[k2].insert(x2);
                }
                else
                {
                    ll x2 = *s2[k1].begin();
                    // cout<<x2<<" x2\n";
                    ll k3 = s[i + 1] - 'a';
                    swap(s[i + 1], t[x2]);
                    // cout<<s<<" "<<t<<"          s t\n";
                    ans.pb({i + 1, x2});
                    // cout<<k3<<" k3\n";
                    s1[k3].erase(s1[k3].begin());
                    s1[k1].insert(i + 1);
                    s2[k1].erase(s2[k1].begin());
                    s2[k3].insert(x2);
                    i--;
                }
            }
            else
            {
                ll k1 = s[i] - 'a', k2 = t[i] - 'a';
                s1[k1].erase(s1[k1].begin());
                s2[k2].erase(s2[k2].begin());
            }
            // fi(0, 3)
            // {
            //     cout<<j<<" -> ";
            //     for(auto it : s1[j])
            //         cout<<it<<" ";
            //     cout<<"\n";
            // }
            // fi(0, 3)
            // {
            //     cout<<j<<" -> ";
            //     for(auto it : s2[j])
            //         cout<<it<<" ";
            //     cout<<"\n";
            // }
            // cout<<"\n";
        }
        cout << ans.size() << "\n";
        f(0, ans.size()) cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}