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

    ll n, k=0;
    cin>>n;
    string s;
    cin>>s;
    f(0,n/2)
    {
        ll j=i+1, x=0;
        for(ll p=0; p<=i; p++)
        {
            if(s[p] != s[j])
            {
                x++;
                break;
            }
            j++;
        }
        if(x==0){
            k = i+1;
        }
    }
    if(k==0) cout<<n;
    else cout<<n-k+1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
