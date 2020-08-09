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

    ll n, k=0;
    cin>>n;
    ll s = n*(n+1)/2;
    s /= 2;
    vll a, b;
    for(ll i=n; i>0; i--)
    {
        if(s - i >= 0)
        {
            a.pb(i);
            s -= i;
            k += i;
        }
        else b.pb(i);
    }
    cout<<abs((n+1)*n/2-2*k)<<"\n";
    cout<<a.size()<<" ";
    f(0, a.size()) cout<<a[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

