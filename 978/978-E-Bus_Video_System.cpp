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

    int n, w, max=0, min=1e18,k,s=0;
    cin>>n>>w;
    f(0,n)
    {
        cin>>k;
        s += k;
        if(s > max)
            max = s;
        if(s < min)
            min = s;
    }
    if(min < -1*w || max > w)
    {
        cout<<"0\n";
        return 0;
    }
    if(min<0)
        min *= -1;
    else min = 0;
    max = w-max;
    if(min > max)
    {
        cout<<"0\n";
        return 0;
    }
    ll ans = abs(max-min)+1;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

