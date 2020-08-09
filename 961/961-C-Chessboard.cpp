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
    ll a[4] = {0};
    for(ll k=0; k<4; k++)
    {
    f(0,n)
    {
        for(ll j=0; j<n; j++)
        {
            char c;
            cin>>c;
            if(i%2==j%2 && c=='1') a[k]++;
            else if(i%2!=j%2 && c=='0') a[k]++;
        }
    }
    }
    sort(a, a+4);
    ll ans = 2*n*n;
    ans = ans + a[0] + a[1] - a[2] - a[3];
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

