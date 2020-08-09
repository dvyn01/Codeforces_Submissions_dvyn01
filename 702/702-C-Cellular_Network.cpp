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

    ll n, m, s=0;
    cin>>n>>m;
    ll a[n], b[m];
    f(0, n) cin>>a[i];
    f(0, m) cin>>b[i];
    ll c=0;
    if(a[0] < b[0])
        s = abs(a[0]-b[0]);
    if(a[n-1] > b[m-1])
        s = max(s, abs(a[n-1]-b[m-1]));
    f(0,n)
    {
        if(b[c] <= a[i]){
        ll p = abs(b[c] - a[i]);
        while(c<m && b[c] <= a[i])
        {
            c++;
            p = min(p, abs(a[i] - b[c]));
        }
        if(c != m)
        p = min(p, abs(a[i]-b[c]));
        if(c==m) c--;
        s = max(s, p);
        }
        else{
            ll p = abs(b[c] - a[i]);
        while(c >=0 && b[c] >= a[i])
        {
            c--;
            p = min(p, abs(a[i] - b[c]));
        }
        if(c != 0 && c!=-1)
        p = min(p, abs(a[i]-b[c]));
        if(c==-1) c++;
        s = max(s, p);
        }
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

