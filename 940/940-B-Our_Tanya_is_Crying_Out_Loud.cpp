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

    ll s=0, n, k, a, b;
    cin>>n>>k>>a>>b;
    if(k==1)
    {
        s += (n-1)*a;
        cout<<s;
        return 0;
    }
    while(n!=1)
    {
        if(n%k==0)
        {
            ll p = n-n/k;
            p = min(b, p*a);
            s += p;
            n /= k;
        }
        else{
            if(n<k)
            {
                s += (n-1)*a;
                n=1;
                continue;
            }
            ll q = n%k;
            s += a*q;
            n -= q;
        }
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

