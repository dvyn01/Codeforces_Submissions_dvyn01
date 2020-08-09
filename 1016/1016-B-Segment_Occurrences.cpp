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
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, q;
    cin>>n>>m>>q;
    string s, t;
    cin>>s>>t;
    ll a[n+1] = {0};
    a[0] = 0;
    f(0, n-m+1)
    {
        if(i==0)
        {
            if(s.compare(0, m, t) == 0)
                a[1] =1;
            else a[1] = 0;
            continue;
        }
        if(s.compare(i, m, t) == 0)
            a[i+1] = a[i] + 1;
        else a[i+1] = a[i];
    }
    f(n-m+2, n+1) a[i] = a[i-1];
   // f(0, n+1) cout<<a[i]<<" ";
   // cout<<"\n";
    while(q--){
        ll l, r;
        cin>>l>>r;
        if(r-l+1 < m){cout<<"0\n"; continue;}
        cout<<a[r-m+1] - a[l-1]<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

