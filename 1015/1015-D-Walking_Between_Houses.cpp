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

    ll n, k, s;
    cin>>n>>k>>s;
    if((n-1)*k < s || k>s)
    {
        cout<<"NO";
        return 0;
    }
    ll cp=1;
    cout<<"YES\n";
    while(k)
    {
        if(k == s)
            break;
        if(k==1)
        {
            ll p=cp+s, q=cp-s;
            if(p<=n){cout<<p<<" ";}
            else cout<<q<<" ";
            k--;
            break;
        }
        ll p = min(s-k+1, n-1);
        if(cp==1)   {    cp=cp+p; s-=p; k--; }
        else if(cp==n){    s-=p; cp = cp-p; k--;}
      //  cout<<cp<<" "<<s<<" "<<k<<" "<<p<<"\n";
        cout<<cp<<" ";
    }
    if(k)
    {
        if(cp > 1)
        {
            cp--;
            ll c=0;
            while(k)
            {
                cout<<cp<<" ";
                if(c%2) cp--;
                else cp++;
                k--;
                c++;
            }
        }
        else
        {
            cp++;
            ll c=0;
            while(k)
            {
                cout<<cp<<" ";
                if(c%2) cp++;
                else cp--;
                c++;
                k--;
            }
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

