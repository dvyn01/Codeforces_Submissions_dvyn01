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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    ll a[n/2+1];
    f(1, n/2+1) cin>>a[i];
    ll p=1, q=2, sp=0, sq=0;
    sort(a+1,a+n/2+1);
    f(1,n/2+1)
    {
        sp += abs(a[i]-p);
        sq += abs(a[i]-q);
        //cout<<p<<" "<<q<<" "<<sp<<" "<<sq<<"\n";
        p = 2*(i)+1;
        q = 2*(i+1);
    }
    ll ans = min(sp,sq);
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

