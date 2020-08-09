/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>

      using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, a, cf, cm, m;
    cin>>n>>a>>cf>>cm>>m;
    pll p;
    f(1, n+1)     cin>>x,     p.pb({x, i});
    p.pb({0, 0});
    sort(p.begin(), p.end());
    ll f[100050];
    f(1, n+1)     f[i] = f[i - 1] + p[i].first;
    ll cr = n, cl = n, ans = 0, mrc = 0, mlc = 0, mlv = 0;
    while(cr >= 0)
    {
        ll k = f[n] - f[cr], x = (n - cr) * a;
        k = x - k;
        if(k > m)
            break;
        k = m - k;
    //    cout<<k<<" ";
        cl = min(cl, cr);
        while(cl > 1 && (cl - 1) * p[cl].first - f[cl - 1] > k)
            cl--;
        ll l = p[cl].first, r = a, no = cl, ans1 = p[cl].first;
        while(l <= r)
        {
            ll mid = l + r >> 1;
            if(cl * mid - f[cl] <= k)
                ans1 = mid,   l = mid + 1;
            else
                r = mid - 1;
        }
        ll v;
        if(ans1 == a) v = ans1 * cm + cf * (cl + n - cr);
        else v = ans1 * cm + cf * (n - cr);
    //    cout<<cr<<" "<<cl<<" "<<ans1<<" "<<v<<"\n";
        if(v > ans)
        {
            ans = v;
            mrc = n - cr;
            mlc = cl;
            mlv = ans1;
        }
        cr--;
    }
    cout<<ans<<"\n";
    ll kill[n+1];   memset(kill, 0, sizeof(kill));
    f(1, n+1)
    {
        if(i <= mlc)
        {
            kill[p[i].second] = mlv;
            continue;
        }
        if(n - i + 1 <= mrc)
        {
            kill[p[i].second] = a;
            continue;
        }
        kill[p[i].second] = p[i].first;
    }
    f(1, n+1)   cout<<kill[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

