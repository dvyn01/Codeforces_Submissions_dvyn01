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

    ll s, l;
    cin>>s>>l;
    pll p;
    f(1, l+1){
        p.pb(mp(i&(-i), i));
    }
    sort(p.begin(), p.end());
    ll m=0;
    vll ans;
    for(ll i=p.size()-1; i>=0; i--)
    {
        if(s-p[i].first >= 0)
        {
            s -= p[i].first;
            ans.pb(p[i].second);
            if(s==0)
                break;
        }
    }
    if(!s){
    cout<<ans.size()<<"\n";
    f(0, ans.size()) cout<<ans[i]<<" ";
    }
    else cout<<"-1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

