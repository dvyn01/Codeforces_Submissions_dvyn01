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
ll xh1=-1e18, xl1=1e18, yh1=-1e18, yl1=1e18, xh2=-1e18, xl2=1e18, yh2=-1e18, yl2=1e18;

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    map<ll,map<ll,ll>> m;
    f(0, 4)
    {
        ll a, b;
        cin>>a>>b;
        xh1 = max(xh1, a);
        xl1 = min(xl1, a);
        yh1 = max(yh1, b);
        yl1 = min(yl1, b);
    }
    f(0,4)
    {
        ll a, b;
        cin>>a>>b;
        xh2 = max(xh2, a);
        xl2 = min(xl2, a);
        yh2 = max(yh2, b);
        yl2 = min(yl2, b);
    }
    f(xl1, xh1+1)
    {
        for(ll j=yl1; j<=yh1; j++)
            { m[i][j]++; }
    }
    ll p = (yh2+yl2)/2;
    ll q = (xh2+xl2)/2;
    ll k=0;
 //  if(xl2>xh1 || yl2>yh1 || xh2<xl1 || yh2<yh1)
   // {
     //   cout<<"NO";
       // return 0;
    //}
    f(xl2, q+1)
    {
        for(ll j=0; j<=k; j++)
        {
            if(m[i][p+j]){ cout<<"YES"; return 0;}
                m[i][p+j]++;
            if(j != 0)
             {if(m[i][p-j]){ cout<<"YES"; return 0;}
                m[i][p-j]++;
             }
        }
        k++;
    }
    k=0;
    for(ll i=xh2; i>q; i--)
    {
        for(ll j=0;j<=k; j++)
        {
             if(m[i][p+j]){cout<<"YES"; return 0;}
                m[i][p+j]++;
            if(j!=0){
             if(m[i][p-j]){cout<<"YES"; return 0;}
                m[i][p-j]++;
            }
        }
        k++;
    }
    cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

