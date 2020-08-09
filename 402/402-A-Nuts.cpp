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

    ll k, a, b, v, c=0;
    cin>>k>>a>>b>>v;
    while(a)
    {
        if(b>=k-1)
        {
            c++;
            b -= k-1;
            ll p = v*k;
            a -= p;
            if(a<0) a=0;
        }
        else if(b<k-1 && a>0 && b!=0)
        {
            ll p = (b+1)*v;
            a -= p;
            if(a<0) a=0;
            b=0;
            c++;
        }
        if(b==0 && a>0)
        {
            ll p = a/v;
            if(a%v != 0)
                p++;
            c += p;
            a=0;
        }
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

