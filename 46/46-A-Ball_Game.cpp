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

    ll n, k=1, p=2;
    cin>>n;
    bool b[n+1] = {false};
    f(0,n-1){
        if(b[p])
        {
        cout<<p<<" ";
        p = p+k+1;
        k++;
        if(p%n==0)
            p = n;
        else p = p%n;
        continue;
        }
        b[p] = true;
        cout<<p<<" ";
        p = p+k+1;
        k++;
        if(p%n==0)
            p = n;
        else p = p%n;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

