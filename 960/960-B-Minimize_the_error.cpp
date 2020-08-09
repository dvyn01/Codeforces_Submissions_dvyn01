//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  //  cout.tie(0);
    ll n,x,y;
    cin>>n>>x>>y;
    x += y;
    ll a[n], b[n], d[n];
    f(0,n) cin>>a[i];
    f(0,n){
        cin>>b[i];
        d[i] = abs(a[i] - b[i]);
    }
    f(0,x)
    {
        ll m=-1e18, p=0;
        for(ll j=0; j<n; j++)
        {
            if(d[j] >= m)
            {
                m = d[j];
                p = j;
            }
        }
        //cout<<p<<"*"<<d[p]<<" ";
        d[p] = abs(d[p]-1);
    }
    ll s=0;
    f(0,n)
    {
        s += d[i]*d[i];
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

