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


ll bs(ll a[], ll l, ll r, ll x)
{
    ll mid = (l+r)/2;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid] == x)
            return mid;
        if(a[mid] < x)
            l = mid+1;
        else r = mid-1;
    }
    return mid;
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, q, ss=0, k;
    cin>>n>>q;
    ll a[n], s[n],p=0;
    f(0,n) {
        cin>>a[i];
        p += a[i];
        s[i] = p;
    }
    while(q--)
    {
        cin>>k;
        ss += k;
        if(ss >= s[n-1])
        {
            cout<<n<<"\n";
            ss = 0;
            continue;
        }
        ll q = bs(s,0,n-1,ss);
       // cout<<q<<"q "<<ss<<"ss ";
        if(s[q] == ss)
            cout<<n-(q+1)<<"\n";
        else if(s[q] < ss)
            cout<<n-(q+1)<<"\n";
        else if(s[q] > ss)
            cout<<n-q<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
