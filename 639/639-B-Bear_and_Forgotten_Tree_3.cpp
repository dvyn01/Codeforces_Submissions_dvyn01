//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, d, h, c=0, nn=0;
    vll v;
    cin>>n>>d>>h;
    if(d/2>h || d<h || 2*h<d || (h==1&&d>2) || (n>2&&h==1&&d==1)){
        cout<<"-1";
        return 0;
    }
    pll ans;
    if(d==2&&h==1){
        f(2,n+1) cout<<"1 "<<i<<"\n";
        return 0;
    }
    f(0,h)
    {
        ans.pb(mp(i+1, i+2));
        c++;
        nn = i+2;
    }
    if(c-1 < d)
    {
        ll p = d-c, q=1;
        f(0, p)
        {
            ans.pb(mp(q, nn+1));
            c++;
            q=nn+1;
            nn++;
        }
        p = n-nn;
        f(0, p) ans.pb(mp(2, ++nn));
    }
    f(0, ans.size()) cout<<ans[i].first<<" "<<ans[i].second<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

