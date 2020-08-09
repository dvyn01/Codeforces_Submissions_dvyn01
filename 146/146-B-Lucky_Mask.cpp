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

ll mask(ll n)
{
    ll s=0, j=1;
    while(n)
    {
        ll p = n%10;
        n /= 10;
        if(p==4 || p==7)
            {
                s = p*j+s;
                j *= 10;
            }
    }
    return s;
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

    ll a, b;
    cin>>a>>b;
    if(b>a)
    {
        cout<<b;
        return 0;
    }
    f(a+1, 1000000)
    {
        if(mask(i)==b)
        {
            cout<<i;
            return 0;
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

