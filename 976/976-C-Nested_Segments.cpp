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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, a, b, f, s, pos=1;
    cin>>n;
    vector<pair<pair<ll,ll>, ll>> p;
    f(0,n)
    {
        cin>>a>>b;
        p.pb(mp(mp(a,b), i+1));
    }
    sort(p.begin(), p.end());
    f = p[0].first.first; s = p[0].first.second; pos = p[0].second;
    f(1,n)
    {
       if(p[i].first.first == f)
       {
           cout<<pos<<" "<<p[i].second;
           return 0;
       }
       else if(p[i].first.first>=f && p[i].first.second<=s)
       {
           cout<<p[i].second<<" "<<pos;
           return 0;
       }
       else
        {
            pos = p[i].second;
            f = p[i].first.first;
            s = p[i].first.second;
        }
    }
    cout<<"-1 -1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

