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

ll bs(ll l, ll r, ll a[], ll x)
{
    ll mid = (l+r)/2;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            l = mid+1;
        else if(a[mid] > x)
            r = mid-1;
    }
    return mid;
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m;
    cin>>n>>m;
    ll a[n], b[n];
    f(0, n)
    {
        cin>>a[i];
        if(i==0) b[i] = a[i];
        else b[i] = b[i-1]+a[i];
    }
    f(0,m)
    {
        ll x, y;
        cin>>x;
        if(x <= b[0])
        {
            cout<<"1 "<<x<<"\n";
            continue;
        }
        ll r = bs(0, n-1, b, x);
        if(b[r] > x)
        {
            y = abs(x - b[r-1]);
            r += 1;
        }
        else if(b[r] < x)
        {
               y = abs(x-b[r]);
               r += 2;
        }
        else { y = abs(b[r-1]-x); r += 1;}
        cout<<r<<" "<<y<<"\n";

    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

