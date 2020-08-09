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
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, b;
    cin>>n>>b;
    ll a[n];
    f(0,n)  cin>>a[i];
    ll c=0, j=0;
    vll v;
    f(0,n)
    {
        if(a[i]%2) c++;
        else c--;
        if(c==0)
            { v.pb(abs(a[i]-a[i+1])); j=i; }
    }
    c=0;
    f(j+1, n)
    {
        if(a[i]%2) c++;
        else c--;
    }
    if(c != 0)
    {
        cout<<"0";
        return 0;
    }
    sort(v.begin(), v.end());
    c=0;    ll s=0;
    f(0, v.size())
    {
        s += v[i];
        if(s <= b)
            c++;
        else break;
    }
    cout<<c;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

