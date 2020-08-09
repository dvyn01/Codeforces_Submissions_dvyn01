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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, a, b, s=0, c=0;
    cin>>n>>a>>b;
    ll ar[n];
    f(0,n) {
        cin>>ar[i];
        s += ar[i];
    }
    ll x=ar[0], cc=0;
    ll p = ar[0]*a/b;
    sort(ar, ar+n);
    if(s <= p)
    {
        cout<<"0\n";
        return 0;
    }
    for(ll j=n-1; j>=0; j--)
    {
        if(ar[j]==x && cc==0)
        {
            cc++;
            continue;
        }
        s -= ar[j];
        c++;
        if(s <= p)
        {
            cout<<c;
            return 0;
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

