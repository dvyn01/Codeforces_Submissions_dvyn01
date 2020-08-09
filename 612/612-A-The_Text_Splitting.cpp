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

    ll n, p, q, a=0, b=0, c=0;
    string s;
    cin>>n>>p>>q>>s;
    f(0, 101)
    {
        for(ll j=0; j<101; j++)
            if(i*p + j*q == n)
        {
            a=i;
            b=j;
            break;
        }
    }
    if(a==0 && b==0)
    {
        cout<<"-1";
        return 0;
    }
    cout<<a+b<<"\n";
    if(a!=0){
    f(0, p*a)
    {
        if((i+1)%p == 0)
        cout<<s[i]<<"\n";
        else cout<<s[i];
    }
    }
    if(b!=0){
          f(0, n-(p*a))
          {
          if((i+1)%q == 0)
            cout<<s[i+p*a]<<"\n";
            else cout<<s[i+p*a];
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
