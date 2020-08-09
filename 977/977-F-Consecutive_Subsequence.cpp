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

    ll n;
    cin>>n;
    ll a[n+1], mx=0;
    vll ans;
    f(1,n+1) cin>>a[i];
    ll b[n+1] = {0};
    map<ll,ll> m;
    f(1, n+1)
    {
        if(m[a[i]-1])
        {
            b[i] = b[m[a[i]-1]] + 1;
            m[a[i]] = i;
        }
        else {
                m[a[i]] = i;
            b[i] = 1;
        }
    }
    ll pos=-1, val=0;
    f(1, n+1){
        if(b[i] >= mx) { mx = b[i]; pos = i; val=a[i];}
   //     cout<<b[i]<<" ";
    }
    cout<<mx<<"\n";
    for(ll j=pos; j>0; j--)
    {
        if(a[j] == val)
        {
            ans.pb(j);
            val--;
        }
    }

    for(ll i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

