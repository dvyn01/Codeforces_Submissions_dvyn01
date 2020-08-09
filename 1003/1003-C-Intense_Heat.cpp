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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, k;
    cin>>n>>k;
    ld a[n+1];
    ld ans = 0;
    f(1,n+1) cin>>a[i];
    ld s[n+1];
    s[0] = 0;
    f(1,n+1)
    {
        s[i] = a[i]+s[i-1];
    }
    f(1,n+1)
    {
        if(i+k > n+1)
            break;
        fi(i+k-1, n+1)
        {
            ld p = s[j] - s[i-1];
            p = p/(j-i+1) * 1.0;
            if(p > ans)
                ans = p;
        }
    }
    cout<<std::fixed<<setprecision(15)<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

