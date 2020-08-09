/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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

    ll n;
    cin>>n;
    ll a[n];
    unordered_map<ll,ll> m;
    f(0, n){
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a, a+n);
    if(m[a[0]] >= 3)
        cout<<m[a[0]]*(m[a[0]]-1)*(m[a[0]]-2)/6;
    else if(m[a[0]]==2)
        cout<<m[a[2]];
    else{
        if(m[a[1]] > 1)
            cout<<m[a[1]] * (m[a[1]]-1)/2;
        else cout<<m[a[2]];
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

