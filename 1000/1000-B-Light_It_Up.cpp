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

ll a[200000], b[200000][2];

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
    a[0] = 0;
    f(1,n+1)
        cin>>a[i];
    ll c=0;
    a[n+1] = m;
    if(n%2==0){
        b[n][1] = 0;
        b[n][0] = a[n+1]-a[n];
    }
    else{
        b[n][0] = 0;
        b[n][1] = a[n+1]-a[n];
        c=1;
    }
        for(ll i=n-1; i>=0; i--)
        {
            if(c%2){
                ll p = a[i+1] - a[i];
                b[i][0]  = b[i+1][0]+p;
                b[i][1] = b[i+1][1];
            }
            else{
                ll p = a[i+1] - a[i];
                b[i][1]  = b[i+1][1]+p;
                b[i][0] = b[i+1][0];
            }
            c++;
        }
      //  f(0, n+1) cout<<b[i][0]<<" "<<b[i][1]<<"\n";
        c=0;
        ll s = 0;
        f(1, n+2)
            { if(i%2) s+=a[i] - a[i-1]; }
        ll ax=0, d=0;
      //  cout<<s<<"\n";
        f(0, n+1){
            if(a[i+1]-a[i]==1) { if(!(d%2)) ax += a[i+1]-a[i];
           d++; continue; }
           if(c%2){
            ll k=0;
            ll p = a[i+1] - 1;
            k += p - a[i];
            if(ax+b[i+1][1]+k > s) s = ax+b[i+1][1]+k;
           }
           else{
                ll k=0;
            ll p = a[i] + 1;
            k += a[i+1]-p;
            if(ax+b[i+1][1]+k > s) s = ax+b[i+1][1]+k;
           }
           c++;
           if(!(d%2)) ax += a[i+1]-a[i];
           d++;
         //  cout<<i<<" "<<s<<"\n"; 
        }
        cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
