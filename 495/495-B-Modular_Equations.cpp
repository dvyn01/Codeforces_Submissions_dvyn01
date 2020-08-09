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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll a, b;
    cin>>a>>b;
    if(b>a){cout<<"0"; return 0; }
    if(a==b)
    {
        cout<<"infinity";
        return 0;
    }
    ll c = b+1, s=0, d=a-b;
    if(c > d){
        cout<<"0";
        return 0;
    }
    for(ll i=1; i*i<=d; i++)
    {
        if(d%i == 0)
          {
             if(i>b) s++;
             if(d/i>b && i*i!=d) s++;
          }
    }
    cout<<s;
     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
