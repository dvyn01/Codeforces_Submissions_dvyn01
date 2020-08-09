//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define pll vector<pair<ll,ll>>
#define mp make_pair
#define pb push_back
#define vll vector<ll>

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);


    ll n, k;
    cin>>n>>k;
    ll b[n] ={0}, a[n], c[n];
    map<ll,ll> m, mm;
    f(0, n){
     cin>>a[i];
     c[i] = a[i];
    }
    f(0,k)
    {
        ll x, y;
        cin>>x>>y;
        if(a[x-1] > a[y-1])
            m[x-1]++;
        else if(a[y-1] > a[x-1])
            m[y-1]++;
    }
    sort(a, a+n);
    mm[a[0]] = 0;
    ll x=1, y=1;
    while(a[x] == a[0]) {x++; y++; }
    f(x, n)
    {
        mm[a[i]] = y;
        ll j = i+1;
        while(a[j] == a[i])
            { j++; y++; }
        y++;
        i = j-1;
    }
    f(0,n)
    {
        ll x = m[i];
        cout<<mm[c[i]]-x<<" ";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
