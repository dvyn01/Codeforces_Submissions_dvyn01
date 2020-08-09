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
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    ll a[n];
    f(0, n) cin>>a[i];
    vll po, no;
    ll s=0;
    f(0, n)
    {
        if(a[i]>0 && a[i]%2) po.pb(a[i]);
        else if(a[i]<0 && abs(a[i])%2) no.pb(a[i]);
        else if(a[i]>0) s+=a[i];
    }
    sort(po.begin(), po.end());
    sort(no.begin(), no.end());
    if(po.size()==0){s+=no[no.size()-1]; cout<<s<<" "; return 0; }
    f(0, po.size()) s+=po[i];
    if(po.size()%2){cout<<s; return 0;}
    if(no.size()==0)
    {
        s-=po[0];
        cout<<s;
        return 0;
    }
    if(abs(po[0]) > abs(no[no.size()-1])) s+=no[no.size()-1];
    else s-=po[0];
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

